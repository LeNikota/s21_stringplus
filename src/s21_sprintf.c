#include "s21_string.h"

#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h> // Добавьте этот заголовок для printf и sprintf


int my_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0; // Счетчик записанных символов
    char *p;
    for (p = (char *)format; *p != '\0'; p++) {
        if (*p == '%') {
            p++; // Переходим к следующему символу
            switch (*p) {
                case 'd': {
                    int i = va_arg(args, int);
                    count += sprintf(str + count, "%d", i); // Используем стандартный sprintf для преобразования
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    count += sprintf(str + count, "%s", s);
                    break;
                }
                // Добавьте другие спецификаторы по мере необходимости
                default:
                    str[count++] = *p; // Если спецификатор не распознан, просто копируем
                    break;
            }
        } else {
            str[count++] = *p; // Копируем обычный символ
        }
    }
    str[count] = '\0'; // Завершаем строку
    va_end(args);
    return count; // Возвращаем количество записанных символов
}