#include "test.h"

START_TEST(s21_strncmp_1) {
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_2) {
  const char str1[] = "Hello";
  const char str2[] = "World";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_3) {  // Исправлено: добавлен тест с номером 3
  const char str1[] = "Hello";
  const char str2[] = "Hello, World";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_4) {
  const char str1[] = "Hello, World";
  const char str2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_5) {
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_6) {
  const char str1[] = "Hello";
  const char str2[] = "Hell";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(s21_strncmp_7) {
  const char str1[] = "Hell";
  const char str2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(s21_strncmp_8) {
  const char str1[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char str2[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  ck_assert_int_eq(s21_strncmp(str1, str2, 65), strncmp(str1, str2, 65));
}
END_TEST

START_TEST(s21_strncmp_9) {
  const char str1[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char str2[] = "Lorem ipsum dolor sit amet, consectetur adipiscing.";
  ck_assert_int_eq(s21_strncmp(str1, str2, 65), strncmp(str1, str2, 65));
}
END_TEST

START_TEST(s21_strncmp_10) {
  const char str1[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char str2[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod "
      "tempor incididunt ut labore et dolore magna aliqua.";
  ck_assert_int_eq(s21_strncmp(str1, str2, 65), strncmp(str1, str2, 65));
}
END_TEST

START_TEST(s21_strncmp_11) {
  const char str1[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char str2[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut enim ad "
      "minim veniam.";
  ck_assert_int_eq(s21_strncmp(str1, str2, 65), strncmp(str1, str2, 65));
}
END_TEST

START_TEST(s21_strncmp_12) {
  const char str1[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char str2[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quis autem vel "
      "eum iure reprehenderit qui in ea voluptate velit esse.";
  ck_assert_int_eq(s21_strncmp(str1, str2, 65), strncmp(str1, str2, 65));
}
END_TEST

Suite *s21_strncmp_test(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc = tcase_create("Core");

  // Добавление тестов в тестовый случай
  tcase_add_test(tc, s21_strncmp_1);
  tcase_add_test(tc, s21_strncmp_2);
  tcase_add_test(tc, s21_strncmp_3);
  tcase_add_test(tc, s21_strncmp_4);
  tcase_add_test(tc, s21_strncmp_5);
  tcase_add_test(tc, s21_strncmp_6);
  tcase_add_test(tc, s21_strncmp_7);
  tcase_add_test(tc, s21_strncmp_8);
  tcase_add_test(tc, s21_strncmp_9);
  tcase_add_test(tc, s21_strncmp_10);
  tcase_add_test(tc, s21_strncmp_11);
  tcase_add_test(tc, s21_strncmp_12);

  // Добавление тестового случая в набор
  suite_add_tcase(s, tc);
  return s;
}
