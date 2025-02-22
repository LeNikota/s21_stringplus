#include "s21_string.h"

int s21_memcmp(const void *s1, const void *s2, s21_size_t len) {
  unsigned char *p = (unsigned char *)s1;
  unsigned char *q = (unsigned char *)s2;
  int compare_status = 0;

  if (s1 == s2) {
    return compare_status;
  }
  while (len > 0) {
    if (*p != *q) {
      compare_status = (*p > *q) ? 1 : -1;
      break;
    }
    len--;
    p++;
    q++;
  }
  return compare_status;
}