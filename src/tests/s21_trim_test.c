#include "test.h"

START_TEST(trim_1) {
  const char str[] = "   Hello, World!   ";
  const char trim_chars[] = " ";
  char *result = s21_trim(str, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(trim_2) {
  const char str[] = "***Hello, World!***";
  const char trim_chars[] = "*";
  char *result = s21_trim(str, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(trim_3) {
  const char str[] = "!!!Hello, World!!!";
  const char trim_chars[] = "!";
  char *result = s21_trim(str, trim_chars);
  ck_assert_str_eq(result, "Hello, World");
  free(result);
}
END_TEST

START_TEST(trim_4) {
  const char str[] = "   ";
  const char trim_chars[] = " ";
  char *result = s21_trim(str, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(trim_5) {
  const char str[] = "Hello, World!";
  const char trim_chars[] = "xyz";
  char *result = s21_trim(str, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");  // No change expected
  free(result);
}
END_TEST

START_TEST(trim_6) {
  char *result = s21_trim(S21_NULL, " ");
  ck_assert_ptr_eq(result, S21_NULL);  // Test for NULL source
}
END_TEST

START_TEST(trim_7) {
  const char str[] = "   Hello   ";
  const char trim_chars[] = " ";
  char *result = s21_trim(str, trim_chars);
  ck_assert_str_eq(result, "Hello");
  free(result);
}
END_TEST

Suite *s21_trim_test(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, trim_7);
  suite_add_tcase(s, tc);
  return s;
}
