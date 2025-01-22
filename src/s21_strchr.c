#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *occurrence = S21_NULL;

  while (*str) {
    if (*str == (char)c) {
      occurrence = str;
      break;
    }
    
    str++;
  }

  if ((char)c == '\0') occurrence = str;

  return (char *)occurrence;
}