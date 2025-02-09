#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_memcmp_1) {
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_memcmp_2) {
  const char str1[] = "Hello";
  const char str2[] = "World";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
  ck_assert_int_eq(s21_memcmp(str2, str1, 5), memcmp(str2, str1, 5));
}
END_TEST

START_TEST(s21_memcmp_3) {
  const char str1[] = "Hello";
  const char str2[] = "Hell";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

START_TEST(s21_memcmp_4) {
  const char str1[] = "Hello";
  const char str2[] = "Hello, World";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
  ck_assert_int_eq(s21_memcmp(str2, str1, 5), memcmp(str2, str1, 5));
}
END_TEST

START_TEST(s21_memcmp_5) {
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_memcmp_6) {
  const char str1[] = "abc";
  const char str2[] = "abcd";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
  ck_assert_int_eq(s21_memcmp(str2, str1, 4), memcmp(str2, str1, 4));
}
END_TEST

START_TEST(s21_memcmp_7) {
  const char str1[] = "Lorem ipsum dolor sit amet.";
  const char str2[] = "Lorem ipsum dolor sit amet.";
  ck_assert_int_eq(s21_memcmp(str1, str2, 27), memcmp(str1, str2, 27));
}
END_TEST

/*
START_TEST (s21_memcmp_8) {
    const char str1[] = "Lorem ipsum dolor sit amet.";
    const char str2[] = "Lorem ipsum dolor sit amet, consectetur adipiscing
elit."; ck_assert_int_eq(s21_memcmp(str1, str2, 27), memcmp(str1, str2, 27)); }
END_TEST
*/

Suite *s21_memcmp_test(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_memcmp_1);
  tcase_add_test(tc, s21_memcmp_2);
  tcase_add_test(tc, s21_memcmp_3);
  tcase_add_test(tc, s21_memcmp_4);
  tcase_add_test(tc, s21_memcmp_5);
  tcase_add_test(tc, s21_memcmp_6);
  tcase_add_test(tc, s21_memcmp_7);
  // tcase_add_test(tc, s21_memcmp_8); // Закомментировано, если не нужно
  suite_add_tcase(s, tc);
  return s;
}
