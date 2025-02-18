#include "s21_string.h"

// Основная функция для чтения строки с форматированием
int s21_sscanf(const char* str, const char* format, ...) {
  if (str == NULL || format == NULL) return -1;

  char* s = (char*)str;
  char* f = (char*)format;
  struct specifiers spec = {0};
  va_list ap;
  va_start(ap, format);

  // Проверяет наличие пустых входных данных с помощью спецификаторов
  // преобразования
  while (*f) {
    if (*f == '%' && *(f + 1) != '%') {
      if (*str == '\0') {
        va_end(ap);
        return -1;
      }
      break;
    }
    f++;
  }
  f = (char*)format;

  while (*f != '\0') {
    if (*f == '%') {
      spec.percent = *f;
      f++;

      if (*f == '%') {
        if (!s21_skip_and_match(&s, &f)) {
          spec.qty = 0;  // установка 0 для несоответствия %%
        }
        continue;
      } else {
        if (s21_process_format_specifier(&f, &s, &spec, &ap, str)) {
          break;
        }
      }
    } else if (*f == ' ' || *f == '\n' || *f == '\t') {
      f++;
      spec.space++;
    } else {
      if (*f == *s) {
        s++;
        f++;
      } else {
        break;
      }
    }
  }

  va_end(ap);
  return spec.qty;
}

// Функция для обработки различных флагов в спецификаторе
int s21_format_pars(char** f, struct specifiers* spec) {
  if (**f == '*') {
    spec->star = **f;
    *f = *f + 1;
  }
  // Обработка ширины поля
  if (**f >= '0' && **f <= '9') {
    int width = 0;
    while (**f >= '0' && **f <= '9') {
      width = width * 10 + (**f - 48);
      *f = *f + 1;
    }
    spec->width = width;
  }
  // Обработка модификаторов типа
  if (**f == 'L' || **f == 'l' || **f == 'h') {
    spec->mod = **f;
    *f = *f + 1;
  }
  // Обработка спецификатора
  if (**f == 'c' || **f == 'd' || **f == 'f' || **f == 's' || **f == 'o' ||
      **f == 'x' || **f == 'X' || **f == 'e' || **f == 'E' || **f == 'g' ||
      **f == 'G' || **f == 'u' || **f == 'n' || **f == 'i' || **f == 'p') {
    spec->type = **f;
    *f = *f + 1;
    return 0;
  }
  *f = *f + 1;
  return 1;
}

// Функция для обработки чтения строк
int s21_str_read(char** s, struct specifiers* spec, va_list* ap,
                 const char* str) {
  int re = 0;
  if (spec->type == 'd' || spec->type == 'u') {  // Если тип - число
    re = s21_flag_d(&s, spec, ap);
    s21_track_conversion_result(spec, re);
  }
  if (spec->type == 'f' || spec->type == 'e' ||
      spec->type == 'E' ||  // Если тип - число с плавающей точкой
      spec->type == 'g' || spec->type == 'G') {
    re = s21_flag_f(&s, spec, ap);
    s21_track_conversion_result(spec, re);
  }
  if (spec->type == 'x' || spec->type == 'X' ||
      spec->type == 'p') {  // Если тип - шестнадцатеричное число
    re = s21_flag_x(&s, spec, ap);
    s21_track_conversion_result(spec, re);
  }
  if (spec->type == 's') {  // Если тип - строка
    re = s21_flag_s(&s, spec, ap);
    s21_track_conversion_result(spec, re);
  }
  if (spec->type == 'o') {  // Если тип - восьмеричное число
    re = s21_flag_o(&s, spec, ap);
    s21_track_conversion_result(spec, re);
  }

  if (spec->type ==
      'i') {  // Если тип - автоматическое определение системы счисления
    re = s21_flag_i(s, spec, ap);
    s21_track_conversion_result(spec, re);
  }
  if (spec->type == 'c') {  // Если тип - символ
    re = s21_flag_c(&s, spec, ap);
    s21_track_conversion_result(spec, re);
  }

  if (spec->type == 'n') {  // Если тип - подсчет символов
    re = s21_flag_n(&s, str, ap, spec);
    if (spec->first_converse == 0) {
      spec->first_converse++;
    }
  }
  return re;
}

