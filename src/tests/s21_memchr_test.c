#include "test.h"

START_TEST(s21_memchr_1) {
  const char str[] = "Hello, World!";
  char ch = 'o';
  ck_assert_ptr_eq(s21_memchr(str, ch, 13), memchr(str, ch, 13));
}
END_TEST

START_TEST(s21_memchr_2) {
  const char str[] = "Goodbye!";
  char ch = 'e';
  ck_assert_ptr_eq(s21_memchr(str, ch, 8), memchr(str, ch, 8));
}
END_TEST

START_TEST(s21_memchr_3) {
  const char str[] = "abcdefg";
  char ch = 'x';
  ck_assert_ptr_eq(s21_memchr(str, ch, 7), memchr(str, ch, 7));
}
END_TEST

START_TEST(s21_memchr_4) {
  const char str[] = "1234567890";
  char ch = '4';
  ck_assert_ptr_eq(s21_memchr(str, ch, 10), memchr(str, ch, 10));
}
END_TEST

START_TEST(s21_memchr_5) {
  const char str[] = "Hello, World!";
  char ch = 'H';
  ck_assert_ptr_eq(s21_memchr(str, ch, 13), memchr(str, ch, 13));
}
END_TEST

START_TEST(s21_memchr_6) {
  const char str[] = "";
  char ch = 'a';
  ck_assert_ptr_eq(s21_memchr(str, ch, 0), memchr(str, ch, 0));
}
END_TEST

START_TEST(s21_memchr_7) {
  const char str[] = "abcdef";
  char ch = 'a';
  ck_assert_ptr_eq(s21_memchr(str, ch, 6), memchr(str, ch, 6));
}
END_TEST

START_TEST(s21_memchr_8) {
  const char str[] = "Hello, World!";
  char ch = '!';
  ck_assert_ptr_eq(s21_memchr(str, ch, 13), memchr(str, ch, 13));
}
END_TEST

Suite *s21_memchr_test(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_memchr_1);
  tcase_add_test(tc, s21_memchr_2);
  tcase_add_test(tc, s21_memchr_3);
  tcase_add_test(tc, s21_memchr_4);
  tcase_add_test(tc, s21_memchr_5);
  tcase_add_test(tc, s21_memchr_6);
  tcase_add_test(tc, s21_memchr_7);
  tcase_add_test(tc, s21_memchr_8);
  suite_add_tcase(s, tc);
  return s;
}
