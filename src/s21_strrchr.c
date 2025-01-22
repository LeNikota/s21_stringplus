#include "s21_string.h"

char *s21_strrchr(const char *s, int c) {
    const char *last_occurrence = S21_NULL;

    while (*s) {
        if (*s == (char)c) {
            last_occurrence = s;
        }
        s++;
    }

    if (c == '\0') {
        last_occurrence = s;
    }

    return (char *)last_occurrence;
}
