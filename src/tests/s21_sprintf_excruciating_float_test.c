#include "test_runner.h"

struct FloatTypes {
  double d;
  long double ld;
};

typedef struct FloatTypes FloatTypes;

static int width[] = {0, 1, 10, 20, 100, -1, -10};
static int precision[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
                          11, 12, 13, 14, 15, 16, 17, 18, -1, -3};
static FloatTypes num[] = {{0.0, 0.0L},
                           {1.0, 1.0L},
                           {-1.0, -1.0L},

                           {12345678.0, 12345678.0L},
                           {-12345678.0, -12345678.0L},

                           {1234.567, 1234.567L},
                           {-1234.567, -1234.567L},

                           {1.234567e5, 1.234567e5L},
                           {-1.234567e5, -1.234567e5L},
                           {1.234567e-5, 1.234567e-5L},
                           {-1.234567e-5, -1.234567e-5L},

                           {1.234567e10, 1.234567e10L},
                           {-1.234567e10, -1.234567e10L},
                           {1.234567e-10, 1.234567e-10L},
                           {-1.234567e-10, -1.234567e-10L},

                           {1.234567e15, 1.234567e15L},
                           {-1.234567e15, -1.234567e15L},
                           {1.234567e-15, 1.234567e-15L},
                           {-1.234567e-15, -1.234567e-15L},

                           {1.234567e20, 1.234567e20L},
                           {-1.234567e20, -1.234567e20L},
                           {1.234567e-20, 1.234567e-20L},
                           {-1.234567e-20, -1.234567e-20L},

                           // Precision problems
                           //  {1.234567e25, 1.234567e25L},
                           //  {-1.234567e25, -1.234567e25L},
                           //  {1.234567e-25, 1.234567e-25L},
                           //  {-1.234567e-25, -1.234567e-25L},
                           //
                           //  {1.234567e30, 1.234567e30L},
                           //  {-1.234567e30, -1.234567e30L},
                           //  {1.234567e-30, 1.234567e-30L},
                           //  {-1.234567e-30, -1.234567e-30L},

                           {INFINITY, NAN},
                           {-INFINITY, NAN},
                           {NAN, NAN}};

static size_t num_count = sizeof(num) / sizeof(num[0]);
static size_t width_count = sizeof(width) / sizeof(width[0]);
static size_t precision_count = sizeof(precision) / sizeof(precision[0]);

START_TEST(test_float) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%f %Lf", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%f %Lf", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%e %Le", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%e %Le", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%g %Lg", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%g %Lg", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}
END_TEST

START_TEST(test_float_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%+f %+Lf", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%+f %+Lf", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%+e %+Le", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%+e %+Le", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%+g %+Lg", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%+g %+Lg", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}
END_TEST

START_TEST(test_float_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "% f % Lf", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "% f % Lf", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "% e % Le", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "% e % Le", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "% g % Lg", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "% g % Lg", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}
END_TEST

START_TEST(test_float_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%#f %#Lf", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%#f %#Lf", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%#e %#Le", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%#e %#Le", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%#g %#Lg", num[i].d, num[i].ld);
    s21_count = s21_sprintf(buffer, "%#g %#Lg", num[i].d, num[i].ld);

    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}
END_TEST

