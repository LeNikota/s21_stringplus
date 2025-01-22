#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  while (*str1 && *str1 == *str2 && --n) {
    str1 += 1;
    str2++;
  }

  return *str1 - *str2;
}