#include "test_runner.h"

typedef struct IntTypes {
  int i;
  long li;
  long long lli;
  short hi;
  char hhi;
} IntTypes;

IntTypes num[] = {{0, 0L, 0LL, 0, 0},
                  {INT_MAX, LONG_MAX, LLONG_MAX, SHRT_MAX, CHAR_MAX},
                  {INT_MIN, LONG_MIN, LLONG_MIN, SHRT_MIN, CHAR_MIN}};

size_t num_count = sizeof(num) / sizeof(num[0]);

// Experimental
// START_TEST(test_string_format) {
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

START_TEST(test_string_format) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

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

  count = sprintf(expected, "%i %li %lli %hi %hhi", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%i %li %lli %hi %hhi", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%o %lo %llo %ho %hho", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%o %lo %llo %ho %hho", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%x %lx %llx %hx %hhx", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%x %lx %llx %hx %hhx", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%X %lX %llX %hX %hhX", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%X %lX %llX %hX %hhX", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%u %lu %llu %hu %hhu", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%u %lu %llu %hu %hhu", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

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

  count = sprintf(expected, "%i %li %lli %hi %hhi", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%i %li %lli %hi %hhi", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%o %lo %llo %ho %hho", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%o %lo %llo %ho %hho", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%x %lx %llx %hx %hhx", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%x %lx %llx %hx %hhx", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%X %lX %llX %hX %hhX", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%X %lX %llX %hX %hhX", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%u %lu %llu %hu %hhu", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%u %lu %llu %hu %hhu", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

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

  count = sprintf(expected, "%i %li %lli %hi %hhi", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%i %li %lli %hi %hhi", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%o %lo %llo %ho %hho", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%o %lo %llo %ho %hho", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%x %lx %llx %hx %hhx", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%x %lx %llx %hx %hhx", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%X %lX %llX %hX %hhX", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%X %lX %llX %hX %hhX", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%u %lu %llu %hu %hhu", regular_int, long_int,
                  long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%u %lu %llu %hu %hhu", regular_int, long_int,
                          long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

// Plus

START_TEST(test_string_plus) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  for (size_t i; i < num_count; i++) {
    int regular_int = num[i].i;
    long long_int = num[i].li;
    long long long_long_int = num[i].lli;
    short short_int = num[i].hi;
    char char_int = num[i].hi;

    count = sprintf(expected, "%+d %+ld %+lld %+hd %+hhd", regular_int,
                    long_int, long_long_int, short_int, char_int);
    s21_count = s21_sprintf(buffer, "%+d %+ld %+lld %+hd %+hhd", regular_int,
                            long_int, long_long_int, short_int, char_int);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "%+i %+li %+lli %+hi %+hhi", regular_int,
                    long_int, long_long_int, short_int, char_int);
    s21_count = s21_sprintf(buffer, "%+i %+li %+lli %+hi %+hhi", regular_int,
                            long_int, long_long_int, short_int, char_int);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Space

START_TEST(test_string_space) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  for (size_t i; i < num_count; i++) {
    int regular_int = num[i].i;
    long long_int = num[i].li;
    long long long_long_int = num[i].lli;
    short short_int = num[i].hi;
    char char_int = num[i].hi;

    count = sprintf(expected, "% d % ld % lld % hd % hhd", regular_int,
                    long_int, long_long_int, short_int, char_int);
    s21_count = s21_sprintf(buffer, "% d % ld % lld % hd % hhd", regular_int,
                            long_int, long_long_int, short_int, char_int);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);

    count = sprintf(expected, "% i % li % lli % hi % hhi", regular_int,
                    long_int, long_long_int, short_int, char_int);
    s21_count = s21_sprintf(buffer, "% i % li % lli % hi % hhi", regular_int,
                            long_int, long_long_int, short_int, char_int);
    ck_assert_str_eq(buffer, expected);
    ck_assert_int_eq(count, s21_count);
  }
}

// Width

START_TEST(test_string_width_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10i %10li %10lli %10hi %10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10i %10li %10lli %10hi %10hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10o %10lo %10llo %10ho %10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10o %10lo %10llo %10ho %10hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10i %10li %10lli %10hi %10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10i %10li %10lli %10hi %10hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10o %10lo %10llo %10ho %10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10o %10lo %10llo %10ho %10hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10i %10li %10lli %10hi %10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10i %10li %10lli %10hi %10hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10o %10lo %10llo %10ho %10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10o %10lo %10llo %10ho %10hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10i %10li %10lli %10hi %10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10i %10li %10lli %10hi %10hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10o %10lo %10llo %10ho %10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10o %10lo %10llo %10ho %10hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10i %10li %10lli %10hi %10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10i %10li %10lli %10hi %10hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10o %10lo %10llo %10ho %10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10o %10lo %10llo %10ho %10hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10d %10ld %10lld %10hd %10hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10i %10li %10lli %10hi %10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10i %10li %10lli %10hi %10hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10o %10lo %10llo %10ho %10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10o %10lo %10llo %10ho %10hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10x %10lx %10llx %10hx %10hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10X %10lX %10llX %10hX %10hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%10u %10lu %10llu %10hu %10hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%100d %100ld %100lld %100hd %100hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100d %100ld %100lld %100hd %100hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100i %100li %100lli %100hi %100hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100i %100li %100lli %100hi %100hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100o %100lo %100llo %100ho %100hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100o %100lo %100llo %100ho %100hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100x %100lx %100llx %100hx %100hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100x %100lx %100llx %100hx %100hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100X %100lX %100llX %100hX %100hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100X %100lX %100llX %100hX %100hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100u %100lu %100llu %100hu %100hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100u %100lu %100llu %100hu %100hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%100d %100ld %100lld %100hd %100hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100d %100ld %100lld %100hd %100hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100i %100li %100lli %100hi %100hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100i %100li %100lli %100hi %100hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100o %100lo %100llo %100ho %100hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100o %100lo %100llo %100ho %100hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100x %100lx %100llx %100hx %100hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100x %100lx %100llx %100hx %100hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100X %100lX %100llX %100hX %100hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100X %100lX %100llX %100hX %100hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100u %100lu %100llu %100hu %100hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100u %100lu %100llu %100hu %100hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%100d %100ld %100lld %100hd %100hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100d %100ld %100lld %100hd %100hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100i %100li %100lli %100hi %100hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100i %100li %100lli %100hi %100hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100o %100lo %100llo %100ho %100hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100o %100lo %100llo %100ho %100hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100x %100lx %100llx %100hx %100hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100x %100lx %100llx %100hx %100hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100X %100lX %100llX %100hX %100hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100X %100lX %100llX %100hX %100hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100u %100lu %100llu %100hu %100hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100u %100lu %100llu %100hu %100hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10d %-10ld %-10lld %-10hd %-10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10i %-10li %-10lli %-10hi %-10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10o %-10lo %-10llo %-10ho %-10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10x %-10lx %-10llx %-10hx %-10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10X %-10lX %-10llX %-10hX %-10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10u %-10lu %-10llu %-10hu %-10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%-100d %-100ld %-100lld %-100hd %-100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100d %-100ld %-100lld %-100hd %-100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100i %-100li %-100lli %-100hi %-100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100i %-100li %-100lli %-100hi %-100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100o %-100lo %-100llo %-100ho %-100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100o %-100lo %-100llo %-100ho %-100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100x %-100lx %-100llx %-100hx %-100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100x %-100lx %-100llx %-100hx %-100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100X %-100lX %-100llX %-100hX %-100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100X %-100lX %-100llX %-100hX %-100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100u %-100lu %-100llu %-100hu %-100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100u %-100lu %-100llu %-100hu %-100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%-100d %-100ld %-100lld %-100hd %-100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100d %-100ld %-100lld %-100hd %-100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100i %-100li %-100lli %-100hi %-100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100i %-100li %-100lli %-100hi %-100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100o %-100lo %-100llo %-100ho %-100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100o %-100lo %-100llo %-100ho %-100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100x %-100lx %-100llx %-100hx %-100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100x %-100lx %-100llx %-100hx %-100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100X %-100lX %-100llX %-100hX %-100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100X %-100lX %-100llX %-100hX %-100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100u %-100lu %-100llu %-100hu %-100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100u %-100lu %-100llu %-100hu %-100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%-100d %-100ld %-100lld %-100hd %-100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100d %-100ld %-100lld %-100hd %-100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100i %-100li %-100lli %-100hi %-100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100i %-100li %-100lli %-100hi %-100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100o %-100lo %-100llo %-100ho %-100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100o %-100lo %-100llo %-100ho %-100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100x %-100lx %-100llx %-100hx %-100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100x %-100lx %-100llx %-100hx %-100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100X %-100lX %-100llX %-100hX %-100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100X %-100lX %-100llX %-100hX %-100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-100u %-100lu %-100llu %-100hu %-100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100u %-100lu %-100llu %-100hu %-100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

// Precision

START_TEST(test_string_precision_0) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%.0d %.0ld %.0lld %.0hd %.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0d %.0ld %.0lld %.0hd %.0hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0i %.0li %.0lli %.0hi %.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0i %.0li %.0lli %.0hi %.0hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0o %.0lo %.0llo %.0ho %.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0o %.0lo %.0llo %.0ho %.0hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0x %.0lx %.0llx %.0hx %.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0x %.0lx %.0llx %.0hx %.0hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0X %.0lX %.0llX %.0hX %.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0X %.0lX %.0llX %.0hX %.0hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0u %.0lu %.0llu %.0hu %.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0u %.0lu %.0llu %.0hu %.0hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%.0d %.0ld %.0lld %.0hd %.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0d %.0ld %.0lld %.0hd %.0hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0i %.0li %.0lli %.0hi %.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0i %.0li %.0lli %.0hi %.0hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0o %.0lo %.0llo %.0ho %.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0o %.0lo %.0llo %.0ho %.0hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0x %.0lx %.0llx %.0hx %.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0x %.0lx %.0llx %.0hx %.0hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0X %.0lX %.0llX %.0hX %.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0X %.0lX %.0llX %.0hX %.0hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0u %.0lu %.0llu %.0hu %.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0u %.0lu %.0llu %.0hu %.0hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%.0d %.0ld %.0lld %.0hd %.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0d %.0ld %.0lld %.0hd %.0hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0i %.0li %.0lli %.0hi %.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0i %.0li %.0lli %.0hi %.0hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0o %.0lo %.0llo %.0ho %.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0o %.0lo %.0llo %.0ho %.0hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0x %.0lx %.0llx %.0hx %.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0x %.0lx %.0llx %.0hx %.0hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0X %.0lX %.0llX %.0hX %.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0X %.0lX %.0llX %.0hX %.0hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0u %.0lu %.0llu %.0hu %.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.0u %.0lu %.0llu %.0hu %.0hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_precision_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%.1d %.1ld %.1lld %.1hd %.1hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1d %.1ld %.1lld %.1hd %.1hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1i %.1li %.1lli %.1hi %.1hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1i %.1li %.1lli %.1hi %.1hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1o %.1lo %.1llo %.1ho %.1hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1o %.1lo %.1llo %.1ho %.1hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1x %.1lx %.1llx %.1hx %.1hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1x %.1lx %.1llx %.1hx %.1hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1X %.1lX %.1llX %.1hX %.1hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1X %.1lX %.1llX %.1hX %.1hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1u %.1lu %.1llu %.1hu %.1hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1u %.1lu %.1llu %.1hu %.1hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%.1d %.1ld %.1lld %.1hd %.1hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1d %.1ld %.1lld %.1hd %.1hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1i %.1li %.1lli %.1hi %.1hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1i %.1li %.1lli %.1hi %.1hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1o %.1lo %.1llo %.1ho %.1hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1o %.1lo %.1llo %.1ho %.1hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1x %.1lx %.1llx %.1hx %.1hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1x %.1lx %.1llx %.1hx %.1hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1X %.1lX %.1llX %.1hX %.1hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1X %.1lX %.1llX %.1hX %.1hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1u %.1lu %.1llu %.1hu %.1hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1u %.1lu %.1llu %.1hu %.1hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%.1d %.1ld %.1lld %.1hd %.1hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1d %.1ld %.1lld %.1hd %.1hhd", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1i %.1li %.1lli %.1hi %.1hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1i %.1li %.1lli %.1hi %.1hhi", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1o %.1lo %.1llo %.1ho %.1hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1o %.1lo %.1llo %.1ho %.1hho", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1x %.1lx %.1llx %.1hx %.1hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1x %.1lx %.1llx %.1hx %.1hhx", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1X %.1lX %.1llX %.1hX %.1hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1X %.1lX %.1llX %.1hX %.1hhX", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.1u %.1lu %.1llu %.1hu %.1hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(buffer, "%.1u %.1lu %.1llu %.1hu %.1hhu", regular_int,
                          long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_precision_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%.10d %.10ld %.10lld %.10hd %.10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10d %.10ld %.10lld %.10hd %.10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10i %.10li %.10lli %.10hi %.10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10i %.10li %.10lli %.10hi %.10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10o %.10lo %.10llo %.10ho %.10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10o %.10lo %.10llo %.10ho %.10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10x %.10lx %.10llx %.10hx %.10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10x %.10lx %.10llx %.10hx %.10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10X %.10lX %.10llX %.10hX %.10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10X %.10lX %.10llX %.10hX %.10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10u %.10lu %.10llu %.10hu %.10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10u %.10lu %.10llu %.10hu %.10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%.10d %.10ld %.10lld %.10hd %.10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10d %.10ld %.10lld %.10hd %.10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10i %.10li %.10lli %.10hi %.10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10i %.10li %.10lli %.10hi %.10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10o %.10lo %.10llo %.10ho %.10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10o %.10lo %.10llo %.10ho %.10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10x %.10lx %.10llx %.10hx %.10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10x %.10lx %.10llx %.10hx %.10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10X %.10lX %.10llX %.10hX %.10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10X %.10lX %.10llX %.10hX %.10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10u %.10lu %.10llu %.10hu %.10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10u %.10lu %.10llu %.10hu %.10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%.10d %.10ld %.10lld %.10hd %.10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10d %.10ld %.10lld %.10hd %.10hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10i %.10li %.10lli %.10hi %.10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10i %.10li %.10lli %.10hi %.10hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10o %.10lo %.10llo %.10ho %.10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10o %.10lo %.10llo %.10ho %.10hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10x %.10lx %.10llx %.10hx %.10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10x %.10lx %.10llx %.10hx %.10hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10X %.10lX %.10llX %.10hX %.10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10X %.10lX %.10llX %.10hX %.10hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10u %.10lu %.10llu %.10hu %.10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.10u %.10lu %.10llu %.10hu %.10hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_precision_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%.100d %.100ld %.100lld %.100hd %.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100d %.100ld %.100lld %.100hd %.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100i %.100li %.100lli %.100hi %.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100i %.100li %.100lli %.100hi %.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100o %.100lo %.100llo %.100ho %.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100o %.100lo %.100llo %.100ho %.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100x %.100lx %.100llx %.100hx %.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100x %.100lx %.100llx %.100hx %.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100X %.100lX %.100llX %.100hX %.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100X %.100lX %.100llX %.100hX %.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100u %.100lu %.100llu %.100hu %.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100u %.100lu %.100llu %.100hu %.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%.100d %.100ld %.100lld %.100hd %.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100d %.100ld %.100lld %.100hd %.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100i %.100li %.100lli %.100hi %.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100i %.100li %.100lli %.100hi %.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100o %.100lo %.100llo %.100ho %.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100o %.100lo %.100llo %.100ho %.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100x %.100lx %.100llx %.100hx %.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100x %.100lx %.100llx %.100hx %.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100X %.100lX %.100llX %.100hX %.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100X %.100lX %.100llX %.100hX %.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100u %.100lu %.100llu %.100hu %.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100u %.100lu %.100llu %.100hu %.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%.100d %.100ld %.100lld %.100hd %.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100d %.100ld %.100lld %.100hd %.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100i %.100li %.100lli %.100hi %.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100i %.100li %.100lli %.100hi %.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100o %.100lo %.100llo %.100ho %.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100o %.100lo %.100llo %.100ho %.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100x %.100lx %.100llx %.100hx %.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100x %.100lx %.100llx %.100hx %.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100X %.100lX %.100llX %.100hX %.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100X %.100lX %.100llX %.100hX %.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.100u %.100lu %.100llu %.100hu %.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%.100u %.100lu %.100llu %.100hu %.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

//

// Precision AND Width

START_TEST(test_string_width_1_AND_precision_0) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%1.0d %1.0ld %1.0lld %1.0hd %1.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0d %1.0ld %1.0lld %1.0hd %1.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0i %1.0li %1.0lli %1.0hi %1.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0i %1.0li %1.0lli %1.0hi %1.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0o %1.0lo %1.0llo %1.0ho %1.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0o %1.0lo %1.0llo %1.0ho %1.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0x %1.0lx %1.0llx %1.0hx %1.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0x %1.0lx %1.0llx %1.0hx %1.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0X %1.0lX %1.0llX %1.0hX %1.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0X %1.0lX %1.0llX %1.0hX %1.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0u %1.0lu %1.0llu %1.0hu %1.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0u %1.0lu %1.0llu %1.0hu %1.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%1.0d %1.0ld %1.0lld %1.0hd %1.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0d %1.0ld %1.0lld %1.0hd %1.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0i %1.0li %1.0lli %1.0hi %1.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0i %1.0li %1.0lli %1.0hi %1.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0o %1.0lo %1.0llo %1.0ho %1.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0o %1.0lo %1.0llo %1.0ho %1.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0x %1.0lx %1.0llx %1.0hx %1.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0x %1.0lx %1.0llx %1.0hx %1.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0X %1.0lX %1.0llX %1.0hX %1.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0X %1.0lX %1.0llX %1.0hX %1.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0u %1.0lu %1.0llu %1.0hu %1.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0u %1.0lu %1.0llu %1.0hu %1.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%1.0d %1.0ld %1.0lld %1.0hd %1.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0d %1.0ld %1.0lld %1.0hd %1.0hhd", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0i %1.0li %1.0lli %1.0hi %1.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0i %1.0li %1.0lli %1.0hi %1.0hhi", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0o %1.0lo %1.0llo %1.0ho %1.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0o %1.0lo %1.0llo %1.0ho %1.0hho", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0x %1.0lx %1.0llx %1.0hx %1.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0x %1.0lx %1.0llx %1.0hx %1.0hhx", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0X %1.0lX %1.0llX %1.0hX %1.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0X %1.0lX %1.0llX %1.0hX %1.0hhX", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%1.0u %1.0lu %1.0llu %1.0hu %1.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%1.0u %1.0lu %1.0llu %1.0hu %1.0hhu", regular_int,
                  long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_10_AND_precision_0) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%10.0d %10.0ld %10.0lld %10.0hd %10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0d %10.0ld %10.0lld %10.0hd %10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0i %10.0li %10.0lli %10.0hi %10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0i %10.0li %10.0lli %10.0hi %10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0o %10.0lo %10.0llo %10.0ho %10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0o %10.0lo %10.0llo %10.0ho %10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0x %10.0lx %10.0llx %10.0hx %10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0x %10.0lx %10.0llx %10.0hx %10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0X %10.0lX %10.0llX %10.0hX %10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0X %10.0lX %10.0llX %10.0hX %10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0u %10.0lu %10.0llu %10.0hu %10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0u %10.0lu %10.0llu %10.0hu %10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%10.0d %10.0ld %10.0lld %10.0hd %10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0d %10.0ld %10.0lld %10.0hd %10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0i %10.0li %10.0lli %10.0hi %10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0i %10.0li %10.0lli %10.0hi %10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0o %10.0lo %10.0llo %10.0ho %10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0o %10.0lo %10.0llo %10.0ho %10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0x %10.0lx %10.0llx %10.0hx %10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0x %10.0lx %10.0llx %10.0hx %10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0X %10.0lX %10.0llX %10.0hX %10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0X %10.0lX %10.0llX %10.0hX %10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0u %10.0lu %10.0llu %10.0hu %10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0u %10.0lu %10.0llu %10.0hu %10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%10.0d %10.0ld %10.0lld %10.0hd %10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0d %10.0ld %10.0lld %10.0hd %10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0i %10.0li %10.0lli %10.0hi %10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0i %10.0li %10.0lli %10.0hi %10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0o %10.0lo %10.0llo %10.0ho %10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0o %10.0lo %10.0llo %10.0ho %10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0x %10.0lx %10.0llx %10.0hx %10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0x %10.0lx %10.0llx %10.0hx %10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0X %10.0lX %10.0llX %10.0hX %10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0X %10.0lX %10.0llX %10.0hX %10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.0u %10.0lu %10.0llu %10.0hu %10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.0u %10.0lu %10.0llu %10.0hu %10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_100_AND_precision_0) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%100.0d %100.0ld %100.0lld %100.0hd %100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0d %100.0ld %100.0lld %100.0hd %100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0i %100.0li %100.0lli %100.0hi %100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0i %100.0li %100.0lli %100.0hi %100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0o %100.0lo %100.0llo %100.0ho %100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0o %100.0lo %100.0llo %100.0ho %100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0x %100.0lx %100.0llx %100.0hx %100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0x %100.0lx %100.0llx %100.0hx %100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0X %100.0lX %100.0llX %100.0hX %100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0X %100.0lX %100.0llX %100.0hX %100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0u %100.0lu %100.0llu %100.0hu %100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0u %100.0lu %100.0llu %100.0hu %100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%100.0d %100.0ld %100.0lld %100.0hd %100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0d %100.0ld %100.0lld %100.0hd %100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0i %100.0li %100.0lli %100.0hi %100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0i %100.0li %100.0lli %100.0hi %100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0o %100.0lo %100.0llo %100.0ho %100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0o %100.0lo %100.0llo %100.0ho %100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0x %100.0lx %100.0llx %100.0hx %100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0x %100.0lx %100.0llx %100.0hx %100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0X %100.0lX %100.0llX %100.0hX %100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0X %100.0lX %100.0llX %100.0hX %100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0u %100.0lu %100.0llu %100.0hu %100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0u %100.0lu %100.0llu %100.0hu %100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%100.0d %100.0ld %100.0lld %100.0hd %100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0d %100.0ld %100.0lld %100.0hd %100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0i %100.0li %100.0lli %100.0hi %100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0i %100.0li %100.0lli %100.0hi %100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0o %100.0lo %100.0llo %100.0ho %100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0o %100.0lo %100.0llo %100.0ho %100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0x %100.0lx %100.0llx %100.0hx %100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0x %100.0lx %100.0llx %100.0hx %100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0X %100.0lX %100.0llX %100.0hX %100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0X %100.0lX %100.0llX %100.0hX %100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.0u %100.0lu %100.0llu %100.0hu %100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.0u %100.0lu %100.0llu %100.0hu %100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_1_AND_precision_0) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%-1.0d %-1.0ld %-1.0lld %-1.0hd %-1.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0d %-1.0ld %-1.0lld %-1.0hd %-1.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0i %-1.0li %-1.0lli %-1.0hi %-1.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0i %-1.0li %-1.0lli %-1.0hi %-1.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0o %-1.0lo %-1.0llo %-1.0ho %-1.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0o %-1.0lo %-1.0llo %-1.0ho %-1.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0x %-1.0lx %-1.0llx %-1.0hx %-1.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0x %-1.0lx %-1.0llx %-1.0hx %-1.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0X %-1.0lX %-1.0llX %-1.0hX %-1.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0X %-1.0lX %-1.0llX %-1.0hX %-1.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0u %-1.0lu %-1.0llu %-1.0hu %-1.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0u %-1.0lu %-1.0llu %-1.0hu %-1.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%-1.0d %-1.0ld %-1.0lld %-1.0hd %-1.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0d %-1.0ld %-1.0lld %-1.0hd %-1.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0i %-1.0li %-1.0lli %-1.0hi %-1.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0i %-1.0li %-1.0lli %-1.0hi %-1.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0o %-1.0lo %-1.0llo %-1.0ho %-1.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0o %-1.0lo %-1.0llo %-1.0ho %-1.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0x %-1.0lx %-1.0llx %-1.0hx %-1.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0x %-1.0lx %-1.0llx %-1.0hx %-1.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0X %-1.0lX %-1.0llX %-1.0hX %-1.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0X %-1.0lX %-1.0llX %-1.0hX %-1.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0u %-1.0lu %-1.0llu %-1.0hu %-1.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0u %-1.0lu %-1.0llu %-1.0hu %-1.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%-1.0d %-1.0ld %-1.0lld %-1.0hd %-1.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0d %-1.0ld %-1.0lld %-1.0hd %-1.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0i %-1.0li %-1.0lli %-1.0hi %-1.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0i %-1.0li %-1.0lli %-1.0hi %-1.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0o %-1.0lo %-1.0llo %-1.0ho %-1.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0o %-1.0lo %-1.0llo %-1.0ho %-1.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0x %-1.0lx %-1.0llx %-1.0hx %-1.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0x %-1.0lx %-1.0llx %-1.0hx %-1.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0X %-1.0lX %-1.0llX %-1.0hX %-1.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0X %-1.0lX %-1.0llX %-1.0hX %-1.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-1.0u %-1.0lu %-1.0llu %-1.0hu %-1.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-1.0u %-1.0lu %-1.0llu %-1.0hu %-1.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_10_AND_precision_0) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%-10.0d %-10.0ld %-10.0lld %-10.0hd %-10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0d %-10.0ld %-10.0lld %-10.0hd %-10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0i %-10.0li %-10.0lli %-10.0hi %-10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0i %-10.0li %-10.0lli %-10.0hi %-10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0o %-10.0lo %-10.0llo %-10.0ho %-10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0o %-10.0lo %-10.0llo %-10.0ho %-10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0x %-10.0lx %-10.0llx %-10.0hx %-10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0x %-10.0lx %-10.0llx %-10.0hx %-10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0X %-10.0lX %-10.0llX %-10.0hX %-10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0X %-10.0lX %-10.0llX %-10.0hX %-10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0u %-10.0lu %-10.0llu %-10.0hu %-10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0u %-10.0lu %-10.0llu %-10.0hu %-10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%-10.0d %-10.0ld %-10.0lld %-10.0hd %-10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0d %-10.0ld %-10.0lld %-10.0hd %-10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0i %-10.0li %-10.0lli %-10.0hi %-10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0i %-10.0li %-10.0lli %-10.0hi %-10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0o %-10.0lo %-10.0llo %-10.0ho %-10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0o %-10.0lo %-10.0llo %-10.0ho %-10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0x %-10.0lx %-10.0llx %-10.0hx %-10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0x %-10.0lx %-10.0llx %-10.0hx %-10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0X %-10.0lX %-10.0llX %-10.0hX %-10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0X %-10.0lX %-10.0llX %-10.0hX %-10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0u %-10.0lu %-10.0llu %-10.0hu %-10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0u %-10.0lu %-10.0llu %-10.0hu %-10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%-10.0d %-10.0ld %-10.0lld %-10.0hd %-10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0d %-10.0ld %-10.0lld %-10.0hd %-10.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0i %-10.0li %-10.0lli %-10.0hi %-10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0i %-10.0li %-10.0lli %-10.0hi %-10.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0o %-10.0lo %-10.0llo %-10.0ho %-10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0o %-10.0lo %-10.0llo %-10.0ho %-10.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0x %-10.0lx %-10.0llx %-10.0hx %-10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0x %-10.0lx %-10.0llx %-10.0hx %-10.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0X %-10.0lX %-10.0llX %-10.0hX %-10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0X %-10.0lX %-10.0llX %-10.0hX %-10.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.0u %-10.0lu %-10.0llu %-10.0hu %-10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.0u %-10.0lu %-10.0llu %-10.0hu %-10.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_100_AND_precision_0) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count =
      sprintf(expected, "%-100.0d %-100.0ld %-100.0lld %-100.0hd %-100.0hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0d %-100.0ld %-100.0lld %-100.0hd %-100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0i %-100.0li %-100.0lli %-100.0hi %-100.0hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0i %-100.0li %-100.0lli %-100.0hi %-100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0o %-100.0lo %-100.0llo %-100.0ho %-100.0hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0o %-100.0lo %-100.0llo %-100.0ho %-100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0x %-100.0lx %-100.0llx %-100.0hx %-100.0hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0x %-100.0lx %-100.0llx %-100.0hx %-100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0X %-100.0lX %-100.0llX %-100.0hX %-100.0hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0X %-100.0lX %-100.0llX %-100.0hX %-100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0u %-100.0lu %-100.0llu %-100.0hu %-100.0hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0u %-100.0lu %-100.0llu %-100.0hu %-100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count =
      sprintf(expected, "%-100.0d %-100.0ld %-100.0lld %-100.0hd %-100.0hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0d %-100.0ld %-100.0lld %-100.0hd %-100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0i %-100.0li %-100.0lli %-100.0hi %-100.0hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0i %-100.0li %-100.0lli %-100.0hi %-100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0o %-100.0lo %-100.0llo %-100.0ho %-100.0hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0o %-100.0lo %-100.0llo %-100.0ho %-100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0x %-100.0lx %-100.0llx %-100.0hx %-100.0hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0x %-100.0lx %-100.0llx %-100.0hx %-100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0X %-100.0lX %-100.0llX %-100.0hX %-100.0hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0X %-100.0lX %-100.0llX %-100.0hX %-100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0u %-100.0lu %-100.0llu %-100.0hu %-100.0hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0u %-100.0lu %-100.0llu %-100.0hu %-100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count =
      sprintf(expected, "%-100.0d %-100.0ld %-100.0lld %-100.0hd %-100.0hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0d %-100.0ld %-100.0lld %-100.0hd %-100.0hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0i %-100.0li %-100.0lli %-100.0hi %-100.0hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0i %-100.0li %-100.0lli %-100.0hi %-100.0hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0o %-100.0lo %-100.0llo %-100.0ho %-100.0hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0o %-100.0lo %-100.0llo %-100.0ho %-100.0hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0x %-100.0lx %-100.0llx %-100.0hx %-100.0hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0x %-100.0lx %-100.0llx %-100.0hx %-100.0hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0X %-100.0lX %-100.0llX %-100.0hX %-100.0hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0X %-100.0lX %-100.0llX %-100.0hX %-100.0hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.0u %-100.0lu %-100.0llu %-100.0hu %-100.0hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.0u %-100.0lu %-100.0llu %-100.0hu %-100.0hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_1_AND_precision_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_10_AND_precision_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1d %10.1ld %10.1lld %10.1hd %10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1i %10.1li %10.1lli %10.1hi %10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1o %10.1lo %10.1llo %10.1ho %10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1x %10.1lx %10.1llx %10.1hx %10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1X %10.1lX %10.1llX %10.1hX %10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.1u %10.1lu %10.1llu %10.1hu %10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_100_AND_precision_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%100.1d %100.1ld %100.1lld %100.1hd %100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1d %100.1ld %100.1lld %100.1hd %100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1i %100.1li %100.1lli %100.1hi %100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1i %100.1li %100.1lli %100.1hi %100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1o %100.1lo %100.1llo %100.1ho %100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1o %100.1lo %100.1llo %100.1ho %100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1x %100.1lx %100.1llx %100.1hx %100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1x %100.1lx %100.1llx %100.1hx %100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1X %100.1lX %100.1llX %100.1hX %100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1X %100.1lX %100.1llX %100.1hX %100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1u %100.1lu %100.1llu %100.1hu %100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1u %100.1lu %100.1llu %100.1hu %100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%100.1d %100.1ld %100.1lld %100.1hd %100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1d %100.1ld %100.1lld %100.1hd %100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1i %100.1li %100.1lli %100.1hi %100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1i %100.1li %100.1lli %100.1hi %100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1o %100.1lo %100.1llo %100.1ho %100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1o %100.1lo %100.1llo %100.1ho %100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1x %100.1lx %100.1llx %100.1hx %100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1x %100.1lx %100.1llx %100.1hx %100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1X %100.1lX %100.1llX %100.1hX %100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1X %100.1lX %100.1llX %100.1hX %100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1u %100.1lu %100.1llu %100.1hu %100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1u %100.1lu %100.1llu %100.1hu %100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%100.1d %100.1ld %100.1lld %100.1hd %100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1d %100.1ld %100.1lld %100.1hd %100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1i %100.1li %100.1lli %100.1hi %100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1i %100.1li %100.1lli %100.1hi %100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1o %100.1lo %100.1llo %100.1ho %100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1o %100.1lo %100.1llo %100.1ho %100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1x %100.1lx %100.1llx %100.1hx %100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1x %100.1lx %100.1llx %100.1hx %100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1X %100.1lX %100.1llX %100.1hX %100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1X %100.1lX %100.1llX %100.1hX %100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100.1u %100.1lu %100.1llu %100.1hu %100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.1u %100.1lu %100.1llu %100.1hu %100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_1_AND_precision_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_10_AND_precision_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1d %-10.1ld %-10.1lld %-10.1hd %-10.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1i %-10.1li %-10.1lli %-10.1hi %-10.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1o %-10.1lo %-10.1llo %-10.1ho %-10.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1x %-10.1lx %-10.1llx %-10.1hx %-10.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1X %-10.1lX %-10.1llX %-10.1hX %-10.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.1u %-10.1lu %-10.1llu %-10.1hu %-10.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_100_AND_precision_1) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count =
      sprintf(expected, "%-100.1d %-100.1ld %-100.1lld %-100.1hd %-100.1hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1d %-100.1ld %-100.1lld %-100.1hd %-100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1i %-100.1li %-100.1lli %-100.1hi %-100.1hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1i %-100.1li %-100.1lli %-100.1hi %-100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1o %-100.1lo %-100.1llo %-100.1ho %-100.1hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1o %-100.1lo %-100.1llo %-100.1ho %-100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1x %-100.1lx %-100.1llx %-100.1hx %-100.1hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1x %-100.1lx %-100.1llx %-100.1hx %-100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1X %-100.1lX %-100.1llX %-100.1hX %-100.1hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1X %-100.1lX %-100.1llX %-100.1hX %-100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1u %-100.1lu %-100.1llu %-100.1hu %-100.1hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1u %-100.1lu %-100.1llu %-100.1hu %-100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count =
      sprintf(expected, "%-100.1d %-100.1ld %-100.1lld %-100.1hd %-100.1hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1d %-100.1ld %-100.1lld %-100.1hd %-100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1i %-100.1li %-100.1lli %-100.1hi %-100.1hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1i %-100.1li %-100.1lli %-100.1hi %-100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1o %-100.1lo %-100.1llo %-100.1ho %-100.1hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1o %-100.1lo %-100.1llo %-100.1ho %-100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1x %-100.1lx %-100.1llx %-100.1hx %-100.1hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1x %-100.1lx %-100.1llx %-100.1hx %-100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1X %-100.1lX %-100.1llX %-100.1hX %-100.1hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1X %-100.1lX %-100.1llX %-100.1hX %-100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1u %-100.1lu %-100.1llu %-100.1hu %-100.1hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1u %-100.1lu %-100.1llu %-100.1hu %-100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count =
      sprintf(expected, "%-100.1d %-100.1ld %-100.1lld %-100.1hd %-100.1hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1d %-100.1ld %-100.1lld %-100.1hd %-100.1hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1i %-100.1li %-100.1lli %-100.1hi %-100.1hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1i %-100.1li %-100.1lli %-100.1hi %-100.1hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1o %-100.1lo %-100.1llo %-100.1ho %-100.1hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1o %-100.1lo %-100.1llo %-100.1ho %-100.1hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1x %-100.1lx %-100.1llx %-100.1hx %-100.1hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1x %-100.1lx %-100.1llx %-100.1hx %-100.1hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1X %-100.1lX %-100.1llX %-100.1hX %-100.1hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1X %-100.1lX %-100.1llX %-100.1hX %-100.1hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-100.1u %-100.1lu %-100.1llu %-100.1hu %-100.1hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-100.1u %-100.1lu %-100.1llu %-100.1hu %-100.1hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_1_AND_precision_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_10_AND_precision_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10d %10.10ld %10.10lld %10.10hd %10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10i %10.10li %10.10lli %10.10hi %10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10o %10.10lo %10.10llo %10.10ho %10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10x %10.10lx %10.10llx %10.10hx %10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10X %10.10lX %10.10llX %10.10hX %10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.10u %10.10lu %10.10llu %10.10hu %10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_100_AND_precision_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count =
      sprintf(expected, "%100.10d %100.10ld %100.10lld %100.10hd %100.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10d %100.10ld %100.10lld %100.10hd %100.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10i %100.10li %100.10lli %100.10hi %100.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10i %100.10li %100.10lli %100.10hi %100.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10o %100.10lo %100.10llo %100.10ho %100.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10o %100.10lo %100.10llo %100.10ho %100.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10x %100.10lx %100.10llx %100.10hx %100.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10x %100.10lx %100.10llx %100.10hx %100.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10X %100.10lX %100.10llX %100.10hX %100.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10X %100.10lX %100.10llX %100.10hX %100.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10u %100.10lu %100.10llu %100.10hu %100.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10u %100.10lu %100.10llu %100.10hu %100.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count =
      sprintf(expected, "%100.10d %100.10ld %100.10lld %100.10hd %100.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10d %100.10ld %100.10lld %100.10hd %100.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10i %100.10li %100.10lli %100.10hi %100.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10i %100.10li %100.10lli %100.10hi %100.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10o %100.10lo %100.10llo %100.10ho %100.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10o %100.10lo %100.10llo %100.10ho %100.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10x %100.10lx %100.10llx %100.10hx %100.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10x %100.10lx %100.10llx %100.10hx %100.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10X %100.10lX %100.10llX %100.10hX %100.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10X %100.10lX %100.10llX %100.10hX %100.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10u %100.10lu %100.10llu %100.10hu %100.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10u %100.10lu %100.10llu %100.10hu %100.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count =
      sprintf(expected, "%100.10d %100.10ld %100.10lld %100.10hd %100.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10d %100.10ld %100.10lld %100.10hd %100.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10i %100.10li %100.10lli %100.10hi %100.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10i %100.10li %100.10lli %100.10hi %100.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10o %100.10lo %100.10llo %100.10ho %100.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10o %100.10lo %100.10llo %100.10ho %100.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10x %100.10lx %100.10llx %100.10hx %100.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10x %100.10lx %100.10llx %100.10hx %100.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10X %100.10lX %100.10llX %100.10hX %100.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10X %100.10lX %100.10llX %100.10hX %100.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%100.10u %100.10lu %100.10llu %100.10hu %100.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%100.10u %100.10lu %100.10llu %100.10hu %100.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_1_AND_precision_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count =
      sprintf(expected, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count =
      sprintf(expected, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count =
      sprintf(expected, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_10_AND_precision_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count =
      sprintf(expected, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count =
      sprintf(expected, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count =
      sprintf(expected, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10d %-10.10ld %-10.10lld %-10.10hd %-10.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10i %-10.10li %-10.10lli %-10.10hi %-10.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10o %-10.10lo %-10.10llo %-10.10ho %-10.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10x %-10.10lx %-10.10llx %-10.10hx %-10.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10X %-10.10lX %-10.10llX %-10.10hX %-10.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%-10.10u %-10.10lu %-10.10llu %-10.10hu %-10.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_100_AND_precision_10) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected,
                  "%-100.10d %-100.10ld %-100.10lld %-100.10hd %-100.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10d %-100.10ld %-100.10lld %-100.10hd %-100.10hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10i %-100.10li %-100.10lli %-100.10hi %-100.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10i %-100.10li %-100.10lli %-100.10hi %-100.10hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10o %-100.10lo %-100.10llo %-100.10ho %-100.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10o %-100.10lo %-100.10llo %-100.10ho %-100.10hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10x %-100.10lx %-100.10llx %-100.10hx %-100.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10x %-100.10lx %-100.10llx %-100.10hx %-100.10hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10X %-100.10lX %-100.10llX %-100.10hX %-100.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10X %-100.10lX %-100.10llX %-100.10hX %-100.10hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10u %-100.10lu %-100.10llu %-100.10hu %-100.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10u %-100.10lu %-100.10llu %-100.10hu %-100.10hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected,
                  "%-100.10d %-100.10ld %-100.10lld %-100.10hd %-100.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10d %-100.10ld %-100.10lld %-100.10hd %-100.10hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10i %-100.10li %-100.10lli %-100.10hi %-100.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10i %-100.10li %-100.10lli %-100.10hi %-100.10hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10o %-100.10lo %-100.10llo %-100.10ho %-100.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10o %-100.10lo %-100.10llo %-100.10ho %-100.10hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10x %-100.10lx %-100.10llx %-100.10hx %-100.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10x %-100.10lx %-100.10llx %-100.10hx %-100.10hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10X %-100.10lX %-100.10llX %-100.10hX %-100.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10X %-100.10lX %-100.10llX %-100.10hX %-100.10hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10u %-100.10lu %-100.10llu %-100.10hu %-100.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10u %-100.10lu %-100.10llu %-100.10hu %-100.10hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected,
                  "%-100.10d %-100.10ld %-100.10lld %-100.10hd %-100.10hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10d %-100.10ld %-100.10lld %-100.10hd %-100.10hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10i %-100.10li %-100.10lli %-100.10hi %-100.10hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10i %-100.10li %-100.10lli %-100.10hi %-100.10hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10o %-100.10lo %-100.10llo %-100.10ho %-100.10hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10o %-100.10lo %-100.10llo %-100.10ho %-100.10hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10x %-100.10lx %-100.10llx %-100.10hx %-100.10hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10x %-100.10lx %-100.10llx %-100.10hx %-100.10hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10X %-100.10lX %-100.10llX %-100.10hX %-100.10hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10X %-100.10lX %-100.10llX %-100.10hX %-100.10hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-100.10u %-100.10lu %-100.10llu %-100.10hu %-100.10hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.10u %-100.10lu %-100.10llu %-100.10hu %-100.10hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_1_AND_precision_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count =
      sprintf(expected, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count =
      sprintf(expected, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count =
      sprintf(expected, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_10_AND_precision_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count =
      sprintf(expected, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count =
      sprintf(expected, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count =
      sprintf(expected, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100d %10.100ld %10.100lld %10.100hd %10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100i %10.100li %10.100lli %10.100hi %10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100o %10.100lo %10.100llo %10.100ho %10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100x %10.100lx %10.100llx %10.100hx %10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100X %10.100lX %10.100llX %10.100hX %10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
              regular_int, long_int, long_long_int, short_int, char_int);
  s21_count =
      s21_sprintf(buffer, "%10.100u %10.100lu %10.100llu %10.100hu %10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_100_AND_precision_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected,
                  "%100.100d %100.100ld %100.100lld %100.100hd %100.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100d %100.100ld %100.100lld %100.100hd %100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100i %100.100li %100.100lli %100.100hi %100.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100i %100.100li %100.100lli %100.100hi %100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100o %100.100lo %100.100llo %100.100ho %100.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100o %100.100lo %100.100llo %100.100ho %100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100x %100.100lx %100.100llx %100.100hx %100.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100x %100.100lx %100.100llx %100.100hx %100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100X %100.100lX %100.100llX %100.100hX %100.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100X %100.100lX %100.100llX %100.100hX %100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100u %100.100lu %100.100llu %100.100hu %100.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100u %100.100lu %100.100llu %100.100hu %100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected,
                  "%100.100d %100.100ld %100.100lld %100.100hd %100.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100d %100.100ld %100.100lld %100.100hd %100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100i %100.100li %100.100lli %100.100hi %100.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100i %100.100li %100.100lli %100.100hi %100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100o %100.100lo %100.100llo %100.100ho %100.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100o %100.100lo %100.100llo %100.100ho %100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100x %100.100lx %100.100llx %100.100hx %100.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100x %100.100lx %100.100llx %100.100hx %100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100X %100.100lX %100.100llX %100.100hX %100.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100X %100.100lX %100.100llX %100.100hX %100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100u %100.100lu %100.100llu %100.100hu %100.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100u %100.100lu %100.100llu %100.100hu %100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected,
                  "%100.100d %100.100ld %100.100lld %100.100hd %100.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100d %100.100ld %100.100lld %100.100hd %100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100i %100.100li %100.100lli %100.100hi %100.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100i %100.100li %100.100lli %100.100hi %100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100o %100.100lo %100.100llo %100.100ho %100.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100o %100.100lo %100.100llo %100.100ho %100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100x %100.100lx %100.100llx %100.100hx %100.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100x %100.100lx %100.100llx %100.100hx %100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100X %100.100lX %100.100llX %100.100hX %100.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100X %100.100lX %100.100llX %100.100hX %100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%100.100u %100.100lu %100.100llu %100.100hu %100.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%100.100u %100.100lu %100.100llu %100.100hu %100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_1_AND_precision_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected,
                  "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected,
                  "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected,
                  "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_10_AND_precision_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(expected,
                  "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(expected,
                  "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(expected,
                  "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100d %-10.100ld %-10.100lld %-10.100hd %-10.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100i %-10.100li %-10.100lli %-10.100hi %-10.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100o %-10.100lo %-10.100llo %-10.100ho %-10.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100x %-10.100lx %-10.100llx %-10.100hx %-10.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100X %-10.100lX %-10.100llX %-10.100hX %-10.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected,
                  "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
                  regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-10.100u %-10.100lu %-10.100llu %-10.100hu %-10.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_string_width_negative_100_AND_precision_100) {
  char buffer[5000];
  char expected[5000];
  int count, s21_count;

  //
  // Test with zero values
  //

  int regular_int = 0;
  long long_int = 0L;
  long long long_long_int = 0LL;
  short short_int = 0;
  char char_int = 0;

  count = sprintf(
      expected, "%-100.100d %-100.100ld %-100.100lld %-100.100hd %-100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100d %-100.100ld %-100.100lld %-100.100hd %-100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100i %-100.100li %-100.100lli %-100.100hi %-100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100i %-100.100li %-100.100lli %-100.100hi %-100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100o %-100.100lo %-100.100llo %-100.100ho %-100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100o %-100.100lo %-100.100llo %-100.100ho %-100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100x %-100.100lx %-100.100llx %-100.100hx %-100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100x %-100.100lx %-100.100llx %-100.100hx %-100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100X %-100.100lX %-100.100llX %-100.100hX %-100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100X %-100.100lX %-100.100llX %-100.100hX %-100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100u %-100.100lu %-100.100llu %-100.100hu %-100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100u %-100.100lu %-100.100llu %-100.100hu %-100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with maximum values
  //

  regular_int = INT_MAX;
  long_int = LONG_MAX;
  long_long_int = LLONG_MAX;
  short_int = SHRT_MAX;
  char_int = CHAR_MAX;

  count = sprintf(
      expected, "%-100.100d %-100.100ld %-100.100lld %-100.100hd %-100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100d %-100.100ld %-100.100lld %-100.100hd %-100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100i %-100.100li %-100.100lli %-100.100hi %-100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100i %-100.100li %-100.100lli %-100.100hi %-100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100o %-100.100lo %-100.100llo %-100.100ho %-100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100o %-100.100lo %-100.100llo %-100.100ho %-100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100x %-100.100lx %-100.100llx %-100.100hx %-100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100x %-100.100lx %-100.100llx %-100.100hx %-100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100X %-100.100lX %-100.100llX %-100.100hX %-100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100X %-100.100lX %-100.100llX %-100.100hX %-100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100u %-100.100lu %-100.100llu %-100.100hu %-100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100u %-100.100lu %-100.100llu %-100.100hu %-100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  //
  // Test with minimum values
  //

  regular_int = INT_MIN;
  long_int = LONG_MIN;
  long_long_int = LLONG_MIN;
  short_int = SHRT_MIN;
  char_int = CHAR_MIN;

  count = sprintf(
      expected, "%-100.100d %-100.100ld %-100.100lld %-100.100hd %-100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100d %-100.100ld %-100.100lld %-100.100hd %-100.100hhd",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100i %-100.100li %-100.100lli %-100.100hi %-100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100i %-100.100li %-100.100lli %-100.100hi %-100.100hhi",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100o %-100.100lo %-100.100llo %-100.100ho %-100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100o %-100.100lo %-100.100llo %-100.100ho %-100.100hho",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100x %-100.100lx %-100.100llx %-100.100hx %-100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100x %-100.100lx %-100.100llx %-100.100hx %-100.100hhx",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100X %-100.100lX %-100.100llX %-100.100hX %-100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100X %-100.100lX %-100.100llX %-100.100hX %-100.100hhX",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(
      expected, "%-100.100u %-100.100lu %-100.100llu %-100.100hu %-100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  s21_count = s21_sprintf(
      buffer, "%-100.100u %-100.100lu %-100.100llu %-100.100hu %-100.100hhu",
      regular_int, long_int, long_long_int, short_int, char_int);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

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

  tcase_add_test(tc_d, test_string_format);
  tcase_add_test(tc_d, test_string_plus);
  tcase_add_test(tc_d, test_string_space);

  tcase_add_test(tc_d, test_string_width_1);
  tcase_add_test(tc_d, test_string_width_10);
  tcase_add_test(tc_d, test_string_width_100);
  tcase_add_test(tc_d, test_string_width_negative_1);
  tcase_add_test(tc_d, test_string_width_negative_10);
  tcase_add_test(tc_d, test_string_width_negative_100);

  tcase_add_test(tc_d, test_string_width_1_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_10_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_100_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_negative_1_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_negative_10_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_negative_100_AND_precision_100);

  tcase_add_test(tc_d, test_string_precision_0);
  tcase_add_test(tc_d, test_string_precision_1);
  tcase_add_test(tc_d, test_string_precision_10);
  tcase_add_test(tc_d, test_string_precision_100);

  tcase_add_test(tc_d, test_string_width_1_AND_precision_0);
  tcase_add_test(tc_d, test_string_width_10_AND_precision_0);
  tcase_add_test(tc_d, test_string_width_100_AND_precision_0);
  tcase_add_test(tc_d, test_string_width_negative_1_AND_precision_0);
  tcase_add_test(tc_d, test_string_width_negative_10_AND_precision_0);
  tcase_add_test(tc_d, test_string_width_negative_100_AND_precision_0);
  tcase_add_test(tc_d, test_string_width_1_AND_precision_1);
  tcase_add_test(tc_d, test_string_width_10_AND_precision_1);
  tcase_add_test(tc_d, test_string_width_100_AND_precision_1);
  tcase_add_test(tc_d, test_string_width_negative_1_AND_precision_1);
  tcase_add_test(tc_d, test_string_width_negative_10_AND_precision_1);
  tcase_add_test(tc_d, test_string_width_negative_100_AND_precision_1);
  tcase_add_test(tc_d, test_string_width_1_AND_precision_10);
  tcase_add_test(tc_d, test_string_width_10_AND_precision_10);
  tcase_add_test(tc_d, test_string_width_100_AND_precision_10);
  tcase_add_test(tc_d, test_string_width_negative_1_AND_precision_10);
  tcase_add_test(tc_d, test_string_width_negative_10_AND_precision_10);
  tcase_add_test(tc_d, test_string_width_negative_100_AND_precision_10);
  tcase_add_test(tc_d, test_string_width_1_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_10_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_100_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_negative_1_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_negative_10_AND_precision_100);
  tcase_add_test(tc_d, test_string_width_negative_100_AND_precision_100);

  tcase_add_test(tc_d, test_count_specifier);

  suite_add_tcase(s, tc_d);

  return s;
}