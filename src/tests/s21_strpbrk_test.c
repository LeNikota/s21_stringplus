#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_strpbrk_1) {
  const char str1[] = "Hello, World!";
  const char str2[] = "aeiou";

  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_2) {
  const char str1[] = "Goodbye!";
  const char str2[] = "aeiou";

  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_3) {
  const char str1[] = "abcdefg";
  const char str2[] = "xyz";

  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_4) {
  const char str1[] = "1234567890";
  const char str2[] = "456";

  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_5) {
  const char str1[] = "Hello, World!";
  const char str2[] = "o";

  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_6) {
  const char str1[] = "";
  const char str2[] = "abc";

  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_7) {
  const char str1[] = "abcdef";
  const char str2[] = "";

  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_8) {
  const char str1[] = "Hello, World!";
  const char str2[] = "W";

  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *s21_strpbrk_test(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, s21_strpbrk_1);
  tcase_add_test(tc, s21_strpbrk_2);
  tcase_add_test(tc, s21_strpbrk_3);
  tcase_add_test(tc, s21_strpbrk_4);
  tcase_add_test(tc, s21_strpbrk_5);
  tcase_add_test(tc, s21_strpbrk_6);
  tcase_add_test(tc, s21_strpbrk_7);
  tcase_add_test(tc, s21_strpbrk_8);

  suite_add_tcase(s, tc);
  return s;
}
