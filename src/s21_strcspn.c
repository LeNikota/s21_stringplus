#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int is_complete = 0;

  while (str1[count]) {
    const char *temp = str2;
    while (*temp) {
      if (str1[count] == *temp) {
        is_complete = 1;
        break;
      }
      temp++;
    }
    if (is_complete) break;

    count++;
  }

  return count;
}
