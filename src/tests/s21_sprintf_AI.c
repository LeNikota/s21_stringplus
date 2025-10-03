#include "test_runner.h"

START_TEST(test_string_format_combinations) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test with zero values
  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%d %ld %lld %hd %hhd", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%d %ld %lld %hd %hhd", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with maximum values
  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%d %ld %lld %hd %hhd", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%d %ld %lld %hd %hhd", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with minimum values
  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%d %ld %lld %hd %hhd", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%d %ld %lld %hd %hhd", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_format_with_padding) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test with minimal padding
  int regular_int = 5;
  long long_int = 10L;
  long long long_long_int = 15LL;
  short short_int = 20;
  char char_int = 25;

  count = sprintf(expected, "%2d %3ld %4lld %2hd %2hhd", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%2d %3ld %4lld %2hd %2hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_char_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  char c = 'A';

  count = sprintf(expected, "%c", c);
  s21_count = s21_sprintf(buffer, "%c", c);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%5c", c);
  s21_count = s21_sprintf(buffer, "%5c", c);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-5c", c);
  s21_count = s21_sprintf(buffer, "%-5c", c);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  char str[] = "hello";

  count = sprintf(expected, "%s", str);
  s21_count = s21_sprintf(buffer, "%s", str);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags and width
  count = sprintf(expected, "%10s", str);
  s21_count = s21_sprintf(buffer, "%10s", str);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10s", str);
  s21_count = s21_sprintf(buffer, "%-10s", str);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.3s", str);
  s21_count = s21_sprintf(buffer, "%.3s", str);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_decimal_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  int num = 123;

  count = sprintf(expected, "%d", num);
  s21_count = s21_sprintf(buffer, "%d", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%+d", num);
  s21_count = s21_sprintf(buffer, "%+d", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "% d", num);
  s21_count = s21_sprintf(buffer, "% d", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%05d", num);
  s21_count = s21_sprintf(buffer, "%05d", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-5d", num);
  s21_count = s21_sprintf(buffer, "%-5d", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_integer_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  int num = -456;

  count = sprintf(expected, "%i", num);
  s21_count = s21_sprintf(buffer, "%i", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%+i", num);
  s21_count = s21_sprintf(buffer, "%+i", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_octal_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  int num = 255;

  count = sprintf(expected, "%o", num);
  s21_count = s21_sprintf(buffer, "%o", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with alternative flag
  count = sprintf(expected, "%#o", num);
  s21_count = s21_sprintf(buffer, "%#o", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%#08o", num);
  s21_count = s21_sprintf(buffer, "%#08o", num);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_float_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  double fnum = 3.14159;

  count = sprintf(expected, "%f", fnum);
  s21_count = s21_sprintf(buffer, "%f", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%+f", fnum);
  s21_count = s21_sprintf(buffer, "%+f", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%#f", fnum);
  s21_count = s21_sprintf(buffer, "%#f", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%08.2f", fnum);
  s21_count = s21_sprintf(buffer, "%08.2f", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.2f", fnum);
  s21_count = s21_sprintf(buffer, "%-10.2f", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_scientific_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  double fnum = 1234.567;

  count = sprintf(expected, "%e", fnum);
  s21_count = s21_sprintf(buffer, "%e", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%+e", fnum);
  s21_count = s21_sprintf(buffer, "%+e", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%#e", fnum);
  s21_count = s21_sprintf(buffer, "%#e", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%010.2e", fnum);
  s21_count = s21_sprintf(buffer, "%010.2e", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_scientific_uppercase_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  double fnum = 1234.567;

  count = sprintf(expected, "%E", fnum);
  s21_count = s21_sprintf(buffer, "%E", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%+E", fnum);
  s21_count = s21_sprintf(buffer, "%+E", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_general_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  double fnum = 3.14159;

  count = sprintf(expected, "%g", fnum);
  s21_count = s21_sprintf(buffer, "%g", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%#g", fnum);
  s21_count = s21_sprintf(buffer, "%#g", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%+g", fnum);
  s21_count = s21_sprintf(buffer, "%+g", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_general_uppercase_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  double fnum = 3.14159;

  count = sprintf(expected, "%G", fnum);
  s21_count = s21_sprintf(buffer, "%G", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with flags
  count = sprintf(expected, "%#G", fnum);
  s21_count = s21_sprintf(buffer, "%#G", fnum);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_pointer_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  int num = 42;
  int *ptr = &num;

  count = sprintf(expected, "%p", ptr);
  s21_count = s21_sprintf(buffer, "%p", ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with width
  count = sprintf(expected, "%15p", ptr);
  s21_count = s21_sprintf(buffer, "%15p", ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_count_specifier) {
  char buffer[100];
  char expected[100];
  int count, s21_count;
  int n1, n2;

  count = sprintf(expected, "test%n", &n1);
  s21_count = s21_sprintf(buffer, "test%n", &n2);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n1, 4);  // "test" is 4 characters

  // Test with multiple %n
  int n3, n4, n5, n6;
  count = sprintf(expected, "ab%n cd%n", &n3, &n4);
  s21_count = s21_sprintf(buffer, "ab%n cd%n", &n5, &n6);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
  ck_assert_int_eq(n3, n5);
  ck_assert_int_eq(n4, n6);
  ck_assert_int_eq(n3, 2);  // "ab" is 2 characters
  ck_assert_int_eq(n4, 5);  // "ab cd" is 5 characters
}

Suite *s21_sprintf_AI_test(void) {
  Suite *s = suite_create("s21_sprintf_AI");
  TCase *tc_d = tcase_create("d");

  tcase_add_test(tc_d, test_string_format_combinations);
  tcase_add_test(tc_d, test_string_format_with_padding);
  tcase_add_test(tc_d, test_char_specifier);
  tcase_add_test(tc_d, test_string_specifier);
  tcase_add_test(tc_d, test_decimal_specifier);
  tcase_add_test(tc_d, test_integer_specifier);
  tcase_add_test(tc_d, test_octal_specifier);
  tcase_add_test(tc_d, test_float_specifier);
  tcase_add_test(tc_d, test_scientific_specifier);
  tcase_add_test(tc_d, test_scientific_uppercase_specifier);
  tcase_add_test(tc_d, test_general_specifier);
  tcase_add_test(tc_d, test_general_uppercase_specifier);
  tcase_add_test(tc_d, test_pointer_specifier);
  tcase_add_test(tc_d, test_count_specifier);
  suite_add_tcase(s, tc_d);

  return s;
}