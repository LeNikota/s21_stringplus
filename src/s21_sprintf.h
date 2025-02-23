#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

#include "s21_string.h"

// %[flags][width][.precision][length]specifier
typedef struct Fmt {
  // Flags that modify output format:
  // '-' : Left-justify is |text        |, default is |        text|
  // '+' : Forces to precede the result with a plus or minus sign (+ or -)
  // ' ' : Space before positive numbers
  // '#' : Used with o, x or X specifiers the value is preceded with 0, 0x or 0X
  // '0' : Left-pads the number with zeroes
  bool flag_minus;
  bool flag_plus;
  bool flag_space;
  bool flag_base;  // '#'
  bool flag_zero;
  bool flag_point;  // Activate precision

  // Minimum width of the output; padded if shorter.
  // number
  // *: additional integer value in argument
  int width;

  // Number of digits after decimal for floats; max chars for strings.
  // .number
  // .*: additional integer value in argument
  int precision;

  // Length modifier for data type:
  // 'h' : short int
  // 'l' : long
  // 'L' : long double
  char length[3];

  // Format specifier for data type:
  // 'c' : char
  // 'd' : signed int
  // 'i' : signed int (may be decimal, octal or hexadecimal)
  // 'e' : scientific notation using e character
  // 'E' : Scientific notation using E character
  // 'f' : float
  // 'g' : Uses the shortest representation of decimal floating point
  // 'G' : Uses the shortest representation of decimal floating point
  // 'o' : Unsigned octal
  // 's' : string
  // 'u' : unsigned int
  // 'x' : Unsigned hexadecimal integer
  // 'X' : Unsigned hexadecimal integer (capital letters)
  // 'p' : pointer address
  // 'n' : Number of characters printed until %n occurs
  // '%' : literal percent
  char specifier;

  // Variable argument list to hold the additional arguments
  va_list args;

  // The pointer to current position in the formatted string (str)
  char *str;

  // Used to determine sign in insert_spaces
  bool is_negative;
} Fmt;

const char *parse_int(const char *p, Fmt *fmt);
void reset_fmt(Fmt *fmt);
void invert_str(char *start, char *end);
void insert_spaces(Fmt *fmt, char *buffer, char *p_buffer);
void insert_integer(Fmt *fmt);
void insert_float(Fmt *fmt);
void insert_octal(Fmt *fmt);
void insert_string(Fmt *fmt);
void insert_character(Fmt *fmt);
void insert_unsigned_integer(Fmt *fmt);
void insert_hexadecimal(Fmt *fmt);
void insert_pointer(Fmt *fmt);
void return_count(Fmt *fmt, char *str);

// /*Rounding*/
// /*Even worse then upper one*/
// if (fractional_part * 10 >= 5) {
//   int digit = (*(buffer) - '0') + 10;
//   digit += 1;
//   *(buffer) = digit + '0';
// }

// Macro to convert an integer to a string
#define int_to_str(number, buffer, fmt) \
  char *start = buffer;                 \
                                        \
  if (number < 0) {                     \
    number = -number;                   \
    fmt->is_negative = 1;               \
  }                                     \
                                        \
  do {                                  \
    *buffer++ = (number % 10) + '0';    \
    number /= 10;                       \
  } while (number > 0);                 \
                                        \
  invert_str(start, buffer);

// Macro to convert an unsigned integer to a string
#define unsigned_int_to_str(number, buffer, fmt) \
  char *start = buffer;                          \
                                                 \
  do {                                           \
    *buffer++ = (number % 10) + '0';             \
    number /= 10;                                \
  } while (number > 0);                          \
                                                 \
  invert_str(start, buffer)

// Macro to convert a hexadecimal number to a string
#define hexadecimal_to_str(number, buffer, hex_case, fmt) \
  char *start = buffer;                                   \
                                                          \
  do {                                                    \
    if ((number % 16) < 10) {                             \
      *buffer++ = '0' + (number % 16);                    \
    } else {                                              \
      *buffer++ = hex_case + ((number % 16) - 10);        \
    }                                                     \
                                                          \
    number /= 16;                                         \
  } while (number > 0);                                   \
                                                          \
  /* 0x prefix */                                         \
  if (fmt->flag_base) {                                   \
    *buffer++ = hex_case + 23;                            \
    *buffer++ = '0';                                      \
  }                                                       \
                                                          \
  invert_str(start, buffer);

// Macro to convert an octal number to a string
#define octal_to_str(number, buffer, fmt) \
  char *start = buffer;                   \
                                          \
  do {                                    \
    *buffer++ = '0' + (number % 8);       \
    number /= 8;                          \
  } while (number > 0);                   \
                                          \
  /* 0 prefix*/                           \
  if (fmt->flag_base) *fmt->str++ = '0';  \
                                          \
  invert_str(start, buffer);

// Decimal to string
#define double_to_str(number, buffer, precision, fmt)        \
  char *start = buffer;                                      \
  bool is_negative = signbit(number);                        \
                                                             \
  if (is_negative) {                                         \
    number = -number;                                        \
    fmt->is_negative = 1;                                    \
  }                                                          \
                                                             \
  long double int_part = truncl(number);                     \
  long double fractional_part = fmodl(number, 1.0);          \
                                                             \
  if (fractional_part > 1e-15) fractional_part += 0.0000005; \
                                                             \
  /* Bad code, cuz inversion happens in insert_spaces*/      \
  for (int i = 0; i < precision; i++) {                      \
    fractional_part *= 10.0;                                 \
    int digit = (int)fractional_part;                        \
    *(buffer + precision - i - 1) = digit + '0';             \
    fractional_part -= digit;                                \
  }                                                          \
  buffer += precision;                                       \
                                                             \
  *buffer++ = '.';                                           \
                                                             \
  if (int_part == 0.0) {                                     \
    *buffer++ = '0';                                         \
  } else {                                                   \
    while (int_part >= 1.0) {                                \
      *buffer++ = '0' + fmodl(int_part, 10.0);               \
      int_part /= 10;                                        \
    }                                                        \
  }                                                          \
                                                             \
  invert_str(start, buffer);
