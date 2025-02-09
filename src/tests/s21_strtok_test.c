#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "test.h"

START_TEST(s21_strtok_1) {
  char str[] = "Hello, World! This is a test.";
  const char *delim =
      " ,.!";  // Delimiters are space, comma, period, and exclamation mark
  char *token = s21_strtok(str, delim);

  ck_assert_str_eq(token, "Hello");  // First token should be "Hello"
}
END_TEST

START_TEST(s21_strtok_2) {
  char str[] = "Hello, World! This is a test.";
  const char *delim = " ,.!";
  s21_strtok(str, delim);  // Get first token
  char *token = s21_strtok(NULL, delim);

  ck_assert_str_eq(token, "World");  // Second token should be "World"
}
END_TEST

START_TEST(s21_strtok_3) {
  char str[] = "Hello, World! This is a test.";
  const char *delim = " ,.!";
  s21_strtok(str, delim);   // Get first token
  s21_strtok(NULL, delim);  // Get second token
  char *token = s21_strtok(NULL, delim);

  ck_assert_str_eq(token, "This");  // Third token should be "This"
}
END_TEST

START_TEST(s21_strtok_4) {
  char str[] = "Hello, World! This is a test.";
  const char *delim = " ,.!";
  s21_strtok(str, delim);   // Get first token
  s21_strtok(NULL, delim);  // Get second token
  s21_strtok(NULL, delim);  // Get third token
  char *token = s21_strtok(NULL, delim);

  ck_assert_str_eq(token, "is");  // Fourth token should be "is"
}
END_TEST

START_TEST(s21_strtok_5) {
  char str[] = "Hello, World! This is a test.";
  const char *delim = " ,.!";
  s21_strtok(str, delim);   // Get first token
  s21_strtok(NULL, delim);  // Get second token
  s21_strtok(NULL, delim);  // Get third token
  s21_strtok(NULL, delim);  // Get fourth token
  char *token = s21_strtok(NULL, delim);

  ck_assert_str_eq(token, "a");  // Fifth token should be "a"
}
END_TEST

START_TEST(s21_strtok_6) {
  char str[] = "Hello, World! This is a test.";
  const char *delim = " ,.!";
  s21_strtok(str, delim);   // Get first token
  s21_strtok(NULL, delim);  // Get second token
  s21_strtok(NULL, delim);  // Get third token
  s21_strtok(NULL, delim);  // Get fourth token
  s21_strtok(NULL, delim);  // Get fifth token
  char *token = s21_strtok(NULL, delim);

  ck_assert_str_eq(token, "test");  // Sixth token should be "test"
}
END_TEST

START_TEST(s21_strtok_7) {
  char str[] = "Hello, World! This is a test.";
  const char *delim = " ,.!";
  s21_strtok(str, delim);   // Get first token
  s21_strtok(NULL, delim);  // Get second token
  s21_strtok(NULL, delim);  // Get third token
  s21_strtok(NULL, delim);  // Get fourth token
  s21_strtok(NULL, delim);  // Get fifth token
  s21_strtok(NULL, delim);  // Get sixth token
  char *token = s21_strtok(NULL, delim);

  ck_assert_ptr_eq(token, NULL);  // No more tokens should return NULL
}
END_TEST

START_TEST(s21_strtok_8) {
  char str[] = "   Leading spaces";
  const char *delim = " ";
  char *token = s21_strtok(str, delim);

  ck_assert_str_eq(token, "Leading");  // First token should be "Leading"
}
END_TEST

START_TEST(s21_strtok_9) {
  char str[] = "Trailing spaces   ";
  const char *delim = " ";
  char *token = s21_strtok(str, delim);

  ck_assert_str_eq(token, "Trailing");  // First token should be "Trailing"
}
END_TEST

START_TEST(s21_strtok_10) {
  char str[] = "Multiple   spaces";
  const char *delim = " ";
  char *token = s21_strtok(str, delim);

  ck_assert_str_eq(token, "Multiple");  // First token should be "Multiple"
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "spaces");  // Second token should be "spaces"
}
END_TEST

Suite *s21_strtok_test(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, s21_strtok_1);
  tcase_add_test(tc, s21_strtok_2);
  tcase_add_test(tc, s21_strtok_3);
  tcase_add_test(tc, s21_strtok_4);
  tcase_add_test(tc, s21_strtok_5);
  tcase_add_test(tc, s21_strtok_6);
  tcase_add_test(tc, s21_strtok_7);
  tcase_add_test(tc, s21_strtok_8);
  tcase_add_test(tc, s21_strtok_9);
  tcase_add_test(tc, s21_strtok_10);
  suite_add_tcase(s, tc);
  return s;
}