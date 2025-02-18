#include "test.h"

START_TEST(s21_strncat_1) {
  char str1[100] = "Hello";
  char str2[100] = "Hello";
  const char src[] = " World!";

  strncat(str1, src, 6);
  s21_strncat(str2, src, 6);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncat_2) {
  char str3[100] = "Goodbye";
  char str4[100] = "Goodbye";
  const char src2[] = " Cruel World!";

  strncat(str3, src2, 10);
  s21_strncat(str4, src2, 10);

  ck_assert_str_eq(str3, str4);
}
END_TEST

START_TEST(s21_strncat_3) {
  char str5[100] = "Test";
  char str6[100] = "Test";
  const char src3[] = " String Concatenation";

  strncat(str5, src3, 80);
  s21_strncat(str6, src3, 80);

  ck_assert_str_eq(str5, str6);
}
END_TEST

Suite *s21_strncat_test(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("None");
  tcase_add_test(tc, s21_strncat_1);
  tcase_add_test(tc, s21_strncat_2);
  tcase_add_test(tc, s21_strncat_3);
  suite_add_tcase(s, tc);
  return s;
}
