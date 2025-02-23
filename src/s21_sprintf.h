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
} Fmt;

const char *parse_int(const char *p, Fmt *fmt);
void reset_fmt(Fmt *fmt);
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

#define to_str(number, buffer)       \
  do {                               \
    *buffer++ = (number % 10) + '0'; \
    number /= 10;                    \
  } while (number > 0);              \
                                     \
  *buffer = '\0';

// Macro to convert an integer to a string
#define int_to_str(number, buffer, fmt) \
  bool is_negative = 0;                 \
                                        \
  if (number < 0) {                     \
    number = -number;                   \
    is_negative = 1;                    \
  }                                     \
                                        \
  to_str(number, buffer);               \
                                        \
  if (is_negative) {                    \
    *buffer++ = '-';                    \
  } else if (fmt->flag_plus) {          \
    *buffer++ = '+';                    \
  } else if (fmt->flag_space) {         \
    *buffer++ = ' ';                    \
  }

// Macro to convert a hexadecimal number to a string
#define hexadecimal_to_str(number, buffer, hex_case) \
  do {                                               \
    if ((number % 16) < 10) {                        \
      *buffer++ = '0' + (number % 16);               \
    } else {                                         \
      *buffer++ = hex_case + ((number % 16) - 10);   \
    }                                                \
                                                     \
    number /= 16;                                    \
  } while (number > 0);                              \
                                                     \
  *buffer = '\0';

// Macro to convert an octal number to a string
#define octal_to_str(number, buffer) \
  do {                               \
    *buffer++ = '0' + (number % 8);  \
    number /= 8;                     \
  } while (number > 0);              \
                                     \
  *buffer = '\0';

// Decimal to string
#define double_to_str(number, str, precision)                \
  char *start = str;                                         \
  bool is_negative = signbit(number);                        \
                                                             \
  if (is_negative) number = -number;                         \
                                                             \
  long double int_part = truncl(number);                     \
  long double fractional_part = fmodl(number, 1.0);          \
                                                             \
  if (int_part == 0.0) {                                     \
    *str++ = '0';                                            \
  } else {                                                   \
    while (int_part >= 1.0) {                                \
      *str++ = '0' + fmodl(int_part, 10.0);                  \
      int_part /= 10;                                        \
    }                                                        \
  }                                                          \
                                                             \
  if (is_negative) {                                         \
    *str++ = '-';                                            \
  } else if (fmt->flag_plus) {                               \
    *str++ = '+';                                            \
  } else if (fmt->flag_space) {                              \
    *str++ = ' ';                                            \
  }                                                          \
                                                             \
  int i = str - start;                                       \
  for (int j = 0; j < i / 2; j++) {                          \
    char temp = start[j];                                    \
    start[j] = start[i - j - 1];                             \
    start[i - j - 1] = temp;                                 \
  }                                                          \
                                                             \
  *str++ = '.';                                              \
                                                             \
  if (fractional_part > 1e-15) fractional_part += 0.0000005; \
                                                             \
  for (int i = 0; i < precision; i++) {                      \
    fractional_part *= 10.0;                                 \
    int digit = (int)fractional_part;                        \
    *str++ = digit + '0';                                    \
    fractional_part -= digit;                                \
  }                                                          \
                                                             \
  *str = '\0';
