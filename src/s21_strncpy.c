#include <stdio.h>

#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src,
                  s21_size_t n) {  // копирование строки с ограничением по
                                   // длине: проверка на NULL,
  // копирование до п или конца строки src, дополнение нулями до п
  if (!dest || !src) return S21_NULL;

  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i] = '\0';
  }
  // dest[n] = '\0';
  return dest;
}
