#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_strerror_1) {
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *s21_strerror_test(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_strerror_1);
  suite_add_tcase(s, tc);
  return s;
}
