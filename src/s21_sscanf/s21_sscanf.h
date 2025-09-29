#include "../s21_string.h"

int s21_format_pars(char **f, struct specifiers *spec);
int s21_str_read(char **s, struct specifiers *spec, va_list *ap,
                 const char *str);
void s21_go_to_10(char ***s, long int *out, int *count);
void s21_space_skip(char ***s);
void s21_track_conversion_result(struct specifiers *spec, int re);
int s21_flag_d(char ***s, const struct specifiers *spec, va_list *ap);
int s21_flag_f(char ***s, const struct specifiers *spec, va_list *ap);
int s21_nan_inf(char ***s, const int *minus, long double *out);
int s21_flag_c(char ***s, const struct specifiers *spec, va_list *ap);
int s21_flag_s(char ***s, const struct specifiers *spec, va_list *ap);
void s21_flag_s_help(char ***s, char *out, int *count);
int s21_flag_o(char ***s, const struct specifiers *spec, va_list *ap);
void s21_flag_o_helper(char ***s, long int *result, int *digits_count);
void s21_apply_argument(const struct specifiers *spec, va_list *ap,
                        long int result);
int s21_flag_x(char ***s, const struct specifiers *spec, va_list *ap);
int s21_flag_n(char ***s, const char *str, va_list *ap,
               const struct specifiers *spec);
int s21_flag_i(char **s, const struct specifiers *spec, va_list *ap);
void s21_flag_x_help(char ***s, int *number, long int *out, int *count);