// Функция для перехода к следующему символу для чтения числа
void s21_go_to_10(char*** s, long int* out, int* count) {
  *out = *out * 10 + (***s - 48);
  **s = **s + 1;
  *count = *count + 1;
}

// Функция для пропуска пробельных символов и сравнения с форматом
int s21_skip_and_match(char** s, char** f) {
  // Skip whitespace only for non-%% matches
  if (**f != '%') {
    while (**s == ' ' || **s == '\n' || **s == '\t') {
      (*s)++;
    }
  }

  if (**f == '%') {
    if (**s != '%') {
      return 0;  // возвращаем 0 для несоответствия %%
    }
    (*s)++;
    (*f)++;
    return 1;
  }
  return 0;
}

void s21_space_skip(char*** s) {
  // Пропускает все пробельные символы, такие как пробелы, новые строки или
  // табуляции.
  while (***s == ' ' || ***s == '\n' || ***s == '\t') {
    **s = **s + 1;
  }
}

int s21_process_format_specifier(char** f, char** s, struct specifiers* spec,
                                 va_list* ap, const char* str) {
  spec->width = 0;

  // Парсим флаг формата
  if (s21_format_pars(f, spec) == 0) {
    if (s21_str_read(s, spec, ap, str)) {
      return 1;
    } else {
      spec->percent = 0;
      spec->star = 0;
      spec->width = 0;
      spec->mod = 0;
      spec->type = 0;
      spec->space = 0;
      return 0;
    }
  } else {
    (*f)++;
    return 1;
  }
}

// ------------ функция записи результата работы функции спецификатора----------
void s21_track_conversion_result(struct specifiers* spec, int re) {
  // Увеличиваем счетчик количества аргументов, если не был использован флаг '*'
  if (spec->star == 0 && re == 0) {
    spec->qty++;
  }

  if (spec->first_converse == 0 && re == 0) {
    spec->first_converse++;
  }
}

void s21_minus_flag(char*** s, int* minus, int* flag) {
  // Проверка на знак перед числом, если он есть
  if (***s == '-' || ***s == '+') {
    if (***s == '-') {
      *minus = -1;
      *flag = 1;
    } else {
      *minus = 1;
      *flag = 1;
    }
    **s = **s + 1;
  }
}

// Функция обработки спецификатора %d
int s21_flag_d(char*** s, const struct specifiers* spec, va_list* ap) {
  long int result = 0;
  int sign = 1;
  int has_sign = 0;
  int digit_count = 0;

  s21_space_skip(s);

  s21_minus_flag(s, &sign, &has_sign);

  if (spec->width == 0) {
    while (***s >= '0' && ***s <= '9') {
      s21_go_to_10(s, &result, &digit_count);
    }
  } else {
    while (***s >= '0' && ***s <= '9' &&
           (digit_count + has_sign) < spec->width) {
      s21_go_to_10(s, &result, &digit_count);
    }
  }

  if (digit_count > 0) {
    result *= sign;
  }

  if (spec->star == 0) {
    s21_apply_argument(spec, ap, result);
  }

  return digit_count > 0 ? 0 : 1;
}

int s21_flag_f(char*** s, const struct specifiers* spec, va_list* ap) {
  long double out = 0.0;
  int minus = 1;
  int flag = 0;
  int success = 0;
  int chars_read = 0;

  s21_space_skip(s);
  s21_minus_flag(s, &minus, &flag);
  if (flag) chars_read++;

  if (***s == 'n' || ***s == 'N' || ***s == 'i' || ***s == 'I') {
    success = s21_nan_inf(s, &minus, &out);
  } else {
    while (***s >= '0' && ***s <= '9' &&
           (spec->width == 0 || chars_read < spec->width)) {
      out = out * 10.0 + (***s - '0');
      **s = **s + 1;
      chars_read++;
      success = 1;
    }

    if (***s == '.' && (spec->width == 0 || chars_read < spec->width)) {
      **s = **s + 1;
      chars_read++;
      long double decimal = 0.1;

      while (***s >= '0' && ***s <= '9' &&
             (spec->width == 0 || chars_read < spec->width)) {
        out += (***s - '0') * decimal;
        decimal *= 0.1;
        **s = **s + 1;
        chars_read++;
        success = 1;
      }
    }

    if (success && (***s == 'e' || ***s == 'E') &&
        (spec->width == 0 || chars_read < spec->width)) {
      s21_scientific_format(s, &out);
    }

    out *= minus;
  }

  if (success && spec->star == 0) {
    if (spec->mod == 'L') {
      *va_arg(*ap, long double*) = out;
    } else if (spec->mod == 'l') {
      *va_arg(*ap, double*) = (double)out;
    } else {
      *va_arg(*ap, float*) = (float)out;
    }
  }

  return success ? 0 : 1;
}

