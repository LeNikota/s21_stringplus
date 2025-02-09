#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_strcspn_1) {
  const char str1[] = "Hello, World!";
  const char str2[] = " ,!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_2) {
  const char str1[] = "Goodbye!";
  const char str2[] = "aeiou";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_3) {
  const char str1[] = "abcdefg";
  const char str2[] = "xyz";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_4) {
  const char str1[] = "1234567890";
  const char str2[] = "456";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_5) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_6) {
  const char str1[] = "";
  const char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_7) {
  const char str1[] = "abcdef";
  const char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_8) {
  const char str1[] = "Hello, World!";
  const char str2[] = "o";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *s21_strcspn_test(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_strcspn_1);
  tcase_add_test(tc, s21_strcspn_2);
  tcase_add_test(tc, s21_strcspn_3);
  tcase_add_test(tc, s21_strcspn_4);
  tcase_add_test(tc, s21_strcspn_5);
  tcase_add_test(tc, s21_strcspn_6);
  tcase_add_test(tc, s21_strcspn_7);
  tcase_add_test(tc, s21_strcspn_8);
  suite_add_tcase(s, tc);
  return s;
}
