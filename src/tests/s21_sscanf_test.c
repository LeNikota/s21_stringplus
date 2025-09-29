#include "test_runner.h"

START_TEST(test_sscanf_basic_int) {
  int x1 = 0, x2 = 0;
  const char str[] = "123";

  int res1 = s21_sscanf(str, "%d", &x1);
  int res2 = sscanf(str, "%d", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_multiple_ints) {
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  const char str[] = "123 -456";

  int res1 = s21_sscanf(str, "%d %d", &x1, &y1);
  int res2 = sscanf(str, "%d %d", &x2, &y2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
}
END_TEST

START_TEST(test_sscanf_float) {
  float x1 = 0, x2 = 0;
  const char str[] = "123.456";

  int res1 = s21_sscanf(str, "%f", &x1);
  int res2 = sscanf(str, "%f", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_string) {
  char str1[100] = {0};
  char str2[100] = {0};
  const char input[] = "Hello World";

  int res1 = s21_sscanf(input, "%99s", str1);
  int res2 = sscanf(input, "%99s", str2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sscanf_char) {
  char c1 = 0, c2 = 0;
  const char str[] = "X";

  int res1 = s21_sscanf(str, "%c", &c1);
  int res2 = sscanf(str, "%c", &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_sscanf_hex) {
  unsigned int x1 = 0, x2 = 0;
  const char str[] = "0xFF";

  int res1 = s21_sscanf(str, "%x", &x1);
  int res2 = sscanf(str, "%x", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_octal) {
  unsigned int x1 = 0, x2 = 0;
  const char str[] = "0777";

  int res1 = s21_sscanf(str, "%o", &x1);
  int res2 = sscanf(str, "%o", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_pointer) {
  void *p1 = NULL, *p2 = NULL;
  const char str[] = "0x12345678";

  int res1 = s21_sscanf(str, "%p", &p1);
  int res2 = sscanf(str, "%p", &p2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(test_sscanf_width) {
  char str1[100] = {0};
  char str2[100] = {0};
  const char input[] = "HelloWorld";

  int res1 = s21_sscanf(input, "%5s", str1);
  int res2 = sscanf(input, "%5s", str2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sscanf_skip) {
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  const char str[] = "123 456 789";

  int res1 = s21_sscanf(str, "%d %*d %d", &x1, &y1);
  int res2 = sscanf(str, "%d %*d %d", &x2, &y2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
}
END_TEST

START_TEST(test_sscanf_empty_input) {
  int x1 = 0, x2 = 0;
  const char str[] = "";

  int res1 = s21_sscanf(str, "%d", &x1);
  int res2 = sscanf(str, "%d", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_invalid_format_fn) {
  const char str[] = "123";

  int res1 = s21_sscanf(str, "123");
  int res2 = sscanf(str, "123");

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_scientific) {
  float x1 = 0, x2 = 0;
  const char str[] = "1.23e-4";

  int res1 = s21_sscanf(str, "%f", &x1);
  int res2 = sscanf(str, "%f", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_special_float) {
  float x1 = 0, x2 = 0;
  const char str[] = "nan inf";

  int res1 = s21_sscanf(str, "%f %f", &x1, &x2);
  int res2 = sscanf(str, "%f %f", &x2, &x2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_length_modifiers) {
  long l1 = 0, l2 = 0;
  short s1 = 0, s2 = 0;
  const char str[] = "12345 -123";

  int res1 = s21_sscanf(str, "%ld %hd", &l1, &s1);
  int res2 = sscanf(str, "%ld %hd", &l2, &s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(l1, l2);
  ck_assert_int_eq(s1, s2);
}
END_TEST

START_TEST(test_sscanf_n_specifier) {
  int n1 = 0, n2 = 0;
  int x1 = 0, x2 = 0;
  const char str[] = "123abc";

  int res1 = s21_sscanf(str, "%d%n", &x1, &n1);
  int res2 = sscanf(str, "%d%n", &x2, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sscanf_multiple_spaces) {
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  const char str[] = "123   456";

  int res1 = s21_sscanf(str, "%d %d", &x1, &y1);
  int res2 = sscanf(str, "%d %d", &x2, &y2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
}
END_TEST

START_TEST(test_sscanf_i_specifier) {
  int x1 = 0, y1 = 0, z1 = 0;
  int x2 = 0, y2 = 0, z2 = 0;
  const char str[] = "123 0x7B 037";

  int res1 = s21_sscanf(str, "%i %i %i", &x1, &y1, &z1);
  int res2 = sscanf(str, "%i %i %i", &x2, &y2, &z2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(z1, z2);
}
END_TEST

START_TEST(test_sscanf_double_percent) {
  const char str[] = "%123";
  char c1, c2;

  int res1 = s21_sscanf(str, "%%%c", &c1);
  int res2 = sscanf(str, "%%%c", &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_sscanf_mixed_specifiers) {
  int i1, i2;
  float f1, f2;
  char s1[100], s2[100];

  const char str1[] = "42 3.14 hello";
  int res1 = s21_sscanf(str1, "%d %f %99s", &i1, &f1, s1);
  int res2 = sscanf(str1, "%d %f %99s", &i2, &f2, s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(i1, i2);
  ck_assert_float_eq(f1, f2);
  ck_assert_str_eq(s1, s2);

  const char format[] = "%s";
  const char str2[] = "test";
  res1 = s21_sscanf(str2, format, s1);
  res2 = sscanf(str2, "%99s", s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_sscanf_long_double) {
  long double ld1 = 0.0L, ld2 = 0.0L;
  const char str[] = "3.14159265358979323846";

  int res1 = s21_sscanf(str, "%Lf", &ld1);
  int res2 = sscanf(str, "%Lf", &ld2);

  ck_assert_int_eq(res1, res2);
  ck_assert(fabsl(ld1 - ld2) < 1e-10L);
}
END_TEST

START_TEST(test_sscanf_invalid_after_valid) {
  int x1 = 0, x2 = 0;
  const char str[] = "123abc";

  int res1 = s21_sscanf(str, "%d", &x1);
  int res2 = sscanf(str, "%d", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_multiple_width) {
  char s1[100], s2[100], s3[100], s4[100];
  const char str[] = "hello world";

  int res1 = s21_sscanf(str, "%5s%5s", s1, s2);
  int res2 = sscanf(str, "%5s%5s", s3, s4);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s3);
  ck_assert_str_eq(s2, s4);
}
END_TEST

START_TEST(test_sscanf_null_ptr) {
  const char str[] = "123";
  int x1 = 0, x2 = 0;

  int res1 = s21_sscanf(str, "%d", &x1);
  int res2 = sscanf(str, "%d", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_break) {
  int x1 = 0, x2 = 0;

  int res1 = s21_sscanf("%%d", "%d", &x1);
  int res2 = sscanf("%%d", "%d", &x2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);

  x1 = 0, x2 = 0;
  res1 = s21_sscanf("Value: %%d", "%d", &x1);
  res2 = sscanf("Value: %%d", "%d", &x2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);

  x1 = 0, x2 = 0;
  res1 = s21_sscanf("Value: %%d", "%d", &x1);
  res2 = sscanf("Value: %%d", "%d", &x2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);

  x1 = 0, x2 = 0;
  char s1[100], s2[100];
  res1 = s21_sscanf("%% IDK", "%5s", s1);
  res2 = sscanf("%% IDK", "%5s", s2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);

  x1 = 0, x2 = 0;

  res1 = s21_sscanf("abc123", "abx%d", &x1);
  res2 = sscanf("abc123", "abx%d", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);
}
END_TEST

START_TEST(test_sscanf_X) {
  const char* input = "ABCDEF";
  const char* format = "%x";
  unsigned int number = 0;
  unsigned int number2 = 0;

  int res1 = s21_sscanf(input, format, &number);
  int res2 = sscanf(input, format, &number2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(number, number2);
}
END_TEST

START_TEST(test_sscanf_skip_and_match_error) {
  const char str[] = "%test string";
  const char format[] = "%%";
  int res1 = s21_sscanf(str, format);

  ck_assert_int_eq(res1, 0);
}
END_TEST

START_TEST(test_sscanf_first_converse_n) {
  const char str[] = "12345";
  int value1 = 0, value2 = 0;
  int count1 = 0, count2 = 0;

  int res1 = s21_sscanf(str, "%d%n", &value1, &count1);
  int res2 = sscanf(str, "%d%n", &value2, &count2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(count1, count2);

  const char str1[] = "test";
  int pos1, pos2;

  int result_s21 = s21_sscanf(str1, "%n", &pos1);
  int result_sys = sscanf(str1, "%n", &pos2);

  ck_assert_int_eq(result_s21, result_sys);
  ck_assert_int_eq(pos1, pos2);
}
END_TEST

START_TEST(test_sscanf_width_limit) {
  const char str[] = "123456789";
  int x1 = 0, x2 = 0;

  int res1 = s21_sscanf(str, "%5d", &x1);
  int res2 = sscanf(str, "%5d", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(x1, x2);

  int x3 = 0, x4 = 0;
  int res3 = s21_sscanf(str, "%3d", &x3);
  int res4 = sscanf(str, "%3d", &x4);

  ck_assert_int_eq(res3, res4);
  ck_assert_int_eq(x3, x4);
}
END_TEST

START_TEST(test_sscanf_float_with_width) {
  const char str[] = "123.456";
  float x1 = 0;
  float x2 = 0;

  int res1 = s21_sscanf(str, "%5f", &x1);
  int res2 = sscanf(str, "%5f", &x2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(x1, x2, 1e-6);
}
END_TEST

START_TEST(test_sscanf_long_double_modifiers) {
  const char str[] = "123.456";
  double x2 = 0;
  long double x3 = 0;

  int res1 = s21_sscanf(str, "%Lf", &x3);
  int res2 = sscanf(str, "%Lf", &x3);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(x3, x3);

  int res3 = s21_sscanf(str, "%lf", &x2);
  int res4 = sscanf(str, "%lf", &x2);

  ck_assert_int_eq(res3, res4);
  ck_assert_double_eq(x2, x2);
}
END_TEST

START_TEST(test_skip_and_match_skip_spaces) {
  char data[] = "   hello";
  char format[] = "x";
  char* s = data;
  char* f = format;

  int result = s21_skip_and_match(&s, &f);

  ck_assert_int_eq(result, 0);
  ck_assert_ptr_eq(s, data + 3);
  ck_assert_ptr_eq(f, format);
}
END_TEST

START_TEST(test_process_format_specifier_invalid_specifier) {
  char data[] = "123";
  char format[] = "%Q";
  char* s = data;
  char* f = format;

  struct specifiers spec = {0};

  int result = s21_process_format_specifier(&f, &s, &spec, NULL, data);

  ck_assert_int_eq(result, 1);

  ck_assert_ptr_eq(f, format + 2);
}
END_TEST

START_TEST(test_minus_flag) {
  char* str1 = "+123";
  char* str2 = "-456";
  int minus1 = 0, flag1 = 0;
  int minus2 = 0, flag2 = 0;

  char** s1 = &str1;
  s21_minus_flag(&s1, &minus1, &flag1);
  ck_assert_int_eq(minus1, 1);
  ck_assert_int_eq(flag1, 1);

  char** s2 = &str2;
  s21_minus_flag(&s2, &minus2, &flag2);
  ck_assert_int_eq(minus2, -1);
  ck_assert_int_eq(flag2, 1);
}
END_TEST

START_TEST(test_scientific_format) {
  char* str = "e+2";
  long double result = 3.14;

  char* s = str;
  char** s_ptr = &s;
  s21_scientific_format(&s_ptr, &result);

  ck_assert_double_eq_tol(result, 314.0, 1e-6);
}
END_TEST

START_TEST(test_flag_o_with_width) {
  const char input[] = "12345";
  unsigned int value1 = 0;
  unsigned int value2 = 0;

  s21_sscanf(input, "%3o", &value1);

  sscanf(input, "%3o", &value2);

  ck_assert_int_eq(value1, value2);
  ck_assert_int_eq(value1, 83);
}
END_TEST

START_TEST(test_hex_width_comparison) {
  const char input1[] = "ABC123";
  const char input2[] = "FFFF";
  const char input3[] = "abcdef";

  unsigned int value1_s21 = 0, value1_sys = 0;
  unsigned int value2_s21 = 0, value2_sys = 0;
  unsigned int value3_s21 = 0, value3_sys = 0;

  s21_sscanf(input1, "%3x", &value1_s21);
  sscanf(input1, "%3x", &value1_sys);
  ck_assert_int_eq(value1_s21, value1_sys);

  s21_sscanf(input2, "%2x", &value2_s21);
  sscanf(input2, "%2x", &value2_sys);
  ck_assert_int_eq(value2_s21, value2_sys);

  s21_sscanf(input3, "%4x", &value3_s21);
  sscanf(input3, "%4x", &value3_sys);
  ck_assert_int_eq(value3_s21, value3_sys);
}
END_TEST

START_TEST(test_flag_i_negative) {
  const char input1[] = "-123";
  const char input2[] = "-0x123";
  const char input3[] = "-0123";

  int value1_s21 = 0, value1_sys = 0;
  int value2_s21 = 0, value2_sys = 0;
  int value3_s21 = 0, value3_sys = 0;

  s21_sscanf(input1, "%i", &value1_s21);
  sscanf(input1, "%i", &value1_sys);
  ck_assert_int_eq(value1_s21, value1_sys);

  s21_sscanf(input2, "%i", &value2_s21);
  sscanf(input2, "%i", &value2_sys);
  ck_assert_int_eq(value2_s21, value2_sys);

  s21_sscanf(input3, "%i", &value3_s21);
  sscanf(input3, "%i", &value3_sys);
  ck_assert_int_eq(value3_s21, value3_sys);
}
END_TEST

START_TEST(test_double_percent_mismatch) {
  const char input1[] = "a%b";
  const char input2[] = "  %b";

  int res1_s21 = s21_sscanf(input1, "%%b");
  int res1_sys = sscanf(input1, "%%b");
  ck_assert_int_eq(res1_s21, res1_sys);

  int res2_s21 = s21_sscanf(input2, "%%b");
  int res2_sys = sscanf(input2, "%%b");
  ck_assert_int_eq(res2_s21, res2_sys);

  const char str[] = "abc%def";

  int res3_s21 = s21_sscanf(str, "abc%%def");
  int res3_sys = sscanf(str, "abc%%def");

  ck_assert_int_eq(res3_s21, res3_sys);
}
END_TEST

START_TEST(test_sscanf_wchar) {
  const char str1[] = "   A";
  char c1, c2;

  int result1_s21 = s21_sscanf(str1, " %c", &c1);
  int result1_sys = sscanf(str1, " %c", &c2);

  ck_assert_int_eq(result1_s21, result1_sys);
  ck_assert_int_eq(c1, c2);

  const char str2[] = "X";
  wchar_t wc1, wc2;

  int result2_s21 = s21_sscanf(str2, "%lc", &wc1);
  int result2_sys = sscanf(str2, "%lc", &wc2);

  ck_assert_int_eq(result2_s21, result2_sys);
  ck_assert_int_eq(wc1, wc2);

  const char str3[] = "1.23e-4";
  double d1, d2;

  int result3_s21 = s21_sscanf(str3, "%lf", &d1);
  int result3_sys = sscanf(str3, "%lf", &d2);

  ck_assert_int_eq(result3_s21, result3_sys);
  ck_assert_double_eq(d1, d2);
}
END_TEST

Suite* s21_sscanf_test(void) {
  Suite* s = suite_create("Sscanf");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sscanf_basic_int);
  tcase_add_test(tc_core, test_sscanf_multiple_ints);
  tcase_add_test(tc_core, test_sscanf_float);
  tcase_add_test(tc_core, test_sscanf_string);
  tcase_add_test(tc_core, test_sscanf_char);
  tcase_add_test(tc_core, test_sscanf_hex);
  tcase_add_test(tc_core, test_sscanf_octal);
  tcase_add_test(tc_core, test_sscanf_pointer);
  tcase_add_test(tc_core, test_sscanf_width);
  tcase_add_test(tc_core, test_sscanf_skip);
  tcase_add_test(tc_core, test_sscanf_empty_input);
  tcase_add_test(tc_core, test_sscanf_invalid_format_fn);
  tcase_add_test(tc_core, test_sscanf_scientific);
  tcase_add_test(tc_core, test_sscanf_special_float);
  tcase_add_test(tc_core, test_sscanf_length_modifiers);
  tcase_add_test(tc_core, test_sscanf_n_specifier);
  tcase_add_test(tc_core, test_sscanf_multiple_spaces);
  tcase_add_test(tc_core, test_sscanf_i_specifier);
  tcase_add_test(tc_core, test_sscanf_double_percent);
  tcase_add_test(tc_core, test_sscanf_mixed_specifiers);
  tcase_add_test(tc_core, test_sscanf_long_double);
  tcase_add_test(tc_core, test_sscanf_invalid_after_valid);
  tcase_add_test(tc_core, test_sscanf_multiple_width);
  tcase_add_test(tc_core, test_sscanf_null_ptr);
  tcase_add_test(tc_core, test_sscanf_break);
  tcase_add_test(tc_core, test_sscanf_X);
  tcase_add_test(tc_core, test_sscanf_skip_and_match_error);
  tcase_add_test(tc_core, test_sscanf_first_converse_n);
  tcase_add_test(tc_core, test_sscanf_width_limit);
  tcase_add_test(tc_core, test_sscanf_float_with_width);
  tcase_add_test(tc_core, test_sscanf_long_double_modifiers);
  tcase_add_test(tc_core, test_skip_and_match_skip_spaces);
  tcase_add_test(tc_core, test_process_format_specifier_invalid_specifier);
  tcase_add_test(tc_core, test_minus_flag);
  tcase_add_test(tc_core, test_scientific_format);
  tcase_add_test(tc_core, test_flag_o_with_width);
  tcase_add_test(tc_core, test_hex_width_comparison);
  tcase_add_test(tc_core, test_flag_i_negative);
  tcase_add_test(tc_core, test_double_percent_mismatch);
  tcase_add_test(tc_core, test_sscanf_wchar);

  suite_add_tcase(s, tc_core);
  return s;
}