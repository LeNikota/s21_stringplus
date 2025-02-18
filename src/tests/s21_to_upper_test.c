#include "test.h"

START_TEST(s21_to_upper_1) {
  const char str[] = "hello, world!";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_2) {
  const char str[] = "Hello, World!";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_3) {
  const char str[] = "12345";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_4) {
  const char str[] = "C programming";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "C PROGRAMMING");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_5) {
  const char str[] = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_6) {
  char *result = s21_to_upper(S21_NULL);
  ck_assert_ptr_eq(result, S21_NULL);  // Test for NULL input
}
END_TEST

START_TEST(s21_to_upper_7) {
  const char str[] = "Mixed CASE 123!";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "MIXED CASE 123!");
  free(result);
}
END_TEST

Suite *s21_to_upper_test(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, s21_to_upper_1);
  tcase_add_test(tc, s21_to_upper_2);
  tcase_add_test(tc, s21_to_upper_3);
  tcase_add_test(tc, s21_to_upper_4);
  tcase_add_test(tc, s21_to_upper_5);
  tcase_add_test(tc, s21_to_upper_6);
  tcase_add_test(tc, s21_to_upper_7);
  suite_add_tcase(s, tc);
  return s;
}
