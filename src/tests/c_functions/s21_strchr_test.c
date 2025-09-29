#include "../test_runner.h"

START_TEST(s21_strchr_1) {
  const char str[] = "Hello, World!";
  char *result = s21_strchr(str, 'o');
  char *expected = strchr(str, 'o');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strchr_2) {
  const char str[] = "Hello, World!";
  char *result = s21_strchr(str, 'H');
  char *expected = strchr(str, 'H');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strchr_3) {
  const char str[] = "Hello, World!";
  char *result = s21_strchr(str, '!');
  char *expected = strchr(str, '!');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strchr_4) {
  const char str[] = "Hello, World!";
  char *result = s21_strchr(str, 'l');
  char *expected = strchr(str, 'l');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strchr_5) {
  const char str[] = "Hello, World!";
  char *result = s21_strchr(str, 'x');
  char *expected = strchr(str, 'x');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strchr_6) {
  const char str[] = "";
  char *result = s21_strchr(str, 'a');
  char *expected = strchr(str, 'a');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_strchr_7) {
  const char str[] = "Hello, World!";
  char *result = s21_strchr(str, '\0');
  char *expected = strchr(str, '\0');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

/*
// START_TEST (s21_strchr_8) {
//     const char str[] = "Hello, World!";
//     char *result = s21_strchr(str, 'w');
//     char *expected = strchr(str, 'w');
//     ck_assert_ptr_eq(result, expected);
// } END_TEST
*/

Suite *s21_strchr_test(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_strchr_1);
  tcase_add_test(tc, s21_strchr_2);
  tcase_add_test(tc, s21_strchr_3);
  tcase_add_test(tc, s21_strchr_4);
  tcase_add_test(tc, s21_strchr_5);
  tcase_add_test(tc, s21_strchr_6);
  tcase_add_test(tc, s21_strchr_7);
  // tcase_add_test(tc, s21_strchr_8); // Закомментировано, если не нужно
  suite_add_tcase(s, tc);
  return s;
}
