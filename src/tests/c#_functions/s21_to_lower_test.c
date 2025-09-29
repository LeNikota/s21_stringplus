#include "../test_runner.h"

START_TEST(s21_to_lower_1) {
  const char str[] = "HELLO, WORLD!";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_2) {
  const char str[] = "Hello, World!";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_3) {
  const char str[] = "12345";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_4) {
  const char str[] = "C PROGRAMMING";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "c programming");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_5) {
  const char str[] = "";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_6) {
  char *result = s21_to_lower(S21_NULL);
  ck_assert_ptr_eq(result, S21_NULL);  // Test for NULL input
}
END_TEST

START_TEST(s21_to_lower_7) {
  const char str[] = "Mixed CASE 123!";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "mixed case 123!");
  free(result);
}
END_TEST

Suite *s21_to_lower_test(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, s21_to_lower_1);
  tcase_add_test(tc, s21_to_lower_2);
  tcase_add_test(tc, s21_to_lower_3);
  tcase_add_test(tc, s21_to_lower_4);
  tcase_add_test(tc, s21_to_lower_5);
  tcase_add_test(tc, s21_to_lower_6);
  tcase_add_test(tc, s21_to_lower_7);
  suite_add_tcase(s, tc);
  return s;
}
