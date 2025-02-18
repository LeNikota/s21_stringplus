#include "./tests/test.h"

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Создание массива указателей на сьюты
  Suite *suites[] = {
      s21_insert_test(),
      s21_memchr_test(),
      s21_memcmp_test(),
      s21_memcpy_test(),
      s21_memset_test(),
      s21_strchr_test(),
      s21_strcspn_test(),
      s21_strerror_test(),
      s21_strlen_test(),
      s21_strncat_test(),
      s21_strncmp_test(),
      s21_strncpy_test(),
      s21_strpbrk_test(),
      s21_strrchr_test(),
      s21_strstr_test(),
      s21_strtok_test(),
      s21_to_lower_test(),
      s21_to_upper_test(),
      s21_trim_test(),
      s21_sprintf_test(),
      s21_sscanf_test(),
      NULL  // Завершающий элемент массива
  };

  int total_failed = 0;  // Счетчик неудачных тестов

  // Цикл по всем сьютам
  for (int i = 0; suites[i] != NULL; i++) {
    SRunner *runner =
        srunner_create(suites[i]);  // Создание нового SRunner для каждого сьюта
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);  // Запуск тестов
    int number_failed =
        srunner_ntests_failed(runner);  // Получение количества неудачных тестов
    total_failed += number_failed;  // Суммирование неудачных тестов
    srunner_free(runner);  // Освобождение памяти
  }

  return (total_failed == 0) ? EXIT_SUCCESS
                             : EXIT_FAILURE;  // Возврат результата
}
