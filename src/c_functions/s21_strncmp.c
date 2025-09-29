#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  while (*str1 && *str1 == *str2 && --n) {
    str1++;
    str2++;
  }

  return *str1 - *str2;
}

// Used in sprintf for checking
int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }

  return *str1 - *str2;
}