#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_strncpy_1) {
  const char str1[] = "This is a long test text";
  char str2[100];
  char str3[100];

  strncpy(str2, str1, 5);
  s21_strncpy(str3, str1, 5);

  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(s21_strncpy_2) {
  const char str1[] = "This is a long test text";
  char str2[100];
  char str3[100];

  strncpy(str2, str1, 17);
  s21_strncpy(str3, str1, 17);

  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(s21_strncpy_3) {
  const char str1[] = "This is a long test text";
  char str2[100];
  char str3[100];

  strncpy(str2, str1, 80);
  s21_strncpy(str3, str1, 80);

  ck_assert_str_eq(str2, str3);
  ck_assert_int_eq(str2[50], str3[50]);
}
END_TEST

START_TEST(s21_strncpy_4) {
  const char str1[] = "This is a long test text";
  char str2[100];
  char str3[100];

  strncpy(str2, str1, 16);
  s21_strncpy(str3, str1, 16);

  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(s21_strncpy_5) {
  const char str1[] = "Short";
  char str2[100];
  char str3[100];

  strncpy(str2, str1, 10);  // Копируем больше, чем длина строки
  s21_strncpy(str3, str1, 10);

  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(s21_strncpy_6) {
  const char str1[] = "";
  char str2[100];
  char str3[100];

  strncpy(str2, str1, 1);
  s21_strncpy(str3, str1, 1);

  ck_assert_str_eq(str2, str3);
}
END_TEST

Suite *s21_strncpy_test(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, s21_strncpy_1);
  tcase_add_test(tc, s21_strncpy_2);
  tcase_add_test(tc, s21_strncpy_3);
  tcase_add_test(tc, s21_strncpy_4);
  tcase_add_test(tc, s21_strncpy_5);
  tcase_add_test(tc, s21_strncpy_6);

  suite_add_tcase(s, tc);
  return s;
}