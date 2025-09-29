#include "../s21_string.h"

/*

Returns a new string in which a specified string (str) is inserted at a
specified index position (start_index) in the given string (src). In case of any
error, return NULL.

*/

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index > src_len) return S21_NULL;

  char *new_str = (char *)malloc(src_len + str_len + 1);
  if (new_str == S21_NULL) return S21_NULL;

  s21_strncpy(new_str, src, start_index);
  new_str[start_index] = '\0';

  s21_strcat(new_str, str);

  s21_strcat(new_str, src + start_index);

  return new_str;
}
