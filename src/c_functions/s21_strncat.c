#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *start = dest;

  while (*dest) dest++;

  while (n-- && *src) *dest++ = *src++;

  *dest = '\0';

  return start;
}

// Used in insert
char *s21_strcat(char *dest, const char *src) {
  char *start = dest;

  while (*dest) dest++;

  while (*src) *dest++ = *src++;

  *dest = '\0';

  return start;
}
