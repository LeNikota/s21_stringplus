#include "../test_runner.h"

START_TEST(s21_strstr_1) {
  const char str[] = "Hello, World!";
  const char substr[] = "World";
  ck_assert_str_eq(s21_strstr(str, substr), strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_2) {
  const char str[] = "Hello, World!";
  const char substr[] = "Hello";
  ck_assert_str_eq(s21_strstr(str, substr), strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_3) {
  const char str[] = "Hello, World!";
  const char substr[] = "!";
  ck_assert_str_eq(s21_strstr(str, substr), strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_4) {
  const char str[] = "Hello, World!";
  const char substr[] = "lo";
  ck_assert_str_eq(s21_strstr(str, substr), strstr(str, substr));
}
END_TEST

START_TEST(s21_strstr_5) {
  const char str[] = "Hello, World!";
  const char substr[] = "Goodbye";
  ck_assert_ptr_eq(s21_strstr(str, substr),
                   strstr(str, substr));  // Should return NULL
}
END_TEST

START_TEST(s21_strstr_6) {
  const char str[] = "Hello, World!";
  const char substr[] = "";
  ck_assert_str_eq(s21_strstr(str, substr),
                   strstr(str, substr));  // Empty substring
}
END_TEST

START_TEST(s21_strstr_7) {
  const char str[] = "";
  const char substr[] = "Hello";
  ck_assert_ptr_eq(s21_strstr(str, substr),
                   strstr(str, substr));  // Non-empty substring in empty string
}
END_TEST

START_TEST(s21_strstr_8) {
  const char str[] = "";
  const char substr[] = "";
  ck_assert_str_eq(s21_strstr(str, substr),
                   strstr(str, substr));  // Both are empty
}
END_TEST

Suite *s21_strstr_test(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, s21_strstr_1);
  tcase_add_test(tc, s21_strstr_2);
  tcase_add_test(tc, s21_strstr_3);
  tcase_add_test(tc, s21_strstr_4);
  tcase_add_test(tc, s21_strstr_5);
  tcase_add_test(tc, s21_strstr_6);
  tcase_add_test(tc, s21_strstr_7);
  tcase_add_test(tc, s21_strstr_8);

  suite_add_tcase(s, tc);
  return s;
}
