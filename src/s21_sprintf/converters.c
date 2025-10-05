#include "s21_sprintf.h"

int convert_str_to_digit(char chr) { return chr - '0'; }
char convert_digit_to_str(int digit) { return digit + '0'; }

// Convert a double to string
void float_to_str(long double number, Fmt *fmt) {
  bool is_specifier_e = fmt->specifier == 'e' || fmt->specifier == 'E';
  bool is_specifier_g = fmt->specifier == 'g' || fmt->specifier == 'G';

  fmt->precision = (fmt->is_precision_specified) ? fmt->precision : 6;
  int exponent = 0;

  if (signbit(number)) {
    number = -number;
    fmt->is_negative = 1;
  }

  if (fmt->is_nan) {
    *fmt->number.string_end++ = 'n';
    *fmt->number.string_end++ = 'a';
    *fmt->number.string_end++ = 'n';
    *fmt->number.string_end = '\0';
    return;
  }
  if (fmt->is_inf) {
    *fmt->number.string_end++ = 'f';
    *fmt->number.string_end++ = 'n';
    *fmt->number.string_end++ = 'i';
    *fmt->number.string_end = '\0';
    return;
  }

  if (is_specifier_e) {
    if (number != 0.0) {
      exponent = (int)floor(log10l(number));
    }
  }

  if (is_specifier_g) {
    if (number != 0.0) {
      if (number >= 1.0) {
        exponent = (int)floor(log10l(number));
      } else {
        exponent = (int)floor(log10l(number)) - 1;
      }
      long double rounded = round_to_precision(number, exponent);
      exponent = (int)floor(log10l(rounded));
    }
  }

  // Handle %g/%G specific logic
  if (is_specifier_g) {
    // Precision 0 becomes 1
    int precision = (fmt->precision == 0) ? 1 : fmt->precision;

    if (precision > exponent && exponent >= -4) {
      // Use %f style with adjusted precision
      is_specifier_e = false;
      fmt->precision = precision - 1 - exponent;
      if (fmt->precision < 0) fmt->precision = 0;
    } else {
      // Use %e style with adjusted precision
      is_specifier_e = true;
      fmt->precision = precision - 1;
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
  invert_str(fmt);
  convert_int_part(number, fmt);
}

void convert_int_part(long double number, Fmt *fmt) {
  long double int_part = truncl(number);

  // Combines fractional part with integral (string)
  // Places a dot
  if (fmt->number.completely_rounded) int_part++;
  if ((fmt->precision > 0 || fmt->flag_base) &&
      !fmt->number.is_fractional_empty)
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
  if (is_exponent_negative) exponent = abs(exponent);
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

void remove_trailing_zeros(Fmt *fmt) {
  fmt->number.string_end--;

  while (*fmt->number.string_end == '0') fmt->number.string_end--;

  fmt->number.string_end++;

  if (fmt->number.string == fmt->number.string_end)
    fmt->number.is_fractional_empty = true;
}

long double round_to_precision(long double value, int precision) {
  if (precision < 0) precision = abs(precision);
  long double scale = pow(10.0, precision);
  return round(value * scale) / scale;
}

void invert_str(Fmt *fmt) {
  char *start = fmt->number.string;
  char *end = fmt->number.string_end - 1;

  for (; start < end; start++, end--) {
    char temp = *start;
    *start = *end;
    *end = temp;
  }
}
