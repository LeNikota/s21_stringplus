#include "test_runner.h"

// If debugging is needed, use something like:
// if (strcmp(expected, buffer)) {
//   printf("expected: %s\nbuffer: %s\np:%i\n\n", expected, buffer, p);
// }

struct IntTypes {
  int i;
  long li;
  long long lli;
  short hi;
  char hhi;
};

typedef struct IntTypes IntTypes;

static int width[] = {0, 1, 10, 100, -1, -10, -100};
static int precision[] = {0, 1, 10, 100, -1, -3, -10};
static IntTypes num[] = {{0, 0L, 0LL, 0, 0},
                         {INT_MAX, LONG_MAX, LLONG_MAX, SHRT_MAX, CHAR_MAX},
                         {INT_MIN, LONG_MIN, LLONG_MIN, SHRT_MIN, CHAR_MIN}};

static size_t num_count = sizeof(num) / sizeof(num[0]);
static size_t width_count = sizeof(width) / sizeof(width[0]);
static size_t precision_count = sizeof(precision) / sizeof(precision[0]);

// Experimental
// START_TEST(test_number) {
//   char buffer[5000];
//   char expected[5000];
//   int count, s21_count;
//
//   char format[100];
//   char specifier[] = "dioxXu";
//   for (size_t i = 0; specifier[i]; i++) {
//     for (size_t j = 0; (num + j); j++) {
//       for (size_t i = 0; specifier[i]; i++) {
//         sprintf(format, "%%%c %%l%c %%ll%c %%h%c %%hh%c", specifier[i],
//                 specifier[i], specifier[i], specifier[i], specifier[i]);
//
//         count = sprintf(expected, format, num[j].i, num[j].li, num[j].lli,
//                         num[j].hi, num[j].hhi);
//         s21_count = s21_sprintf(buffer, format, num[j].i, num[j].li,
//         num[j].lli,
//                                 num[j].hi, num[j].hhi);
//
//         if (strcmp(expected, buffer)) printf("%s\n", format);
//         if (count != s21_count)
//           printf("count != s21_count: %i != %i\n\n", count, s21_count);
//
//         ck_assert_str_eq(buffer, expected);
//         ck_assert_int_eq(count, s21_count);
//       }
//     }
//   }
// }

// Defualt
START_TEST(test_number) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%d %ld %lld %hd %hhd", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%d %ld %lld %hd %hhd", num[i].i, num[i].li,
                            num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%i %li %lli %hi %hhi", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%i %li %lli %hi %hhi", num[i].i, num[i].li,
                            num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%o %lo %llo %ho %hho", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%o %lo %llo %ho %hho", num[i].i, num[i].li,
                            num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%x %lx %llx %hx %hhx", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%x %lx %llx %hx %hhx", num[i].i, num[i].li,
                            num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%X %lX %llX %hX %hhX", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%X %lX %llX %hX %hhX", num[i].i, num[i].li,
                            num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%u %lu %llu %hu %hhu", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%u %lu %llu %hu %hhu", num[i].i, num[i].li,
                            num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Plus
