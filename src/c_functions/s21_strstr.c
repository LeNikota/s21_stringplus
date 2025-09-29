#include "../s21_string.h"

int compare(const char *str, const char *substr) {
  int is_match = 1;

  while (*str && *substr) {
    if (*str != *substr) {
      is_match = 0;
      break;
    }

    str++;
    substr++;
  }

  is_match = (*substr == '\0');

  return is_match;
}

char *s21_strstr(const char *str, const char *substr) {
  if (*substr == '\0') return (char *)str;

  char *occurrence = S21_NULL;

  while (*str) {
    if ((*str == *substr) && compare(str, substr)) {
      occurrence = (char *)str;
      break;
    }

    str++;
  }

  return occurrence;
}