START_TEST(test_float_zero) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%0*f %0*Lf", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%0*f %0*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%0*e %0*Le", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%0*e %0*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%0*g %0*Lg", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%0*g %0*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_zero_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%+0*f %+0*Lf", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%+0*f %+0*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%+0*e %+0*Le", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%+0*e %+0*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%+0*g %+0*Lg", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%+0*g %+0*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_zero_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "% 0*f % 0*Lf", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "% 0*f % 0*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "% 0*e % 0*Le", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "% 0*e % 0*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "% 0*g % 0*Lg", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "% 0*g % 0*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_zero_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%#0*f %#0*Lf", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%#0*f %#0*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#0*e %#0*Le", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%#0*e %#0*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#0*g %#0*Lg", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%#0*g %#0*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_zero_AND_hash_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%+#0*f %+#0*Lf", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%+#0*f %+#0*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%+#0*e %+#0*Le", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%+#0*e %+#0*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%+#0*g %+#0*Lg", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "%+#0*g %+#0*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_zero_AND_hash_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "% #0*f % #0*Lf", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "% #0*f % #0*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "% #0*e % #0*Le", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "% #0*e % #0*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "% #0*g % #0*Lg", w, num[i].d, w, num[i].ld);
      s21_count =
          s21_sprintf(buffer, "% #0*g % #0*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_width) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%*f %*Lf", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%*f %*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*e %*Le", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%*e %*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*g %*Lg", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%*g %*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_precision) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t k = 0; k < precision_count; k++) {
      int p = precision[k];

      count = sprintf(expected, "%.*f %.*Lf", p, num[i].d, p, num[i].ld);
      s21_count = s21_sprintf(buffer, "%.*f %.*Lf", p, num[i].d, p, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%.*e %.*Le", p, num[i].d, p, num[i].ld);
      s21_count = s21_sprintf(buffer, "%.*e %.*Le", p, num[i].d, p, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%.*g %.*Lg", p, num[i].d, p, num[i].ld);
      s21_count = s21_sprintf(buffer, "%.*g %.*Lg", p, num[i].d, p, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_precision_AND_width) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      for (size_t k = 0; k < precision_count; k++) {
        int w = width[j];
        int p = precision[k];

        count =
            sprintf(expected, "%*.*lf %*.*Lf", w, p, num[i].d, w, p, num[i].ld);
        s21_count = s21_sprintf(buffer, "%*.*lf %*.*Lf", w, p, num[i].d, w, p,
                                num[i].ld);

        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count =
            sprintf(expected, "%*.*le %*.*Le", w, p, num[i].d, w, p, num[i].ld);
        s21_count = s21_sprintf(buffer, "%*.*le %*.*Le", w, p, num[i].d, w, p,
                                num[i].ld);

        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count =
            sprintf(expected, "%*.*lg %*.*Lg", w, p, num[i].d, w, p, num[i].ld);
        s21_count = s21_sprintf(buffer, "%*.*lg %*.*Lg", w, p, num[i].d, w, p,
                                num[i].ld);

        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);
      }
    }
  }
}
END_TEST

START_TEST(test_float_width_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%+*f %+*Lf", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%+*f %+*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%+*e %+*Le", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%+*e %+*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%+*g %+*Lg", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%+*g %+*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_width_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "% *f % *Lf", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "% *f % *Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "% *e % *Le", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "% *e % *Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "% *g % *Lg", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "% *g % *Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_width_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%#*f %#*Lf", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%#*f %#*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#*e %#*Le", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%#*e %#*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#*g %#*Lg", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%#*g %#*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

START_TEST(test_float_width_AND_zero) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%0*f %0*Lf", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%0*f %0*Lf", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%0*e %0*Le", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%0*e %0*Le", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%0*g %0*Lg", w, num[i].d, w, num[i].ld);
      s21_count = s21_sprintf(buffer, "%0*g %0*Lg", w, num[i].d, w, num[i].ld);

      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

Suite *s21_sprintf_excruciating_float_test(void) {
  Suite *s = suite_create("s21_sprintf_excruciating_float_test");
  TCase *tc_d = tcase_create("All");

  tcase_add_test(tc_d, test_float);
  tcase_add_test(tc_d, test_float_plus);
  tcase_add_test(tc_d, test_float_space);
  tcase_add_test(tc_d, test_float_hash);
  tcase_add_test(tc_d, test_float_zero);

  tcase_add_test(tc_d, test_float_zero_AND_plus);
  tcase_add_test(tc_d, test_float_zero_AND_space);
  tcase_add_test(tc_d, test_float_zero_AND_hash);

  tcase_add_test(tc_d, test_float_zero_AND_hash_AND_plus);
  tcase_add_test(tc_d, test_float_zero_AND_hash_AND_space);

  tcase_add_test(tc_d, test_float_width);
  tcase_add_test(tc_d, test_float_precision);
  tcase_add_test(tc_d, test_float_precision_AND_width);

  tcase_add_test(tc_d, test_float_width_AND_plus);
  tcase_add_test(tc_d, test_float_width_AND_space);
  tcase_add_test(tc_d, test_float_width_AND_hash);
  tcase_add_test(tc_d, test_float_width_AND_zero);

  // tcase_add_test(tc_d, test_float_precision_AND_plus);
  // tcase_add_test(tc_d, test_float_precision_AND_space);
  // tcase_add_test(tc_d, test_float_precision_AND_hash);

  // tcase_add_test(tc_d, test_float_width_AND_zero_AND_plus);
  // tcase_add_test(tc_d, test_float_width_AND_zero_AND_space);
  // tcase_add_test(tc_d, test_float_width_AND_zero_AND_hash);

  // tcase_add_test(tc_d, test_float_precision_AND_width_AND_plus);
  // tcase_add_test(tc_d, test_float_precision_AND_width_AND_space);
  // tcase_add_test(tc_d, test_float_precision_AND_width_AND_hash);

  suite_add_tcase(s, tc_d);

  return s;
}