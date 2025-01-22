#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *stop = S21_NULL;
  int is_complete = 0;

  while (*str1) {
    const char *p = str2;
    while (*p) {
      if (*str1 == *p) {
        stop = (char *)str1;

        is_complete = 1;
        break;
      }

      p++;
    }
    if (is_complete) break;

    str1++;
  }

  return stop;
}
