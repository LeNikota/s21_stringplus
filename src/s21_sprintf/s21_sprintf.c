
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
      if (fmt.width < 0) {
        fmt.flag_minus = true;
        fmt.width = abs(fmt.width);
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

      if (fmt.precision < 0) {
        if (fmt.specifier == 'f' || fmt.specifier == 'e' ||
            fmt.specifier == 'E' || fmt.specifier == 'g' ||
            fmt.specifier == 'G')
          fmt.precision = 6;
        fmt.is_precision_specified = false;
      }

      // Process the specifier
      switch (fmt.specifier) {
        case 'd':
        case 'i':
          handle_integer(&fmt);
          break;
        case 's':
          handle_string(&fmt);
          if (fmt.is_error) return -1;
          break;
        case 'c':
          handle_character(&fmt);
          if (fmt.is_error) return -1;
          break;
        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
          handle_float(&fmt);
          break;
        case 'o':
          handle_octal(&fmt);
          break;
        case 'u':
          handle_unsigned_integer(&fmt);
          break;
        case 'x':
        case 'X':
          handle_hexadecimal(&fmt);
          break;
        case 'p':
          handle_pointer(&fmt);
          break;
        case 'n':
          handle_return_count(&fmt, str);
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

void reset_fmt(Fmt *fmt) {
  fmt->flag_minus = false;
  fmt->flag_plus = false;
  fmt->flag_space = false;
  fmt->flag_base = false;
  fmt->flag_zero = false;
  fmt->flag_point = false;

  fmt->width = 0;
  fmt->precision = 0;
  fmt->is_precision_specified = 0;

  s21_memset(fmt->length, 0, sizeof(fmt->length));
  fmt->specifier = 0;

  fmt->is_negative = 0;

  fmt->number.string_end = fmt->number.string;
  fmt->number.completely_rounded = false;
  fmt->number.is_fractional_empty = false;

  fmt->is_nan = false;
  fmt->is_inf = false;
}