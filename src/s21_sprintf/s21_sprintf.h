#include "../s21_string.h"

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

  // Exists solely for handeling when wchar_t is not in ASCII
  // Immediately exits s21_printf and returns -1
  bool is_error;
  // The current implementation requires this two bools.
  // Otherwise, NaN or infinity values will vanish after converting to long
  // double in the handle_float(Fmt *fmt) function. Although the program may
  // work, Valgrind will hang.
  bool is_nan;
  bool is_inf;
} Fmt;

int parse_int(const char **p);
void reset_fmt(Fmt *fmt);
void invert_str(Fmt *fmt);

void insert_number(Fmt *fmt);
void insert_string(Fmt *fmt, char *string);
void insert_wstring(Fmt *fmt, wchar_t *string);
void insert_character(Fmt *fmt, char ch);
void insert_wcharacter(Fmt *fmt, wchar_t ch);

void handle_integer(Fmt *fmt);
void handle_octal(Fmt *fmt);
void handle_string(Fmt *fmt);
void handle_character(Fmt *fmt);
void handle_unsigned_integer(Fmt *fmt);
void handle_hexadecimal(Fmt *fmt);
void handle_pointer(Fmt *fmt);
void handle_return_count(Fmt *fmt, char *str);

void handle_float(Fmt *fmt);

void float_to_str(long double number, Fmt *fmt);
void convert_int_part(long double number, Fmt *fmt);
void convert_fractional_part(long double number, Fmt *fmt);
void round_(Fmt *fmt);
void insert_exp(int exponent, Fmt *fmt);
void remove_trailing_zeros(Fmt *fmt);
long double round_to_precision(long double value, int precision);

//
// Converters
//

// The if (!(number == 0 && fmt->is_precision_specified && fmt->precision == 0))
// is necessary when the user specifies a precision of 0 and the number is 0.
// In this case, we output no number, as per the sprintf documentation.

// Macro to convert an integer to a string
// Note: After conversion number is inverted
#define int_to_str(number, fmt)                                               \
  if (!(number == 0 && fmt->is_precision_specified && fmt->precision == 0)) { \
    fmt->is_negative = number < 0;                                            \
                                                                              \
    if (fmt->is_negative) {                                                   \
      int mod = number % 10;                                                  \
      mod = -mod;                                                             \
      *fmt->number.string_end++ = mod + '0';                                  \
                                                                              \
      number /= 10;                                                           \
      number = -number;                                                       \
                                                                              \
      while (number > 0) {                                                    \
        *fmt->number.string_end++ = (number % 10) + '0';                      \
        number /= 10;                                                         \
      }                                                                       \
    } else {                                                                  \
      do {                                                                    \
        *fmt->number.string_end++ = (number % 10) + '0';                      \
        number /= 10;                                                         \
      } while (number > 0);                                                   \
    }                                                                         \
  }

// Macro to convert an unsigned integer to a string
#define unsigned_int_to_str(number, fmt)                                      \
  if (!(number == 0 && fmt->is_precision_specified && fmt->precision == 0)) { \
    do {                                                                      \
      *fmt->number.string_end++ = (number % 10) + '0';                        \
      number /= 10;                                                           \
    } while (number > 0);                                                     \
  }

// Macro to convert a hexadecimal number to a string
#define hexadecimal_to_str(hex, hex_case, fmt)                             \
  if (!(hex == 0 && fmt->is_precision_specified && fmt->precision == 0)) { \
    if (hex == 0)                                                          \
      fmt->flag_base = false; /* Make insert_number not output  0x */      \
    do {                                                                   \
      if ((hex % 16) < 10) {                                               \
        *fmt->number.string_end++ = '0' + (hex % 16);                      \
      } else {                                                             \
        *fmt->number.string_end++ = hex_case + ((hex % 16) - 10);          \
      }                                                                    \
                                                                           \
      hex /= 16;                                                           \
    } while (hex > 0);                                                     \
  } else {                                                                 \
    fmt->flag_base = false; /* Make insert_number not output  0x */        \
  }

// Macro to convert an octal number to a string
#define octal_to_str(number, fmt)                                             \
  if (!(number == 0 && fmt->is_precision_specified && fmt->precision == 0)) { \
    if (number == 0)                                                          \
      fmt->flag_base = false; /* Make insert_number not output  0 */          \
    do {                                                                      \
      *fmt->number.string_end++ = '0' + (number % 8);                         \
      number /= 8;                                                            \
    } while (number > 0);                                                     \
  }
