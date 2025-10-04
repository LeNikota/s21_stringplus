#include "test_runner.h"

typedef struct IntTypes {
  int i;
  long li;
  long long lli;
  short hi;
  char hhi;
} IntTypes;

int width[] = {0, 1, 10, 100, -1, -10, -100};
int precision[] = {0, 1, 10, 100, -1};
IntTypes num[] = {{0, 0L, 0LL, 0, 0},
                  {INT_MAX, LONG_MAX, LLONG_MAX, SHRT_MAX, CHAR_MAX},
                  {INT_MIN, LONG_MIN, LLONG_MIN, SHRT_MIN, CHAR_MIN}};

size_t num_count = sizeof(num) / sizeof(num[0]);
size_t width_count = sizeof(width) / sizeof(width[0]);
size_t precision_count = sizeof(precision) / sizeof(precision[0]);

// Experimental
// START_TEST(test_string) {
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
START_TEST(test_string) {
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
START_TEST(test_string_plus) {
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
START_TEST(test_string_space) {
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
START_TEST(test_string_hash) {
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
START_TEST(test_string_zero) {
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
START_TEST(test_string_zero_AND_plus) {
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
START_TEST(test_string_zero_AND_space) {
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
START_TEST(test_string_zero_AND_hash) {
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
START_TEST(test_string_width) {
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
START_TEST(test_string_precision) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int p = precision[j];

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
START_TEST(test_string_precision_AND_width) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];
      int p = precision[j];

      count = sprintf(expected, "%*.*d %*.*ld %*.*lld %*.*hd %*.*hhd", w, p,
                      num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%*.*d %*.*ld %*.*lld %*.*hd %*.*hhd", w,
                              p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w,
                              p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*.*o %*.*lo %*.*llo %*.*ho %*.*hho", w, p,
                      num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%*.*o %*.*lo %*.*llo %*.*ho %*.*hho", w,
                              p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w,
                              p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*.*x %*.*lx %*.*llx %*.*hx %*.*hhx", w, p,
                      num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%*.*x %*.*lx %*.*llx %*.*hx %*.*hhx", w,
                              p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w,
                              p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*.*X %*.*lX %*.*llX %*.*hX %*.*hhX", w, p,
                      num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%*.*X %*.*lX %*.*llX %*.*hX %*.*hhX", w,
                              p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w,
                              p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%*.*u %*.*lu %*.*llu %*.*hu %*.*hhu", w, p,
                      num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(buffer, "%*.*u %*.*lu %*.*llu %*.*hu %*.*hhu", w,
                              p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w,
                              p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Width AND Plus
START_TEST(test_string_width_AND_plus) {
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
START_TEST(test_string_width_AND_space) {
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
START_TEST(test_string_width_AND_hash) {
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

// Precision AND Plus
START_TEST(test_string_precision_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int p = precision[j];

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
START_TEST(test_string_precision_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int p = precision[j];

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
START_TEST(test_string_precision_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int p = precision[j];

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
START_TEST(test_string_width_AND_zero_AND_plus) {
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
START_TEST(test_string_width_AND_zero_AND_space) {
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
START_TEST(test_string_width_AND_zero_AND_hash) {
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
START_TEST(test_string_precision_AND_width_AND_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];
      int p = precision[j];

      count = sprintf(expected, "%+*.*d %+*.*ld %+*.*lld %+*.*hd %+*.*hhd", w,
                      p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(
          buffer, "%+*.*d %+*.*ld %+*.*lld %+*.*hd %+*.*hhd", w, p, num[i].i, w,
          p, num[i].li, w, p, num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision AND Width AND Space
START_TEST(test_string_precision_AND_width_AND_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];
      int p = precision[j];

      count = sprintf(expected, "% *.*d % *.*ld % *.*lld % *.*hd % *.*hhd", w,
                      p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(
          buffer, "% *.*d % *.*ld % *.*lld % *.*hd % *.*hhd", w, p, num[i].i, w,
          p, num[i].li, w, p, num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Precision AND Width AND Hash
START_TEST(test_string_precision_AND_width_AND_hash) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i = 0; i < num_count; i++) {
    for (size_t j = 0; j < width_count; j++) {
      int w = width[j];
      int p = precision[j];

      count = sprintf(expected, "%#*.*o %#*.*lo %#*.*llo %#*.*ho %#*.*hho", w,
                      p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(
          buffer, "%#*.*o %#*.*lo %#*.*llo %#*.*ho %#*.*hho", w, p, num[i].i, w,
          p, num[i].li, w, p, num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#*.*x %#*.*lx %#*.*llx %#*.*hx %#*.*hhx", w,
                      p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(
          buffer, "%#*.*x %#*.*lx %#*.*llx %#*.*hx %#*.*hhx", w, p, num[i].i, w,
          p, num[i].li, w, p, num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);

      count = sprintf(expected, "%#*.*X %#*.*lX %#*.*llX %#*.*hX %#*.*hhX", w,
                      p, num[i].i, w, p, num[i].li, w, p, num[i].lli, w, p,
                      num[i].hi, w, p, num[i].hhi);
      s21_count = s21_sprintf(
          buffer, "%#*.*X %#*.*lX %#*.*llX %#*.*hX %#*.*hhX", w, p, num[i].i, w,
          p, num[i].li, w, p, num[i].lli, w, p, num[i].hi, w, p, num[i].hhi);
      ck_assert_str_eq(buffer, expected);
      ck_assert_int_eq(count, s21_count);
    }
  }
}
END_TEST

// Other

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

  // Test with multiple %n
  int n3, n4, n5, n6;
  count = sprintf(expected, "ab%n %f cd%n", &n3, 342.34f, &n4);
  s21_count = s21_sprintf(buffer, "ab%n %f cd%n", &n5, 342.34f, &n6);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
  ck_assert_int_eq(n3, n5);
  ck_assert_int_eq(n4, n6);
}

Suite *s21_sprintf_excruciating_test(void) {
  Suite *s = suite_create("s21_sprintf_excruciating_test");
  TCase *tc_d = tcase_create("All");

  tcase_add_test(tc_d, test_string);
  tcase_add_test(tc_d, test_string_plus);
  tcase_add_test(tc_d, test_string_space);
  tcase_add_test(tc_d, test_string_hash);
  tcase_add_test(tc_d, test_string_zero);

  tcase_add_test(tc_d, test_string_zero_AND_plus);
  tcase_add_test(tc_d, test_string_zero_AND_space);
  tcase_add_test(tc_d, test_string_zero_AND_hash);

  tcase_add_test(tc_d, test_string_width);
  tcase_add_test(tc_d, test_string_precision);
  tcase_add_test(tc_d, test_string_precision_AND_width);

  tcase_add_test(tc_d, test_string_width_AND_plus);
  tcase_add_test(tc_d, test_string_width_AND_space);
  tcase_add_test(tc_d, test_string_width_AND_hash);

  tcase_add_test(tc_d, test_string_precision_AND_plus);
  tcase_add_test(tc_d, test_string_precision_AND_space);
  tcase_add_test(tc_d, test_string_precision_AND_hash);

  tcase_add_test(tc_d, test_string_width_AND_zero_AND_plus);
  tcase_add_test(tc_d, test_string_width_AND_zero_AND_space);
  tcase_add_test(tc_d, test_string_width_AND_zero_AND_hash);

  tcase_add_test(tc_d, test_string_precision_AND_width_AND_plus);
  tcase_add_test(tc_d, test_string_precision_AND_width_AND_space);
  tcase_add_test(tc_d, test_string_precision_AND_width_AND_hash);

  tcase_add_test(tc_d, test_count_specifier);

  suite_add_tcase(s, tc_d);

  return s;
}