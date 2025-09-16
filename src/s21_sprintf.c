
#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  Fmt fmt = {0};
  fmt.str = str;

  va_start(fmt.args, format);

  for (const char *p = format; *p; p++) {
    if (*p == '%') {
      p++;
      reset_fmt(&fmt);

      // Handle flags
      while (s21_strchr("-+0 #", *p)) {
        switch (*p) {
          case '-':
            fmt.flag_minus = true;
            break;
          case '+':
            fmt.flag_plus = true;
            break;
          case '0':
            fmt.flag_zero = true;
            break;
          case ' ':
            fmt.flag_space = true;
            break;
          case '#':
            fmt.flag_base = true;
            break;
        }
        p++;
      }

      // Handle width
      if (*p == '*') {
        fmt.width = va_arg(fmt.args, int);
        p++;
      } else if (*p >= '0' && *p <= '9') {
        fmt.width = parse_int(&p);
      }

      // Handle precision
      if (*p == '.' && *(p + 1) == '*') {
        fmt.precision = va_arg(fmt.args, int);
        p += 2;
      } else if (*p == '.') {
        p++;
        fmt.precision = parse_int(&p);
      }

      // Handle length modifier
      if (*p == 'h' || *p == 'l' || *p == 'L') {
        fmt.length[0] = *p;
        fmt.length[1] = '\0';
        p++;
      }
      // long long int (ll[i|d]) or signed char (hh[i|d])
      if (*p == 'l' || *p == 'h') {
        fmt.length[1] = *p;
        fmt.length[2] = '\0';
        p++;
      }

      // Handle the format specifier
      fmt.specifier = *p;

      // Process the specifier
      switch (fmt.specifier) {
        case 'd':
        case 'i':
          insert_integer(&fmt);
          break;
        case 's':
          // wchar_t* IS NOT HANDLED
          insert_string(&fmt);
          break;
        case 'c':
          // wint_t IS NOT HANDLED
          insert_character(&fmt);
          break;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
          insert_float(&fmt);
          // implement e and E
          // implement g and G
          // implement f
          break;
        case 'o':
          insert_octal(&fmt);
          break;
        case 'u':
          insert_unsigned_integer(&fmt);
          break;
        case 'x':
        case 'X':
          insert_hexadecimal(&fmt);
          break;
        case 'p':
          insert_pointer(&fmt);
          break;
        case 'n':
          return_count(&fmt, str);
          break;
        case '%':
          *fmt.str++ = '%';
          break;
      }
    } else {
      *fmt.str++ = *p;
    }
  }

  *fmt.str = '\0';
  va_end(fmt.args);

  return fmt.str - str;
}

// --------------------
// ----- Utility -----
// --------------------

int parse_int(const char **p) {
  int number = 0;

  while (**p >= '0' && **p <= '9') {
    number = number * 10 + (**p - '0');
    *p += 1;
  }

  return number;
}

int convert_str_to_digit(char chr) { return 10 + (chr - '0'); }
char convert_digit_to_str(int chr) { return chr - '0'; }

void reset_fmt(Fmt *fmt) {
  fmt->flag_minus = false;
  fmt->flag_plus = false;
  fmt->flag_space = false;
  fmt->flag_base = false;
  fmt->flag_zero = false;
  fmt->flag_point = false;

  fmt->width = 0;
  fmt->precision = 6;

  s21_memset(fmt->length, 0, sizeof(fmt->length));
  fmt->specifier = 0;

  fmt->is_negative = 0;

  fmt->number.string_end = fmt->number.string;
  fmt->number.decimal_point = NULL;
}

void invert_str(char *start, char *end) {
  // cuz end is at the \0
  // it must not be moved to the start
  end--;

  for (; start < end; start++, end--) {
    char temp = *start;
    *start = *end;
    *end = temp;
  }
}

void invert_str_temp(Fmt *fmt) {
  char *start = fmt->number.string;
  char *end = fmt->number.string_end - 1;

  for (; start < end; start++, end--) {
    char temp = *start;
    *start = *end;
    *end = temp;
  }
}

