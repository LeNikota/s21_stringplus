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
  bool is_precision_specified;

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

  // The pointer to current position in the formatted string
  // Provided buffer (char *str in s21_sprintf) to be written to
  char *str;

  // Used to determine sign in insert_spaces
  bool is_negative;

  // Contains converted to string number (number_buffer)
  struct Number {
    // 10000 because user may want precision of about 5000 and more
    char string[10000];
    char *string_end;
    bool completely_rounded;
    bool is_fractional_empty;
  } number;

} Fmt;

int parse_int(const char **p);
void reset_fmt(Fmt *fmt);
void invert_str(char *start, char *end);
void invert_str_temp(Fmt *fmt);

void insert_spaces(Fmt *fmt, char *buffer, char *p_buffer);
void insert_number(Fmt *fmt);

void insert_integer(Fmt *fmt);
void insert_octal(Fmt *fmt);
void insert_string(Fmt *fmt);
void insert_character(Fmt *fmt);
void insert_unsigned_integer(Fmt *fmt);
void insert_hexadecimal(Fmt *fmt);
void insert_pointer(Fmt *fmt);
void return_count(Fmt *fmt, char *str);

void handle_float(Fmt *fmt);

void float_to_str(long double number, Fmt *fmt);
void convert_int_part(long double number, Fmt *fmt);
void convert_fractional_part(long double number, Fmt *fmt);
void round_(Fmt *fmt);
void insert_exp(int exponent, Fmt *fmt);
void remove_trailing_zeros(Fmt *fmt);

// Macro to convert an integer to a string
// Note: After conversion number is inverted
#define int_to_str(number, fmt)                      \
  if (number < 0) {                                  \
    number = -number;                                \
    fmt->is_negative = 1;                            \
  }                                                  \
                                                     \
  do {                                               \
    *fmt->number.string_end++ = (number % 10) + '0'; \
    number /= 10;                                    \
  } while (number > 0);

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