int s21_nan_inf(char*** s, const int* minus, long double* out) {
  int ret = 0;
  if ((***s == 'n' || ***s == 'N')) {
    **s = **s + 1;
    if ((***s == 'a' || ***s == 'A')) {
      **s = **s + 1;
      if ((***s == 'n' || ***s == 'N')) {
        **s = **s + 1;
        *out = S21_NAN;
        ret = 1;
      }
    }
  } else if ((***s == 'i' || ***s == 'I')) {
    **s = **s + 1;
    if ((***s == 'n' || ***s == 'N')) {
      **s = **s + 1;
      if ((***s == 'f' || ***s == 'F')) {
        **s = **s + 1;
        *out = (long double)S21_INF * *minus;
        ret = 1;
      }
    }
  }
  return ret;
}

void s21_scientific_format(char*** s, long double* out) {
  **s = **s + 1;  // Skip 'e' or 'E'

  int exp_sign = 1;
  if (***s == '+' || ***s == '-') {
    exp_sign = (***s == '-') ? -1 : 1;
    **s = **s + 1;
  }

  int exponent = 0;
  while (***s >= '0' && ***s <= '9') {
    exponent = exponent * 10 + (***s - '0');
    **s = **s + 1;
  }

  *out *= pow(10.0, exp_sign * exponent);
}

// Функция для обработки символа (%c)
int s21_flag_c(char*** s, const struct specifiers* spec, va_list* ap) {
  char out = 0;

  if (spec->space != 0) {
    s21_space_skip(s);
  }

  out = ***s;

  **s = **s + spec->width + 1;

  if (spec->star == 0) {
    if (spec->mod == 'l') {
      *va_arg(*ap, wchar_t*) = (wchar_t)out;
    } else {
      *va_arg(*ap, char*) = out;
    }
  }

  return 0;
}

// Функция для обработки строки (%s)
int s21_flag_s(char*** s, const struct specifiers* spec, va_list* ap) {
  char out[1024] = {0};
  int count = 0;

  s21_space_skip(s);

  if (spec->width == 0) {
    while (***s != '\n' && ***s != ' ' && ***s != '\t' && ***s != '\0') {
      s21_flag_s_help(s, out, &count);
    }
  } else {
    while (***s != '\n' && ***s != ' ' && ***s != '\t' && ***s != '\0' &&
           count < spec->width) {
      s21_flag_s_help(s, out, &count);
    }
  }

  out[count] = '\0';

  if (spec->star == 0) {
    char* out1 = va_arg(*ap, char*);
    int i = 0;

    while (out[i] != '\0') {
      out1[i] = out[i];
      i++;
    }

    out1[i] = '\0';
  }

  return count > 0 ? 0 : 1;
}

// Вспомогательная функция для чтения строки
void s21_flag_s_help(char*** s, char* out, int* count) {
  out[*count] = ***s;

  **s = **s + 1;

  *count += 1;
}

// Функция для обработки восьмеричного числа (%o)
int s21_flag_o(char*** s, const struct specifiers* spec, va_list* ap) {
  long int result = 0;
  int sign = 1, modifier = 0;

  s21_space_skip(s);

  s21_minus_flag(s, &sign, &modifier);

  int digits_count = 0;

  // Чтение чисел в системе счисления 8 (до '7') или до указанной ширины
  if (spec->width == 0) {
    while (***s >= '0' && ***s <= '7') {
      s21_flag_o_helper(s, &result, &digits_count);
    }
  } else {
    while (***s >= '0' && ***s <= '7' &&
           (digits_count + modifier) < spec->width) {
      s21_flag_o_helper(s, &result, &digits_count);
    }
  }

  if (digits_count > 0) {
    result *= sign;
  }

  if (spec->star == 0) {
    s21_apply_argument(spec, ap, result);
  }

  return digits_count == 0 ? 1 : 0;
}

