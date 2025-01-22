#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *str_1 = (char *)str1;
  char *str_2 = (char *)str2;
  int diff = 0;

  if (*str_1 != *str_2) {
    diff = *str_1 - *str_2 > 0 ? 1 : -1;
  } else {
    for (s21_size_t i = 0; i < n; i++) {
      if (str_1[i] != str_2[i]) {
        if ((str_1[i] == '\0' || str_2[i] == '\0') && i + 1 == n)
          diff = str_1[i] - str_2[i] > 0 ? 1 : -1;
        else
          diff = str_1[i] - str_2[i];

        break;
      }
    }
  }

  return diff;
}
