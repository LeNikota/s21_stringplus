
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
            fmt.flag_number = true;
            break;
        }
        p++;
      }

      // Handle width
      if (*p == '*') {
        fmt.width_star = true;
        p++;
      } else if (*p >= '0' && *p <= '9') {
        p = parse_int(p, &fmt);
      }

      // Handle precision
      if (*p == '*') {
        fmt.width_star = true;
        p++;
      } else if (*p == '.') {
        p = parse_int(p, &fmt);
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
          insert_string(&fmt);
          break;
        case 'c':
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
        default:
          *fmt.str++ = *p;
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

const char *parse_int(const char *p, Fmt *fmt) {
  fmt->width = 0;

  while (*p >= '0' && *p <= '9') {
    fmt->width = fmt->width * 10 + (*p - '0');
    p++;
  }

  // Return moved pointer
  return p;
}

void reset_fmt(Fmt *fmt) {
  fmt->flag_minus = false;
  fmt->flag_plus = false;
  fmt->flag_space = false;
  fmt->flag_number = false;
  fmt->flag_zero = false;
  fmt->flag_point = false;

  fmt->width = 0;
  fmt->width_star = false;

  fmt->precision = 0;
  fmt->precision_star = false;

  s21_memset(fmt->length, 0, sizeof(fmt->length));
  fmt->specifier = 0;
}

void insert_integer(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    int number = va_arg(fmt->args, int);
    int_to_str(number, fmt->str, fmt);

  } else if (s21_strcmp(fmt->length, "l") == 0) {
    long number = va_arg(fmt->args, long);
    int_to_str(number, fmt->str, fmt);

  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    long long number = va_arg(fmt->args, long long);
    int_to_str(number, fmt->str, fmt);

  } else if (s21_strcmp(fmt->length, "h") == 0) {
    short number = va_arg(fmt->args, int);
    int_to_str(number, fmt->str, fmt);

  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    char number = va_arg(fmt->args, int);
    int_to_str(number, fmt->str, fmt);
  }
}

void insert_float(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0 || s21_strcmp(fmt->length, "l") == 0) {
    double number = va_arg(fmt->args, double);
    double_to_str(number, fmt->str, 6)
  } else if (s21_strcmp(fmt->length, "L") == 0) {
    long double number = va_arg(fmt->args, long double);
    double_to_str(number, fmt->str, 6)
  }
}

void insert_octal(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    octal_to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    octal_to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    octal_to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    octal_to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    octal_to_str(number, fmt->str);
  }
}

void insert_string(Fmt *fmt) {
  char *string = va_arg(fmt->args, char *);

  while (*string) *fmt->str++ = *string++;
  *fmt->str = '\0';
}

void insert_character(Fmt *fmt) {
  *fmt->str++ = va_arg(fmt->args, int);
  *fmt->str = '\0';
}

void insert_unsigned_integer(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    to_str(number, fmt->str);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    to_str(number, fmt->str);
  }
}

void insert_hexadecimal(Fmt *fmt) {
  char hex_case;

  if (fmt->specifier == 'x') {
    hex_case = 'a';
  } else {
    hex_case = 'A';
  }

  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    hexadecimal_to_str(number, fmt->str, hex_case);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    hexadecimal_to_str(number, fmt->str, hex_case);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    hexadecimal_to_str(number, fmt->str, hex_case);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    hexadecimal_to_str(number, fmt->str, hex_case);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    hexadecimal_to_str(number, fmt->str, hex_case);
  }
}

void insert_pointer(Fmt *fmt) {
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

  *fmt->str++ = '0';
  *fmt->str++ = 'x';

  hexadecimal_to_str(address, fmt->str, 'a');
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
