
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
        p = parse_int(p, &fmt);
      }

      // Handle precision
      if (*p == '.' && *(p + 1) == '*') {
        fmt.precision = va_arg(fmt.args, int);
        p += 2;
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

const char *parse_int(const char *p, Fmt *fmt) {
  fmt->width = 0;

  while (*p >= '0' && *p <= '9') {
    fmt->width = fmt->width * 10 + (*p - '0');
    p++;
  }

  // Returns moved pointer
  return p;
}

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

void insert_spaces(Fmt *fmt, char *buffer, char *buffer_end) {
  int written = buffer_end - buffer;
  int spaces = fmt->width - written;
  char ch = ' ';

  // // Bad code, cuz sign is placed into buffer in macro
  if (fmt->flag_zero) {
    //   char last = *(buffer_end - 1);
    //   if (s21_strchr("+- ", last)) {
    //     *fmt->str++ = last;
    //     buffer_end--;
    //   }

    ch = '0';
  }

  if (!fmt->flag_minus)
    while (spaces-- > 0) *fmt->str++ = ch;

  while (buffer != buffer_end) {
    *fmt->str++ = *buffer++;
  }

  if (fmt->flag_minus)
    while (spaces-- > 0) *fmt->str++ = ' ';
}

void insert_integer(Fmt *fmt) {
  char buffer[500] = {0};
  char *buffer_end = buffer;

  if (s21_strcmp(fmt->length, "") == 0) {
    int number = va_arg(fmt->args, int);
    int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    long number = va_arg(fmt->args, long);
    int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    long long number = va_arg(fmt->args, long long);
    int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    short number = va_arg(fmt->args, int);
    int_to_str(number, buffer_end, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    char number = va_arg(fmt->args, int);
    int_to_str(number, buffer_end, fmt);
  }

  insert_spaces(fmt, buffer, buffer_end);
}

void insert_float(Fmt *fmt) {
  // !EDIT: may be reduce to long double number
  // !EDIT: precision is not handled
  char buffer[10000] = {0};
  char *buffer_end = buffer;

  if (s21_strcmp(fmt->length, "") == 0 || s21_strcmp(fmt->length, "l") == 0) {
    double number = va_arg(fmt->args, double);
    double_to_str(number, buffer_end, fmt->precision)
  } else if (s21_strcmp(fmt->length, "L") == 0) {
    long double number = va_arg(fmt->args, long double);
    double_to_str(number, buffer_end, fmt->precision)
  }

  insert_spaces(fmt, buffer, buffer_end);
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
    unsigned_int_to_str(number, buffer_end);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    unsigned_int_to_str(number, buffer_end);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    unsigned_int_to_str(number, buffer_end);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    unsigned_int_to_str(number, buffer_end);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    unsigned_int_to_str(number, buffer_end);
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