// Convert a double to string
void float_to_str(long double number, Fmt *fmt) {
  if (signbit(number)) {
    number = -number;
    fmt->is_negative = 1;
  }

  convert_fractional_part(number, fmt);
  // *fmt->number.decimal_point = *fmt->number.string_end;
  *fmt->number.string_end++ = '.';
  convert_int_part(number, fmt);
  // round_(fmt);
}

void convert_int_part(long double number, Fmt *fmt) {
  long double int_part = truncl(number);

  if (int_part != 0.0) {
    while (int_part >= 1.0) {
      *fmt->number.string_end++ = '0' + fmodl(int_part, 10.0);
      int_part /= 10;
    }
  } else {
    *fmt->number.string_end++ = '0';
  }
}

void convert_fractional_part(long double number, Fmt *fmt) {
  long double fractional_part = fmodl(number, 1.0);

  if (fractional_part > 1e-15) fractional_part += 9e-13;

  for (int i = 0; i < fmt->precision; i++) {
    fractional_part *= 10.0;
    int digit = (int)fractional_part;
    *fmt->number.string_end++ = digit + '0';
    fractional_part -= digit;
  }

  // Inverts number
  // It has to be done because how insert_number works
  // It reads from right to left
  invert_str_temp(fmt);
}

void round_(Fmt *fmt) {
  (void)fmt;
  // int dot_remoteness = fmt->number.decimal_point - fmt->number.string;
  // if (fmt->precision > dot_remoteness) return;

  //   char *decimal = fmt->number.decimal_point;
  //   int precision = fmt->precision;
  //   char *rounding_start = decimal - precision + 1;

  //   char *start = rounding_start;
  //   char *end = fmt->number.string_end - 1;

  //   int previous_number = convert_str_to_digit(*start++);
  //   int next_number = 0;
  //   for (; start < end && fmt->precision;) {
  //     if (*start == '.') {
  //       *start++ = '\0';
  //       *start = convert_digit_to_str(convert_str_to_digit(*start) + 1);

  //       return;
  //     }

  //     next_number = convert_str_to_digit(*start++);

  //     if (previous_number >= 5) next_number++;
  //     if (next_number != 10) {
  //       *start = convert_digit_to_str(next_number);
  //       *(start - 1) = '\0';

  //       return;
  //     }

  //     previous_number = next_number;
  //   }
}

void insert_spaces(Fmt *fmt, char *buffer, char *buffer_end) {
  int written = buffer_end - buffer;
  int spaces = fmt->width - written;
  char sign = 'r';

  if (fmt->is_negative)
    sign = '-';
  else if (fmt->flag_plus)
    sign = '+';
  else if (fmt->flag_space)
    sign = ' ';

  if (sign != 'r') spaces--;

  if (!fmt->flag_minus) {
    if (fmt->flag_zero) {
      if (fmt->is_negative || fmt->flag_plus || fmt->flag_space) {
        *fmt->str++ = sign;
      }

      while (spaces-- > 0) *fmt->str++ = '0';
    } else {
      while (spaces-- > 0) *fmt->str++ = ' ';
      if (fmt->is_negative || fmt->flag_plus || fmt->flag_space) {
        *fmt->str++ = sign;
      }
    }
  } else if (fmt->is_negative || fmt->flag_plus || fmt->flag_space) {
    *fmt->str++ = sign;
  }

  while (buffer < buffer_end) {
    *fmt->str++ = *buffer++;
  }

  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}

void insert_number(Fmt *fmt) {
  char *string_start = fmt->number.string;
  char *string_end = fmt->number.string_end - 1;
  int written = string_end - string_start;
  int spaces = fmt->width - written - 1;

  char sign = '\0';
  if (fmt->is_negative)
    sign = '-';
  else if (fmt->flag_plus)
    sign = '+';
  else if (fmt->flag_space)
    sign = ' ';

  // Adds spaces to the left
  if (!(fmt->flag_minus || fmt->flag_zero)) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }

  // Adds sign
  if (sign != '\0') {
    *fmt->str++ = sign;
    spaces--;
  }

  // Adds zeros to the left
  if (fmt->flag_zero) {
    while (spaces-- > 0) *fmt->str++ = '0';
  }

  // Rewrite to the provided str buffer from the temp buffer
  while (string_start <= string_end) {
    *fmt->str++ = *string_end--;
  }

  // Adds spaces to the right
  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}

