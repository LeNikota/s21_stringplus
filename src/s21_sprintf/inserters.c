#include "s21_sprintf.h"

void insert_number(Fmt *fmt) {
  bool is_zero_prepend = fmt->specifier == 'd' || fmt->specifier == 'i' ||
                         fmt->specifier == 'u' || fmt->specifier == 'x' ||
                         fmt->specifier == 'X' || fmt->specifier == 'o';
  bool is_hex =
      fmt->specifier == 'x' || fmt->specifier == 'X' || fmt->specifier == 'p';
  bool is_octal = fmt->specifier == 'o';

  char *string_start = fmt->number.string;
  char *string_end = fmt->number.string_end - 1;
  int written = string_end - string_start + 1;

  // Calculate total characters needed (without padding)
  int total_chars = written;

  // Add precision padding zeros
  int precision_zeros = 0;
  if (is_zero_prepend) {
    precision_zeros = fmt->precision - written;
    if (precision_zeros < 0) precision_zeros = 0;
    total_chars += precision_zeros;
  }

  // Add sign character if needed
  int sign_length = 0;
  char sign = '\0';
  if (fmt->is_negative) {
    sign = '-';
    sign_length = 1;
  } else if (fmt->flag_plus) {
    sign = '+';
    sign_length = 1;
  } else if (fmt->flag_space) {
    sign = ' ';
    sign_length = 1;
  }
  if (fmt->specifier == 'u' || is_hex) sign_length = 0;  // unsigned, no sign
  total_chars += sign_length;

  // Add prefix if needed - SPECIAL HANDLING FOR OCTAL WITH PRECISION
  int prefix_length = 0;
  bool need_octal_prefix = false;

  if (fmt->flag_base) {
    if (is_hex) {
      prefix_length = 2;  // "0x" or "0X"
    } else if (is_octal) {
      // For octal: only add prefix if it doesn't duplicate precision zero
      // If precision already adds a leading zero, don't add another one
      if (precision_zeros == 0 && *string_start != '0') {
        prefix_length = 1;  // "0"
        need_octal_prefix = true;
      }
    }
  }
  total_chars += prefix_length;

  // Calculate padding spaces
  int spaces = fmt->width - total_chars;
  if (spaces < 0) spaces = 0;

  // Adds spaces to the left (right alignment)
  if (!fmt->flag_minus && !fmt->flag_zero) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }

  // Adds sign
  if (sign_length > 0) *fmt->str++ = sign;

  // Add prefix
  if (prefix_length > 0) {
    if (is_hex) {
      *fmt->str++ = '0';
      *fmt->str++ = (fmt->specifier == 'X') ? 'X' : 'x';
    } else if (is_octal && need_octal_prefix) {
      *fmt->str++ = '0';
    }
  }

  // Adds zeros to the left (zero padding or precision)
  if (!fmt->flag_minus && fmt->flag_zero) {
    while (spaces-- > 0) *fmt->str++ = '0';
  }

  // Add precision zeros
  while (precision_zeros-- > 0) *fmt->str++ = '0';

  // Write the actual number
  while (string_start <= string_end) *fmt->str++ = *string_end--;

  // Adds spaces to the right (left alignment)
  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}

void insert_string(Fmt *fmt, char *string) {
  int precision = fmt->is_precision_specified ? fmt->precision : -1;

  char null_wstr[] = "(null)";
  if (string == S21_NULL) {
    string = null_wstr;
    if (precision < 6 && precision != -1) *string = '\0';
  }

  int written = s21_strlen(string);
  int spaces = (precision > 0 && precision <= written) ? fmt->width - precision
                                                       : fmt->width - written;

  // Adds spaces to the left
  if (!fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }

  while (*string != '\0' && precision--) *fmt->str++ = *string++;

  // Adds spaces to the right
  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}

void insert_wstring(Fmt *fmt, wchar_t *string) {
  int precision = fmt->is_precision_specified ? fmt->precision : -1;

  wchar_t null_wstr[] = L"(null)";
  if (string == S21_NULL) {
    string = null_wstr;
    if (precision < 6 && precision != -1) *string = '\0';
  }

  int written = s21_wcslen(string);
  int spaces = (precision > 0 && precision <= written) ? fmt->width - precision
                                                       : fmt->width - written;

  // Checks for non-ASCII, return error
  wchar_t *check_string = string;
  int check_precision = precision;
  while (*check_string != L'\0' && check_precision--) {
    wchar_t wc = *check_string++;

    if (wc < 0 || wc > 127) {
      fmt->is_error = true;
      *fmt->str++ = '\0';
      return;
    }
  }

  // Adds spaces to the left
  if (!fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }

  while (*string != L'\0' && precision--) {
    wchar_t wc = *string++;

    *fmt->str++ = ((char)wc);
  }

  // Adds spaces to the right
  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}

void insert_character(Fmt *fmt, char ch) {
  int spaces = fmt->width - 1;

  // Adds spaces to the left
  if (!fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }

  *fmt->str++ = ch;

  // Adds spaces to the right
  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}

void insert_wcharacter(Fmt *fmt, wchar_t wc) {
  int spaces = fmt->width - 1;

  // For non-ASCII, return error
  if (wc < 0 || wc > 127) {
    fmt->is_error = true;
    *fmt->str = '\0';
    return;
  }

  // Adds spaces to the left
  if (!fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }

  *fmt->str++ = ((char)wc);

  // Adds spaces to the right
  if (fmt->flag_minus) {
    while (spaces-- > 0) *fmt->str++ = ' ';
  }
}
