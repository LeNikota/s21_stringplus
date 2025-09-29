#include "../test_runner.h"

START_TEST(s21_memcpy_1) {
  char src[] = "Hello, World!";
  char dest[20] = {0};
  ck_assert_str_eq(s21_memcpy(dest, src, 13), memcpy(dest, src, 13));
}
END_TEST

START_TEST(s21_memcpy_2) {
  char src[] = "Goodbye!";
  char dest[20] = {0};
  ck_assert_str_eq(s21_memcpy(dest, src, 8), memcpy(dest, src, 8));
}
END_TEST

START_TEST(s21_memcpy_3) {
  char src[] = "abcdefg";
  char dest[20] = {0};
  ck_assert_str_eq(s21_memcpy(dest, src, 7), memcpy(dest, src, 7));
}
END_TEST

START_TEST(s21_memcpy_4) {
  char src[] = "1234567890";
  char dest[20] = {0};
  ck_assert_str_eq(s21_memcpy(dest, src, 10), memcpy(dest, src, 10));
}
END_TEST

START_TEST(s21_memcpy_5) {
  char src[] = "Hello, World!";
  char dest[20] = {0};
  s21_memcpy(dest, src, 13);
  ck_assert_int_eq(dest[12], '!');
}
END_TEST

START_TEST(s21_memcpy_6) {
  char src[] = "";
  char dest[20] = {0};
  ck_assert_str_eq(s21_memcpy(dest, src, 0), memcpy(dest, src, 0));
}
END_TEST

START_TEST(s21_memcpy_7) {
  char src[] = "abcdef";
  char dest[20] = {0};
  s21_memcpy(dest, src, 6);
  ck_assert_int_eq(dest[0], 'a');
}
END_TEST

START_TEST(s21_memcpy_8) {
  char src[] = "Hello, World!";
  char dest[20] = {0};
  s21_memcpy(dest, src, 14);
  ck_assert_str_eq(dest, src);
}
END_TEST

Suite *s21_memcpy_test(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_memcpy_1);
  tcase_add_test(tc, s21_memcpy_2);
  tcase_add_test(tc, s21_memcpy_3);
  tcase_add_test(tc, s21_memcpy_4);
  tcase_add_test(tc, s21_memcpy_5);
  tcase_add_test(tc, s21_memcpy_6);
  tcase_add_test(tc, s21_memcpy_7);
  tcase_add_test(tc, s21_memcpy_8);
  suite_add_tcase(s, tc);
  return s;
}
