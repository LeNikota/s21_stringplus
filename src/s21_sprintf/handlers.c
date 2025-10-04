#include "s21_sprintf.h"

void handle_integer(Fmt *fmt) {
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
    double temp = va_arg(fmt->args, double);

    if (isinf(temp)) fmt->is_inf = true;
    if (isnan(temp)) fmt->is_nan = true;

    number = (long double)temp;
  } else if (s21_strcmp(fmt->length, "L") == 0) {
    number = va_arg(fmt->args, long double);

    if (isinf(number) || number == INFINITY || number == -INFINITY)
      fmt->is_inf = true;
    if (isnan(number)) fmt->is_nan = true;
  }

  float_to_str(number, fmt);

  insert_number(fmt);
}

void handle_octal(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    octal_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    octal_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    octal_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    octal_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    octal_to_str(number, fmt);
  }

  insert_number(fmt);
}

void handle_string(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    char *string = va_arg(fmt->args, char *);
    insert_string(fmt, string);
  } else {
    wchar_t *wstr = va_arg(fmt->args, wchar_t *);
    insert_wstring(fmt, wstr);
  }
}

void handle_character(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    char ch = va_arg(fmt->args, int);
    insert_character(fmt, ch);

  } else {
    wchar_t wc = (wchar_t)va_arg(fmt->args, wint_t);
    insert_wcharacter(fmt, wc);
  }
}

void handle_unsigned_integer(Fmt *fmt) {
  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    unsigned_int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    unsigned_int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    unsigned_int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    unsigned_int_to_str(number, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    unsigned_int_to_str(number, fmt);
  }

  insert_number(fmt);
}

void handle_hexadecimal(Fmt *fmt) {
  char hex_case = (fmt->specifier == 'x') ? 'a' : 'A';

  if (s21_strcmp(fmt->length, "") == 0) {
    unsigned int number = va_arg(fmt->args, unsigned int);
    hexadecimal_to_str(number, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "l") == 0) {
    unsigned long number = va_arg(fmt->args, unsigned long);
    hexadecimal_to_str(number, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "ll") == 0) {
    unsigned long long number = va_arg(fmt->args, unsigned long long);
    hexadecimal_to_str(number, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "h") == 0) {
    unsigned short number = va_arg(fmt->args, int);
    hexadecimal_to_str(number, hex_case, fmt);
  } else if (s21_strcmp(fmt->length, "hh") == 0) {
    unsigned char number = va_arg(fmt->args, int);
    hexadecimal_to_str(number, hex_case, fmt);
  }

  insert_number(fmt);
}

void handle_pointer(Fmt *fmt) {
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
  hexadecimal_to_str(address, 'a', fmt);

  insert_number(fmt);
}

void handle_return_count(Fmt *fmt, char *str) {
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