#include "s21_string.h"

#include <stddef.h> // for size_t

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t count = 0;   

    while (str1[count]) {
        const char *temp = str2;
        while (*temp) {
            if (str1[count] == *temp) {
                return count;
            }
            temp++;
        }
        count++;
    }

    return count;
}
