#include "../s21_string.h"
#include "test.h"

START_TEST(s21_insert_1) {
  const char src[] = "Hello, World!";
  const char str[] = " Beautiful";
  char *result = s21_insert(src, str, 5);
  ck_assert_str_eq(result, "Hello Beautiful, World!");
  free(result);
}
END_TEST

START_TEST(s21_insert_2) {
  const char src[] = "Hello, World!";
  const char str[] = "Greetings ";
  char *result = s21_insert(src, str, 0);
  ck_assert_str_eq(result, "Greetings Hello, World!");
  free(result);
}
END_TEST

START_TEST(s21_insert_3) {
  const char src[] = "Hello, World!";
  const char str[] = "!!!";
  char *result = s21_insert(src, str, 13);
  ck_assert_str_eq(result, "Hello, World!!!!");
  free(result);
}
END_TEST

START_TEST(s21_insert_4) {
  const char src[] = "Hello, World!";
  const char str[] = "!!!";
  char *result = s21_insert(src, str, 14);
  ck_assert_ptr_eq(result, S21_NULL);  // Insertion index out of bounds
}
END_TEST

START_TEST(s21_insert_5) {
  const char src[] = "Hello, World!";
  char *result = s21_insert(src, S21_NULL, 5);
  ck_assert_ptr_eq(result, S21_NULL);  // Inserting NULL string
}
END_TEST

START_TEST(s21_insert_6) {
  char *result = s21_insert(S21_NULL, "test", 0);
  ck_assert_ptr_eq(result, S21_NULL);  // Source string is NULL
}
END_TEST

START_TEST(s21_insert_7) {
  const char src[] = "Hello!";
  const char str[] = " World";
  char *result = s21_insert(src, str, 5);
  ck_assert_str_eq(result, "Hello World!");
  free(result);
}
END_TEST

Suite *s21_insert_test(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_insert_1);
  tcase_add_test(tc, s21_insert_2);
  tcase_add_test(tc, s21_insert_3);
  tcase_add_test(tc, s21_insert_4);
  tcase_add_test(tc, s21_insert_5);
  tcase_add_test(tc, s21_insert_6);
  tcase_add_test(tc, s21_insert_7);
  suite_add_tcase(s, tc);
  return s;
}