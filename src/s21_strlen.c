#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *s = str;

  while (*s != '\0') s++;

  return s - str;
}

size_t s21_wcslen(const wchar_t *str) {
  const wchar_t *s = str;

  if (str == NULL) return 0;

  while (*s) s++;

  return s - str;
}