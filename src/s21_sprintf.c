
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
        fmt.is_precision_specified = true;
        p += 2;
      } else if (*p == '.') {
        p++;
        fmt.precision = parse_int(&p);
        fmt.is_precision_specified = true;
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
        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
          handle_float(&fmt);
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

int convert_str_to_digit(char chr) { return chr - '0'; }
char convert_digit_to_str(int digit) { return digit + '0'; }

void reset_fmt(Fmt *fmt) {
  fmt->flag_minus = false;
  fmt->flag_plus = false;
  fmt->flag_space = false;
  fmt->flag_base = false;
  fmt->flag_zero = false;
  fmt->flag_point = false;

  fmt->width = 0;
  fmt->precision = 6;
  fmt->is_precision_specified = 0;

  s21_memset(fmt->length, 0, sizeof(fmt->length));
  fmt->specifier = 0;

  fmt->is_negative = 0;

  fmt->number.string_end = fmt->number.string;
  fmt->number.completely_rounded = false;
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
  bool is_specifier_e = fmt->specifier == 'e' || fmt->specifier == 'E';
  bool is_specifier_g = fmt->specifier == 'g' || fmt->specifier == 'G';
  int precision = fmt->precision;
  int exponent = 0;

  if (signbit(number)) {
    number = -number;
    fmt->is_negative = 1;
  }

  if (isnan(number)) {
    *fmt->number.string_end++ = 'n';
    *fmt->number.string_end++ = 'a';
    *fmt->number.string_end++ = 'n';
    return;
  }
  if (isinf(number)) {
    *fmt->number.string_end++ = 'f';
    *fmt->number.string_end++ = 'n';
    *fmt->number.string_end++ = 'i';
    return;
  }

  // Calculate exponent for scientific notation
  if (is_specifier_e || is_specifier_g) {
    if (number != 0.0) {
      exponent = (int)floor(log10l(number));
    }
  }

  // Handle %g/%G specific logic
  if (is_specifier_g) {
    int P = precision;
    if (precision == 0) P = 1;  // Precision 0 becomes 1

    if (P > exponent && exponent >= -4) {
      // Use %f style with adjusted precision
      is_specifier_e = false;
      fmt->precision = P - 1 - exponent;
      if (fmt->precision < 0) fmt->precision = 0;
    } else {
      // Use %e style with adjusted precision
      is_specifier_e = true;
      fmt->precision = P - 1;
      if (fmt->precision < 0) fmt->precision = 0;
    }
  }

  // Normalize number for scientific notation
  if (is_specifier_e && number != 0.0) {
    number /= powl(10.0, exponent);
  }

  convert_fractional_part(number, fmt);
  round_(fmt);
  if (is_specifier_g && !fmt->flag_base) remove_trailing_zeros(fmt);
  if (is_specifier_e) insert_exp(exponent, fmt);
  invert_str_temp(fmt);
  convert_int_part(number, fmt);
}

void convert_int_part(long double number, Fmt *fmt) {
  long double int_part = truncl(number);

  // Combines fractional part with integral (string)
  // Places a dot
  if (fmt->number.completely_rounded) int_part++;
  if ((fmt->precision > 0 || fmt->flag_base) &&
      fmt->number.string != fmt->number.string_end)
    *fmt->number.string_end++ = '.';

  // Integral part conversion
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

  for (int i = 0; i < fmt->precision + 1 && i < 5000; i++) {
    fractional_part *= 10.0;
    int digit = (int)fractional_part;
    *fmt->number.string_end++ = digit + '0';
    fractional_part -= digit;
  }
}

void round_(Fmt *fmt) {
  char *digits = fmt->number.string;
  int length = fmt->number.string_end - digits;

  // Start from the end and round backwards
  int carry = 0;
  for (int i = length - 1; i >= 0; i--) {
    int digit = convert_str_to_digit(digits[i]);

    if (i == length - 1) {
      // Last digit - check if we need to round
      if (digit >= 5) {
        carry = 1;
        digit = 0;
      }
    } else if (carry > 0) {
      // Apply carry from previous rounding
      digit += carry;
      carry = 0;
      if (digit >= 10) {
        carry = 1;
        digit -= 10;
      }
    }

    digits[i] = convert_digit_to_str(digit);

    // Stop if no more carry to propagate
    if (carry == 0) {
      // fmt->number.string_end = digits + i + 1;
      fmt->number.string_end--;
      return;
    }
  }

  // If carry reached the beginning
  if (carry > 0) {
    fmt->number.completely_rounded = true;
    fmt->number.string_end--;
  }
}

// Inserts exp into fmt
// Example 100 -> 001+e
// Example -100 -> 001-e
void insert_exp(int exponent, Fmt *fmt) {
  char exp_str[20];
  char *exp_str_end = exp_str;
  char exp_sign = fmt->specifier == 'g' || fmt->specifier == 'e' ? 'e' : 'E';

  bool is_exponent_negative = exponent < 0;
  bool is_exponent_digit = exponent < 10;

  do {
    exponent = abs(exponent);
    *exp_str_end++ = (exponent % 10) + '0';
    exponent /= 10;
  } while (exponent > 0);

  if (is_exponent_digit) {
    *exp_str_end++ = '0';
  }

  if (is_exponent_negative)
    *exp_str_end++ = '-';
  else
    *exp_str_end++ = '+';

  *exp_str_end = exp_sign;

  while (exp_str <= exp_str_end) {
    *fmt->number.string_end++ = *exp_str_end--;
  }
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

  while (string_start <= string_end) *fmt->str++ = *string_end--;

  // Adds spaces to the right
  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}

void remove_trailing_zeros(Fmt *fmt) {
  fmt->number.string_end--;

  while (*fmt->number.string_end == '0') fmt->number.string_end--;

  fmt->number.string_end++;
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

void handle_float(Fmt *fmt) {
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
