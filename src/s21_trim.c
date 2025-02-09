#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL || trim_chars == S21_NULL) return S21_NULL;

  const char *start = src;
  while (*start && s21_strchr(trim_chars, *start)) {
    start++;
  }

  const char *end = src + s21_strlen(src) - 1;

  while (end > start && s21_strchr(trim_chars, *end)) {
    end--;
  }

  size_t len = end - start + 1;

  char *trimmed_str = (char *)malloc(len + 1);
  if (trimmed_str == S21_NULL) return S21_NULL;

  s21_strncpy(trimmed_str, start, len);
  trimmed_str[len] = '\0';

  return trimmed_str;
}
