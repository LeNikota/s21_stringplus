#include <stdio.h>

#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  while (n && *src) {
    *dest++ = *src++;
    n--;
  }

  while (n) {
    *dest++ = '\0';
    n--;
  }

  return dest;
}