// Вспомогательная функция для обработки восьмеричных цифр
void s21_flag_o_helper(char*** s, long int* result, int* digits_count) {
  *result = *result * 8 + (***s - '0');

  **s = **s + 1;

  *digits_count += 1;
}

// Функция для записи результата в переменную в зависимости от модификатора типа
void s21_apply_argument(const struct specifiers* spec, va_list* ap,
                        long int result) {
  // Применяем модификатор типа для записи результата в переменную
  if (spec->mod == 'h') {
    *va_arg(*ap, short int*) = (short int)result;
  } else if (spec->mod == 'l') {
    *va_arg(*ap, long int*) = (long int)result;
  } else {
    *va_arg(*ap, int*) = (int)result;
  }
}

// Функция для обработки шестнадцатиричных чисел (%x, %X)
int s21_flag_x(char*** s, const struct specifiers* spec, va_list* ap) {
  long int out = 0;
  int minus = 1, flag = 0;

  s21_space_skip(s);

  s21_minus_flag(s, &minus, &flag);
  int count = 0, number = 0;

  if (spec->width == 0) {
    while ((***s >= '0' && ***s <= '9') || (***s >= 'A' && ***s <= 'F') ||
           (***s >= 'a' && ***s <= 'f') || ***s == 'x' || ***s == 'X') {
      s21_flag_x_help(s, &number, &out, &count);
    }
  } else {
    while (((***s >= '0' && ***s <= '9') || (***s >= 'A' && ***s <= 'F') ||
            (***s >= 'a' && ***s <= 'f') || ***s == 'x' || ***s == 'X') &&
           (count + flag) < spec->width) {
      s21_flag_x_help(s, &number, &out, &count);
    }
  }

  if (count > 0) {
    out *= minus;
  }

  if (spec->star == 0) {
    if (spec->type == 'p') {
      *va_arg(*ap, void**) = (void*)out;
    } else {
      s21_apply_argument(spec, ap, out);
    }
  }
  return count == 0 ? 1 : 0;
}

// Вспомогательная функция для обработки шестнадцатиричных цифр
void s21_flag_x_help(char*** s, int* number, long int* out, int* count) {
  if ((***s >= 'A' && ***s <= 'F') || (***s >= 'a' && ***s <= 'f')) {
    if (***s == 'A' || ***s == 'a') {
      *number = 10;
    }
    if (***s == 'B' || ***s == 'b') {
      *number = 11;
    }
    if (***s == 'C' || ***s == 'c') {
      *number = 12;
    }
    if (***s == 'D' || ***s == 'd') {
      *number = 13;
    }
    if (***s == 'E' || ***s == 'e') {
      *number = 14;
    }
    if (***s == 'F' || ***s == 'f') {
      *number = 15;
    }
  } else {
    *number = ***s - 48;
  }
  if (***s != 'x' && ***s != 'X') {
    *out = *out * 16 + *number;
  }
  **s = **s + 1;
  *count = *count + 1;
}

// Проверка, является ли символ шестнадцатиричной цифрой
// Функция для обработки флага %n
int s21_flag_n(char*** s, const char* str, va_list* ap,
               const struct specifiers* spec) {
  long int out = 0;

  out = **s - str;

  if (spec->star == 0) {
    s21_apply_argument(spec, ap, out);
  }

  return 0;
}

// Функция для обработки числа с учетом флага %i
int s21_flag_i(char** s, const struct specifiers* spec, va_list* ap) {
  int out = 0;
  int flt = 0;
  int minus = 0, flag = 0;

  s21_space_skip(&s);

  s21_minus_flag(&s, &minus, &flag);

  // Определяем формат числа
  if (**s == '0') {
    *s = *s + 1;
    if (**s == 'x' || **s == 'X') {
      out = 'x';
    } else {
      out = 'o';
    }
  } else {
    out = 'd';
  }

  if (minus) {
    *s = *s - 1;
  }

  // Обрабатываем флаг в зависимости от формата
  if (out == 'd') {
    flt = s21_flag_d(&s, spec, ap);
  } else if (out == 'o') {
    *s = *s - 1;
    flt = s21_flag_o(&s, spec, ap);
  } else if (out == 'x') {
    *s = *s - 1;
    flt = s21_flag_x(&s, spec, ap);
  }

  return flt;
}
