#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_strrchr_1) {
  const char str[] = "Hello, World!";
  char *result = s21_strrchr(str, 'o');
  ck_assert_str_eq(result, "orld!");
}
END_TEST

START_TEST(s21_strrchr_2) {
  const char str[] = "Hello, World!";
  char *result = s21_strrchr(str, 'H');
  ck_assert_str_eq(result, "Hello, World!");
}
END_TEST

START_TEST(s21_strrchr_3) {
  const char str[] = "Hello, World!";
  char *result = s21_strrchr(str, '!');
  ck_assert_str_eq(result, "!");
}
END_TEST

START_TEST(s21_strrchr_4) {
  const char str[] = "Hello, World!";
  char *result = s21_strrchr(str, 'l');
  ck_assert_str_eq(result, "ld!");
}
END_TEST

START_TEST(s21_strrchr_5) {
  const char str[] = "Hello, World!";
  char *result = s21_strrchr(str, 'x');
  ck_assert_ptr_eq(result, S21_NULL);  // Character not found
}
END_TEST

START_TEST(s21_strrchr_6) {
  const char str[] = "";
  char *result = s21_strrchr(str, 'a');
  ck_assert_ptr_eq(result, S21_NULL);  // Empty string
}
END_TEST

START_TEST(s21_strrchr_7) {
  const char str[] = "Hello, World!";
  char *result = s21_strrchr(str, '\0');
  ck_assert_str_eq(result, "");  // Null character at the end
}
END_TEST

Suite *s21_strrchr_test(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, s21_strrchr_1);
  tcase_add_test(tc, s21_strrchr_2);
  tcase_add_test(tc, s21_strrchr_3);
  tcase_add_test(tc, s21_strrchr_4);
  tcase_add_test(tc, s21_strrchr_5);
  tcase_add_test(tc, s21_strrchr_6);
  tcase_add_test(tc, s21_strrchr_7);

  suite_add_tcase(s, tc);
  return s;
}
