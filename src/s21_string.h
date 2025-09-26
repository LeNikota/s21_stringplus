#pragma once

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <wchar.h>  // Подключение библиотеки для работы с широкими символами (wchar_t)

#define S21_NULL ((void *)0)
#define S21_INF (1.0 / 0.0)  // Определение бесконечности
#define S21_NAN (0.0 / 0.0)  // Определение NaN (нечисловое значение)

typedef long unsigned int s21_size_t;

// Структура для хранения информации о спецификаторе
typedef struct specifiers {
  int percent;  // Признак процента (%)
  int star;     // Признак флага *
  int type;     // Тип спецификатора (например, %d, %s)
  int first_converse;  // Признак первого сопоставления
  int width;           // Ширина поля
  int space;           // Признак пробела
  int mod;  // Модификатор типа (например, h, l)
  int qty;  // Количество успешных присваиваний
} specifiers;

// string.h
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *str, const char *substr);
char *s21_strtok(char *str, const char *delim);

// complex
int s21_sprintf(char *str, const char *format, ...);

// sscanf
int s21_sscanf(const char *str, const char *format, ...);
int s21_format_pars(char **f, struct specifiers *spec);
int s21_str_read(char **s, struct specifiers *spec, va_list *ap,
                 const char *str);
void s21_go_to_10(char ***s, long int *out, int *count);
int s21_skip_and_match(char **s, char **f);
void s21_space_skip(char ***s);
int s21_process_format_specifier(char **f, char **s, struct specifiers *spec,
                                 va_list *ap, const char *str);
void s21_track_conversion_result(struct specifiers *spec, int re);
void s21_minus_flag(char ***s, int *minus, int *flag);
int s21_flag_d(char ***s, const struct specifiers *spec, va_list *ap);
int s21_flag_f(char ***s, const struct specifiers *spec, va_list *ap);
int s21_nan_inf(char ***s, const int *minus, long double *out);
void s21_flag_f_help(char ***s, int *dot, int *dot_count, long double *out,
                     int *count);
void s21_scientific_format(char ***s, long double *out);
int s21_flag_c(char ***s, const struct specifiers *spec, va_list *ap);
int s21_flag_s(char ***s, const struct specifiers *spec, va_list *ap);
void s21_flag_s_help(char ***s, char *out, int *count);
int s21_flag_o(char ***s, const struct specifiers *spec, va_list *ap);
void s21_flag_o_helper(char ***s, long int *result, int *digits_count);
void s21_apply_argument(const struct specifiers *spec, va_list *ap,
                        long int result);
int s21_flag_x(char ***s, const struct specifiers *spec, va_list *ap);
void s21_flag_x_helper(char ***s, int *hex_digit, long int *result,
                       int *digits_count);
int s21_is_hex_char(char c);
int s21_hex_value(char c);
int s21_flag_n(char ***s, const char *str, va_list *ap,
               const struct specifiers *spec);
int s21_flag_i(char **s, const struct specifiers *spec, va_list *ap);
void s21_flag_x_help(char ***s, int *number, long int *out, int *count);

// C#
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// Utilties
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcat(char *dest, const char *src);
size_t s21_wcslen(const wchar_t *str);