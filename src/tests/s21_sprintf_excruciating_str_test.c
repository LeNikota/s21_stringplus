#include "test_runner.h"

struct StrTypes {
  char str[100];
  char ch;
};

typedef struct StrTypes StrTypes;

static int width[] = {0, 1, 10, 100, -1, -10, -100};
static int precision[] = {0, 1, 10, 100, -1};
static StrTypes str[] = {
    {"T", 'T'},
    {"t", 't'},
    {"The", '1'},
    {"Hello world", '='},
    {"This is a long text compared to the above ones. Am I right?", '&'},
};

static size_t str_count = sizeof(str) / sizeof(str[0]);
static size_t width_count = sizeof(width) / sizeof(width[0]);
static size_t precision_count = sizeof(precision) / sizeof(precision[0]);

// Defualt
START_TEST(test_string) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < str_count; i++) {
    count = sprintf(expected, "%s %c", str[i].str, str[i].ch);
    s21_count = s21_sprintf(buffer, "%s %c", str[i].str, str[i].ch);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Width (minus is tested too)
START_TEST(test_string_width) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < str_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%*s %*c", w, str[i].str, w, str[i].ch);
      s21_count = s21_sprintf(buffer, "%*s %*c", w, str[i].str, w, str[i].ch);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision
START_TEST(test_string_precision) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < str_count; i++) {
    for (size_t k = 0; k < precision_count; k++) {
      int p = precision[k];

      count = sprintf(expected, "%.*s %c", p, str[i].str, str[i].ch);
      s21_count = s21_sprintf(buffer, "%.*s %c", p, str[i].str, str[i].ch);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision AND Width
START_TEST(test_string_precision_AND_width) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < str_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      for (size_t k = 0; k < precision_count; k++) {
        int w = width[j];
        int p = precision[k];

        count = sprintf(expected, "%*.*s %*c", w, p, str[i].str, w, str[i].ch);
        s21_count =
            s21_sprintf(buffer, "%*.*s %*c", w, p, str[i].str, w, str[i].ch);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);
      }
    }
  }
}
END_TEST

Suite *s21_sprintf_excruciating_str_test(void) {
  Suite *s = suite_create("s21_sprintf_excruciating_str_test");
  TCase *tc_d = tcase_create("All");

  tcase_add_test(tc_d, test_string);
  tcase_add_test(tc_d, test_string_width);
  tcase_add_test(tc_d, test_string_precision);
  tcase_add_test(tc_d, test_string_precision_AND_width);

  suite_add_tcase(s, tc_d);

  return s;
}