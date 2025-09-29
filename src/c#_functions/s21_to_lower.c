#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;

  s21_size_t len = s21_strlen(str);

  char *lower_str = (char *)malloc(len + 1);
  if (lower_str == S21_NULL) return S21_NULL;

  for (s21_size_t i = 0; i < len; i++) {
    char current_char = str[i];

    if (current_char >= 'A' && current_char <= 'Z')
      lower_str[i] = current_char + 32;
    else
      lower_str[i] = current_char;
  }

  lower_str[len] = '\0';

  return lower_str;
}