#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_strlen_1) {
  const char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_2) {
  const char str[] = "Hello world";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_3) {
  const char str[] = "Cotton Eye Joe";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *s21_strlen_test(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_strlen_1);
  tcase_add_test(tc, s21_strlen_2);
  tcase_add_test(tc, s21_strlen_3);
  suite_add_tcase(s, tc);
  return s;
}