START_TEST(test_number_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%+d %+ld %+lld %+hd %+hhd", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%+d %+ld %+lld %+hd %+hhd", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%+i %+li %+lli %+hi %+hhi", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%+i %+li %+lli %+hi %+hhi", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Space
START_TEST(test_number_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "% d % ld % lld % hd % hhd", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "% d % ld % lld % hd % hhd", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "% i % li % lli % hi % hhi", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "% i % li % lli % hi % hhi", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Hash
START_TEST(test_number_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%#o %#lo %#llo %#ho %#hho", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%#o %#lo %#llo %#ho %#hho", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%#x %#lx %#llx %#hx %#hhx", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%#x %#lx %#llx %#hx %#hhx", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%#X %#lX %#llX %#hX %#hhX", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%#X %#lX %#llX %#hX %#hhX", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Zero
START_TEST(test_number_zero) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%0d %0ld %0lld %0hd %0hhd", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%0d %0ld %0lld %0hd %0hhd", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%0i %0li %0lli %0hi %0hhi", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%0i %0li %0lli %0hi %0hhi", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%0o %0lo %0llo %0ho %0hho", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%0o %0lo %0llo %0ho %0hho", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%0x %0lx %0llx %0hx %0hhx", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%0x %0lx %0llx %0hx %0hhx", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%0X %0lX %0llX %0hX %0hhX", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%0X %0lX %0llX %0hX %0hhX", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%0u %0lu %0llu %0hu %0hhu", num[i].i, num[i].li,
                    num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%0u %0lu %0llu %0hu %0hhu", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Zero AND Plus
START_TEST(test_number_zero_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%+0d %+0ld %+0lld %+0hd %+0hhd", num[i].i,
                    num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%+0d %+0ld %+0lld %+0hd %+0hhd", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%+0i %+0li %+0lli %+0hi %+0hhi", num[i].i,
                    num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%+0i %+0li %+0lli %+0hi %+0hhi", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Zero AND Space
START_TEST(test_number_zero_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "% 0d % 0ld % 0lld % 0hd % 0hhd", num[i].i,
                    num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "% 0d % 0ld % 0lld % 0hd % 0hhd", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "% 0i % 0li % 0lli % 0hi % 0hhi", num[i].i,
                    num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "% 0i % 0li % 0lli % 0hi % 0hhi", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Zero AND Hash
START_TEST(test_number_zero_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    count = sprintf(expected, "%#0o %#0lo %#0llo %#0ho %#0hho", num[i].i,
                    num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%#0o %#0lo %#0llo %#0ho %#0hho", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%#0x %#0lx %#0llx %#0hx %#0hhx", num[i].i,
                    num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%#0x %#0lx %#0llx %#0hx %#0hhx", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%#0X %#0lX %#0llX %#0hX %#0hhX", num[i].i,
                    num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    s21_count = s21_sprintf(buffer, "%#0X %#0lX %#0llX %#0hX %#0hhX", num[i].i,
                            num[i].li, num[i].lli, num[i].hi, num[i].hhi);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Width (minus is tested too)
START_TEST(test_number_width) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%*d %*ld %*lld %*hd %*hhd", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%*d %*ld %*lld %*hd %*hhd", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*o %*lo %*llo %*ho %*hho", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%*o %*lo %*llo %*ho %*hho", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*x %*lx %*llx %*hx %*hhx", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%*x %*lx %*llx %*hx %*hhx", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*X %*lX %*llX %*hX %*hhX", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%*X %*lX %*llX %*hX %*hhX", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*u %*lu %*llu %*hu %*hhu", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%*u %*lu %*llu %*hu %*hhu", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision
START_TEST(test_number_precision) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t k = 0; k < precision_count; k++) {
      int p = precision[k];

      count = sprintf(expected, "%.*d %.*ld %.*lld %.*hd %.*hhd", p, num[i].i,
                      p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%.*d %.*ld %.*lld %.*hd %.*hhd", p, num[i].i, p,
                      num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%.*o %.*lo %.*llo %.*ho %.*hho", p, num[i].i,
                      p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%.*o %.*lo %.*llo %.*ho %.*hho", p, num[i].i, p,
                      num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%.*x %.*lx %.*llx %.*hx %.*hhx", p, num[i].i,
                      p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%.*x %.*lx %.*llx %.*hx %.*hhx", p, num[i].i, p,
                      num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%.*X %.*lX %.*llX %.*hX %.*hhX", p, num[i].i,
                      p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%.*X %.*lX %.*llX %.*hX %.*hhX", p, num[i].i, p,
                      num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%.*u %.*lu %.*llu %.*hu %.*hhu", p, num[i].i,
                      p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%.*u %.*lu %.*llu %.*hu %.*hhu", p, num[i].i, p,
                      num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision AND Width
START_TEST(test_number_precision_AND_width) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      for (size_t k = 0; k < precision_count; k++) {
        int w = width[j];
        int p = precision[k];

        count = sprintf(expected, "%*.*d %*.*ld %*.*lld %*.*hd %*.*hhd", w, p,
                        num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%*.*d %*.*ld %*.*lld %*.*hd %*.*hhd",
                                w, p, num[i].i, w, p, num[i].li, w, p,
                                num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count = sprintf(expected, "%*.*o %*.*lo %*.*llo %*.*ho %*.*hho", w, p,
                        num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%*.*o %*.*lo %*.*llo %*.*ho %*.*hho",
                                w, p, num[i].i, w, p, num[i].li, w, p,
                                num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count = sprintf(expected, "%*.*x %*.*lx %*.*llx %*.*hx %*.*hhx", w, p,
                        num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%*.*x %*.*lx %*.*llx %*.*hx %*.*hhx",
                                w, p, num[i].i, w, p, num[i].li, w, p,
                                num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count = sprintf(expected, "%*.*X %*.*lX %*.*llX %*.*hX %*.*hhX", w, p,
                        num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%*.*X %*.*lX %*.*llX %*.*hX %*.*hhX",
                                w, p, num[i].i, w, p, num[i].li, w, p,
                                num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count = sprintf(expected, "%*.*u %*.*lu %*.*llu %*.*hu %*.*hhu", w, p,
                        num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%*.*u %*.*lu %*.*llu %*.*hu %*.*hhu",
                                w, p, num[i].i, w, p, num[i].li, w, p,
                                num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);
      }
    }
  }
}
END_TEST

// Width AND Plus
START_TEST(test_number_width_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%+*d %+*ld %+*lld %+*hd %+*hhd", w, num[i].i,
                      w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%+*d %+*ld %+*lld %+*hd %+*hhd", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Width AND Space
START_TEST(test_number_width_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "% *d % *ld % *lld % *hd % *hhd", w, num[i].i,
                      w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "% *d % *ld % *lld % *hd % *hhd", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Width AND Hash
START_TEST(test_number_width_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count = sprintf(expected, "%#*o %#*lo %#*llo %#*ho %#*hho", w, num[i].i,
                      w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%#*o %#*lo %#*llo %#*ho %#*hho", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#*x %#*lx %#*llx %#*hx %#*hhx", w, num[i].i,
                      w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%#*x %#*lx %#*llx %#*hx %#*hhx", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#*X %#*lX %#*llX %#*hX %#*hhX", w, num[i].i,
                      w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count =
          s21_sprintf(buffer, "%#*X %#*lX %#*llX %#*hX %#*hhX", w, num[i].i, w,
                      num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Width AND Zero
START_TEST(test_number_width_AND_zero) {
  {
    char buffer[5000];
    char expected[5000];
    int count, s21_count;

    for (size_t i = 0; i < num_count; i++) {
      for (size_t j = 0; j < width_count; j++) {
        int w = width[j];

        count =
            sprintf(expected, "%0*d %0*ld %0*lld %0*hd %0*hhd", w, num[i].i, w,
                    num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%0*d %0*ld %0*lld %0*hd %0*hhd", w,
                                num[i].i, w, num[i].li, w, num[i].lli, w,
                                num[i].hi, w, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count =
            sprintf(expected, "%0*o %0*lo %0*llo %0*ho %0*hho", w, num[i].i, w,
                    num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%0*o %0*lo %0*llo %0*ho %0*hho", w,
                                num[i].i, w, num[i].li, w, num[i].lli, w,
                                num[i].hi, w, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count =
            sprintf(expected, "%0*x %0*lx %0*llx %0*hx %0*hhx", w, num[i].i, w,
                    num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%0*x %0*lx %0*llx %0*hx %0*hhx", w,
                                num[i].i, w, num[i].li, w, num[i].lli, w,
                                num[i].hi, w, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count =
            sprintf(expected, "%0*X %0*lX %0*llX %0*hX %0*hhX", w, num[i].i, w,
                    num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%0*X %0*lX %0*llX %0*hX %0*hhX", w,
                                num[i].i, w, num[i].li, w, num[i].lli, w,
                                num[i].hi, w, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count =
            sprintf(expected, "%0*u %0*lu %0*llu %0*hu %0*hhu", w, num[i].i, w,
                    num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
        s21_count = s21_sprintf(buffer, "%0*u %0*lu %0*llu %0*hu %0*hhu", w,
                                num[i].i, w, num[i].li, w, num[i].lli, w,
                                num[i].hi, w, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);
      }
    }
  }
}
END_TEST

// Precision AND Plus
START_TEST(test_number_precision_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t k = 0; k < precision_count; k++) {
      int p = precision[k];

      count =
          sprintf(expected, "%+.*d %+.*ld %+.*lld %+.*hd %+.*hhd", p, num[i].i,
                  p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%+.*d %+.*ld %+.*lld %+.*hd %+.*hhd", p,
                              num[i].i, p, num[i].li, p, num[i].lli, p,
                              num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision AND Space
START_TEST(test_number_precision_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t k = 0; k < precision_count; k++) {
      int p = precision[k];

      count =
          sprintf(expected, "% .*d % .*ld % .*lld % .*hd % .*hhd", p, num[i].i,
                  p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "% .*d % .*ld % .*lld % .*hd % .*hhd", p,
                              num[i].i, p, num[i].li, p, num[i].lli, p,
                              num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision AND Hash
START_TEST(test_number_precision_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t k = 0; k < precision_count; k++) {
      int p = precision[k];

      count =
          sprintf(expected, "%#.*o %#.*lo %#.*llo %#.*ho %#.*hho", p, num[i].i,
                  p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%#.*o %#.*lo %#.*llo %#.*ho %#.*hho", p,
                              num[i].i, p, num[i].li, p, num[i].lli, p,
                              num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count =
          sprintf(expected, "%#.*x %#.*lx %#.*llx %#.*hx %#.*hhx", p, num[i].i,
                  p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%#.*x %#.*lx %#.*llx %#.*hx %#.*hhx", p,
                              num[i].i, p, num[i].li, p, num[i].lli, p,
                              num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count =
          sprintf(expected, "%#.*X %#.*lX %#.*llX %#.*hX %#.*hhX", p, num[i].i,
                  p, num[i].li, p, num[i].lli, p, num[i].hi, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%#.*X %#.*lX %#.*llX %#.*hX %#.*hhX", p,
                              num[i].i, p, num[i].li, p, num[i].lli, p,
                              num[i].hi, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Width AND Zero AND Plus
START_TEST(test_number_width_AND_zero_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count =
          sprintf(expected, "%+0*d %+0*ld %+0*lld %+0*hd %+0*hhd", w, num[i].i,
                  w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%+0*d %+0*ld %+0*lld %+0*hd %+0*hhd", w,
                              num[i].i, w, num[i].li, w, num[i].lli, w,
                              num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Width AND Zero AND Space
START_TEST(test_number_width_AND_zero_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count =
          sprintf(expected, "% 0*d % 0*ld % 0*lld % 0*hd % 0*hhd", w, num[i].i,
                  w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count = s21_sprintf(buffer, "% 0*d % 0*ld % 0*lld % 0*hd % 0*hhd", w,
                              num[i].i, w, num[i].li, w, num[i].lli, w,
                              num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Width AND Zero AND Hash
START_TEST(test_number_width_AND_zero_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];

      count =
          sprintf(expected, "%#0*o %#0*lo %#0*llo %#0*ho %#0*hho", w, num[i].i,
                  w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%#0*o %#0*lo %#0*llo %#0*ho %#0*hho", w,
                              num[i].i, w, num[i].li, w, num[i].lli, w,
                              num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count =
          sprintf(expected, "%#0*x %#0*lx %#0*llx %#0*hx %#0*hhx", w, num[i].i,
                  w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%#0*x %#0*lx %#0*llx %#0*hx %#0*hhx", w,
                              num[i].i, w, num[i].li, w, num[i].lli, w,
                              num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count =
          sprintf(expected, "%#0*X %#0*lX %#0*llX %#0*hX %#0*hhX", w, num[i].i,
                  w, num[i].li, w, num[i].lli, w, num[i].hi, w, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%#0*X %#0*lX %#0*llX %#0*hX %#0*hhX", w,
                              num[i].i, w, num[i].li, w, num[i].lli, w,
                              num[i].hi, w, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision AND Width AND Plus
START_TEST(test_number_precision_AND_width_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      for (size_t k = 0; k < precision_count; k++) {
        int w = width[j];
        int p = precision[k];

        count = sprintf(expected, "%+*.*d %+*.*ld %+*.*lld %+*.*hd %+*.*hhd", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count =
            s21_sprintf(buffer, "%+*.*d %+*.*ld %+*.*lld %+*.*hd %+*.*hhd", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);
      }
    }
  }
}
END_TEST

// Precision AND Width AND Space
START_TEST(test_number_precision_AND_width_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      for (size_t k = 0; k < precision_count; k++) {
        int w = width[j];
        int p = precision[k];

        count = sprintf(expected, "% *.*d % *.*ld % *.*lld % *.*hd % *.*hhd", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count =
            s21_sprintf(buffer, "% *.*d % *.*ld % *.*lld % *.*hd % *.*hhd", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);
      }
    }
  }
}
END_TEST

// Precision AND Width AND Hash
START_TEST(test_number_precision_AND_width_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      for (size_t k = 0; k < precision_count; k++) {
        int w = width[j];
        int p = precision[k];

        count = sprintf(expected, "%#*.*o %#*.*lo %#*.*llo %#*.*ho %#*.*hho", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count =
            s21_sprintf(buffer, "%#*.*o %#*.*lo %#*.*llo %#*.*ho %#*.*hho", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count = sprintf(expected, "%#*.*x %#*.*lx %#*.*llx %#*.*hx %#*.*hhx", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count =
            s21_sprintf(buffer, "%#*.*x %#*.*lx %#*.*llx %#*.*hx %#*.*hhx", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);

        count = sprintf(expected, "%#*.*X %#*.*lX %#*.*llX %#*.*hX %#*.*hhX", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        s21_count =
            s21_sprintf(buffer, "%#*.*X %#*.*lX %#*.*llX %#*.*hX %#*.*hhX", w,
                        p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                        num[i].hi, w, p, num[i].hhi);
        ck_assert_str_eq(buffer, expected);
        ck_assert_int_eq(count, s21_count);
      }
    }
  }
}
END_TEST

START_TEST(test_number_pointer) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  void *p = &count;
  count = sprintf(expected, "%p", p);
  s21_count = s21_sprintf(buffer, "%p", p);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  p = NULL;
  count = sprintf(expected, "%p", p);
  s21_count = s21_sprintf(buffer, "%p", p);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  for (size_t j = 0; j < width_count; j++) {
    int w = width[j];

    p = &count;
    count = sprintf(expected, "%*p", w, p);
    s21_count = s21_sprintf(buffer, "%*p", w, p);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    p = NULL;
    count = sprintf(expected, "%*p", w, p);
    s21_count = s21_sprintf(buffer, "%*p", w, p);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}
END_TEST

Suite *s21_sprintf_excruciating_int_test(void) {
  Suite *s = suite_create("s21_sprintf_excruciating_int_test");
  TCase *tc_d = tcase_create("All");

  tcase_add_test(tc_d, test_number);
  tcase_add_test(tc_d, test_number_plus);
  tcase_add_test(tc_d, test_number_space);
  tcase_add_test(tc_d, test_number_hash);
  tcase_add_test(tc_d, test_number_zero);

  tcase_add_test(tc_d, test_number_zero_AND_plus);
  tcase_add_test(tc_d, test_number_zero_AND_space);
  tcase_add_test(tc_d, test_number_zero_AND_hash);

  tcase_add_test(tc_d, test_number_width);
  tcase_add_test(tc_d, test_number_precision);
  tcase_add_test(tc_d, test_number_precision_AND_width);

  tcase_add_test(tc_d, test_number_width_AND_plus);
  tcase_add_test(tc_d, test_number_width_AND_space);
  tcase_add_test(tc_d, test_number_width_AND_hash);
  tcase_add_test(tc_d, test_number_width_AND_zero);

  tcase_add_test(tc_d, test_number_precision_AND_plus);
  tcase_add_test(tc_d, test_number_precision_AND_space);
  tcase_add_test(tc_d, test_number_precision_AND_hash);

  tcase_add_test(tc_d, test_number_width_AND_zero_AND_plus);
  tcase_add_test(tc_d, test_number_width_AND_zero_AND_space);
  tcase_add_test(tc_d, test_number_width_AND_zero_AND_hash);

  tcase_add_test(tc_d, test_number_precision_AND_width_AND_plus);
  tcase_add_test(tc_d, test_number_precision_AND_width_AND_space);
  tcase_add_test(tc_d, test_number_precision_AND_width_AND_hash);

  tcase_add_test(tc_d, test_number_pointer);

  suite_add_tcase(s, tc_d);

  return s;
}