// --------------------
// ----- Handlers -----
// --------------------

void insert_integer(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    int number = va_arg(fmt->args, int);
    int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    long number = va_arg(fmt->args, long);
    int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    long long number = va_arg(fmt->args, long long);
    int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    short number = va_arg(fmt->args, int);
    int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    char number = va_arg(fmt->args, int);
    int_to_str(number, fmt);
  }

  insert_number(fmt);
}

void insert_float(Fmt *fmt) {
  long double number = 0;

  if (s21_strcmp(fmt->length, "") == 0 || s21_strcmp(fmt->length, "l") == 0) {
    number = (long double)va_arg(fmt->args, double);
  } else if (s21_strcmp(fmt->length, "L") == 0) {
    number = va_arg(fmt->args, long double);
  }

  float_to_str(number, fmt);
  insert_number(fmt);
}

void insert_octal(Fmt *fmt) {
  char buffer[500] = {0};
  char *buffer_end = buffer;

  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    octal_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    octal_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    octal_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    octal_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    octal_to_str(number, buffer_end, fmt);
  }

  insert_spaces(fmt, buffer, buffer_end);
}

void insert_string(Fmt *fmt) {
  char *string = va_arg(fmt->args, char *);
  s21_size_t length = s21_strlen(string);

  insert_spaces(fmt, string, string + length);
}

void insert_character(Fmt *fmt) {
  char buffer[2] = {0};
  char *buffer_end = buffer;

  *buffer_end++ = va_arg(fmt->args, int);
  *buffer_end = '\0';

  insert_spaces(fmt, buffer, buffer_end);
}

void insert_unsigned_integer(Fmt *fmt) {
  char buffer[500] = {0};
  char *buffer_end = buffer;

  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    unsigned_int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    unsigned_int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    unsigned_int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    unsigned_int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    unsigned_int_to_str(number, buffer_end, fmt);
  }

  insert_spaces(fmt, buffer, buffer_end);
}

void insert_hexadecimal(Fmt *fmt) {
  char buffer[500] = {0};
  char *buffer_end = buffer;
  char hex_case;

  if (fmt->specifier == 'x') {
    hex_case = 'a';
  } else {
    hex_case = 'A';
  }

  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    hexadecimal_to_str(number, buffer_end, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    hexadecimal_to_str(number, buffer_end, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    hexadecimal_to_str(number, buffer_end, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    hexadecimal_to_str(number, buffer_end, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    hexadecimal_to_str(number, buffer_end, hex_case, fmt);
  }

  insert_spaces(fmt, buffer, buffer_end);
}

void insert_pointer(Fmt *fmt) {
  char buffer[500] = {0};
  char *buffer_end = buffer;
  void *ptr = va_arg(fmt->args, void *);
  unsigned long address = (unsigned long)ptr;

  if (address == 0) {
    *fmt->str++ = '(';
    *fmt->str++ = 'n';
    *fmt->str++ = 'i';
    *fmt->str++ = 'l';
    *fmt->str++ = ')';
    *fmt->str = '\0';
    return;
  }

  fmt->flag_base = true;
  hexadecimal_to_str(address, buffer_end, 'a', fmt);

  insert_spaces(fmt, buffer, buffer_end);
}

void return_count(Fmt *fmt, char *str) {
  if (s21_strcmp(fmt->length, "") == 0) {
    int *count = va_arg(fmt->args, int *);
    *count = fmt->str - str;

  } else if (s21_strcmp(fmt->length, "l") == 0) {
    long *count = va_arg(fmt->args, long *);
    *count = fmt->str - str;

  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    long long *count = va_arg(fmt->args, long long *);
    *count = fmt->str - str;

  } else if (s21_strcmp(fmt->length, "h") == 0) {
    short *count = va_arg(fmt->args, short *);
    *count = fmt->str - str;
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    char *count = va_arg(fmt->args, char *);
    *count = fmt->str - str;
  }
}
