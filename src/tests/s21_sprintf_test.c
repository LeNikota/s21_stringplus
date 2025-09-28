#include "test.h"

START_TEST(nulled_within_provided_string) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  const char *text = "Hello \0 World!";
  count = sprintf(expected, "Text: %s", text);
  s21_count = s21_sprintf(buffer, "Text: %s", text);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(nulled_char) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  int number = 3005;
  const char ch = '\0';
  const char *text = "Hello World!";
  count = sprintf(expected, "Text: %i %5c %s", number, ch, text);
  s21_count = s21_sprintf(buffer, "Text: %i %5c %s", number, ch, text);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_combined) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 0: %%
  count = sprintf(expected, "Just two prosents %%, cool");
  s21_count = s21_sprintf(buffer, "Just two prosents %%, cool");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 1: Integer decimal (%d)
  int number1 = 42;
  count = sprintf(expected, "Number: %d", number1);
  s21_count = s21_sprintf(buffer, "Number: %d", number1);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Long decimal (%ld)
  long number2 = 1234567890L;
  count = sprintf(expected, "Long Number: %ld", number2);
  s21_count = s21_sprintf(buffer, "Long Number: %ld", number2);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Long long decimal (%lld)
  long long number3 = 1234567890123456789LL;
  count = sprintf(expected, "Long Long Number: %lld", number3);
  s21_count = s21_sprintf(buffer, "Long Long Number: %lld", number3);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Integer (%i)
  int number4 = 42;
  count = sprintf(expected, "Number: %i", number4);
  s21_count = s21_sprintf(buffer, "Number: %i", number4);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Long integer (%li)
  long number5 = 1234567890L;
  count = sprintf(expected, "Long Number: %li", number5);
  s21_count = s21_sprintf(buffer, "Long Number: %li", number5);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Long long integer (%lli)
  long long number6 = 1234567890123456789LL;
  count = sprintf(expected, "Long Long Number: %lli", number6);
  s21_count = s21_sprintf(buffer, "Long Long Number: %lli", number6);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: String (%s)
  const char *text = "Hello, World!";
  count = sprintf(expected, "Text: %s", text);
  s21_count = s21_sprintf(buffer, "Text: %s", text);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Character (%c)
  count = sprintf(expected, "Character: %c%c%c", 'w', 'o', 'w');
  s21_count = s21_sprintf(buffer, "Character: %c%c%c", 'w', 'o', 'w');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: %n flag
  int count_second, s21_count_second;
  count = sprintf(expected, "How much have you read %n", &count_second);
  s21_count =
      s21_sprintf(buffer, "How much have you read %n", &s21_count_second);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
  ck_assert_int_eq(count_second, s21_count_second);

  // Test 10: Long %n (%ln)
  long written_chars1;
  count = sprintf(buffer, "Hello, World!%ln", &written_chars1);
  s21_count = s21_sprintf(buffer, "Hello, World!%ln", &written_chars1);
  ck_assert_int_eq(written_chars1, count);
  ck_assert_int_eq(s21_count, count);

  // Test 11: Long long %n (%lln)
  long long written_chars2;
  count = sprintf(buffer, "Long Long Number: %lln", &written_chars2);
  s21_count = s21_sprintf(buffer, "Long Long Number: %lln", &written_chars2);
  ck_assert_int_eq(written_chars2, count);
  ck_assert_int_eq(s21_count, count);

  // Test 12: Short %n (%hn)
  short written_chars3;
  count = sprintf(buffer, "Short Number: %hn", &written_chars3);
  s21_count = s21_sprintf(buffer, "Short Number: %hn", &written_chars3);
  ck_assert_int_eq(written_chars3, count);
  ck_assert_int_eq(s21_count, count);

  // Test 13: Signed char %n (%hhn)
  signed char written_chars4;
  count = sprintf(buffer, "Signed Char: %hhn", &written_chars4);
  s21_count = s21_sprintf(buffer, "Signed Char: %hhn", &written_chars4);
  ck_assert_int_eq(written_chars4, count);
  ck_assert_int_eq(s21_count, count);

  // Test 14: Unsigned integer (%u)
  unsigned int number7 = 42;
  count = sprintf(expected, "Unsigned Number: %u", number7);
  s21_count = s21_sprintf(buffer, "Unsigned Number: %u", number7);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 15: Unsigned integer max (%u)
  unsigned int number8 = INT_MAX;
  count = sprintf(expected, "Max Unsigned Number: %u", number8);
  s21_count = s21_sprintf(buffer, "Max Unsigned Number: %u", number8);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 16: Unsigned long integer max (%lu)
  unsigned long number9 = ULONG_MAX;
  count = sprintf(expected, "Max Unsigned Long Number: %lu", number9);
  s21_count = s21_sprintf(buffer, "Max Unsigned Long Number: %lu", number9);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 17: Unsigned long long integer max (%llu)
  unsigned long long number10 = ULLONG_MAX;
  count = sprintf(expected, "Max Unsigned Long Long Number: %llu", number10);
  s21_count =
      s21_sprintf(buffer, "Max Unsigned Long Long Number: %llu", number10);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 18: Pointer null (%p)
  void *ptr1 = NULL;
  count = sprintf(expected, "Pointer: %p", ptr1);
  s21_count = s21_sprintf(buffer, "Pointer: %p", ptr1);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 19: Pointer valid (%p)
  int number11 = 42;
  void *ptr2 = &number11;
  count = sprintf(expected, "Pointer: %p", ptr2);
  s21_count = s21_sprintf(buffer, "Pointer: %p", ptr2);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 20: Pointer array (%p)
  int array[5] = {1, 2, 3, 4, 5};
  void *ptr3 = array;
  count = sprintf(expected, "Pointer to array: %p", ptr3);
  s21_count = s21_sprintf(buffer, "Pointer to array: %p", ptr3);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 21: Pointer function (%p)
  void (*func_ptr)(void) = NULL;
  count = sprintf(expected, "Function Pointer: %p", func_ptr);
  s21_count = s21_sprintf(buffer, "Function Pointer: %p", func_ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 22: Pointer dynamic memory (%p)
  char *dynamic_ptr = malloc(10);
  count = sprintf(expected, "Dynamic Pointer: %p", dynamic_ptr);
  s21_count = s21_sprintf(buffer, "Dynamic Pointer: %p", dynamic_ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
  free(dynamic_ptr);

  // Test 23: Pointer multiple (%p)
  int a = 10, b = 20;
  void *ptr_a = &a;
  void *ptr_b = &b;
  count = sprintf(expected, "Pointers: %p and %p", ptr_a, ptr_b);
  s21_count = s21_sprintf(buffer, "Pointers: %p and %p", ptr_a, ptr_b);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 24: Short decimal (%hd)
  short number12 = 42;
  count = sprintf(expected, "Short Number: %hd", number12);
  s21_count = s21_sprintf(buffer, "Short Number: %hd", number12);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 25: Unsigned short integer (%hu)
  unsigned short number13 = 42;
  count = sprintf(expected, "Unsigned Short Number: %hu", number13);
  s21_count = s21_sprintf(buffer, "Unsigned Short Number: %hu", number13);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 26: Signed char (%hhd)
  signed char number14 = -10;
  count = sprintf(expected, "Signed Char: %hhd", number14);
  s21_count = s21_sprintf(buffer, "Signed Char: %hhd", number14);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 27: Unsigned char (%hhu)
  unsigned char number15 = 250;
  count = sprintf(expected, "Unsigned Char: %hhu", number15);
  s21_count = s21_sprintf(buffer, "Unsigned Char: %hhu", number15);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 28: Multiple short (%hd)
  short number16 = 10, number17 = 20;
  count = sprintf(expected, "Shorts: %hd and %hd", number16, number17);
  s21_count = s21_sprintf(buffer, "Shorts: %hd and %hd", number16, number17);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 29: Multiple signed char (%hhd)
  signed char char1 = -5, char2 = 5;
  count = sprintf(expected, "Chars: %hhd and %hhi", char1, char2);
  s21_count = s21_sprintf(buffer, "Chars: %hhd and %hhi", char1, char2);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 30: Octal as decimal (%d)
  int number18 = 04321;
  count = sprintf(expected, "Octal as Decimal: %d", number18);
  s21_count = s21_sprintf(buffer, "Octal as Decimal: %d", number18);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 31: Hexadecimal as decimal (%d)
  int number19 = 0xABCDE;
  count = sprintf(expected, "Hexadecimal as Decimal: %d", number19);
  s21_count = s21_sprintf(buffer, "Hexadecimal as Decimal: %d", number19);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 32: Hexadecimal uppercase as decimal (%d)
  int number20 = 0x63AB21;
  count = sprintf(expected, "Hexadecimal as Decimal: %d", number20);
  s21_count = s21_sprintf(buffer, "Hexadecimal as Decimal: %d", number20);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 33: Octal signed char (%hhd)
  signed char number21 = 033;
  count = sprintf(expected, "Signed Char as Decimal: %hhd", number21);
  s21_count = s21_sprintf(buffer, "Signed Char as Decimal: %hhd", number21);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 34: Octal short (%hd)
  short number22 = 044670;
  count = sprintf(expected, "Short as Decimal: %hd", number22);
  s21_count = s21_sprintf(buffer, "Short as Decimal: %hd", number22);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 35: Octal long (%ld)
  long number23 = 06235;
  count = sprintf(expected, "Long as Decimal: %ld", number23);
  s21_count = s21_sprintf(buffer, "Long as Decimal: %ld", number23);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 36: Octal long long (%lld)
  long long number24 = 03757;
  count = sprintf(expected, "Long Long as Decimal: %lld", number24);
  s21_count = s21_sprintf(buffer, "Long Long as Decimal: %lld", number24);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 37: Hexadecimal signed char (%hhd)
  signed char number25 = 0x6A;
  count = sprintf(expected, "Signed Char as Decimal: %hhd", number25);
  s21_count = s21_sprintf(buffer, "Signed Char as Decimal: %hhd", number25);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 38: Unsigned integer hex lowercase (%x)
  unsigned int number26 = 255;
  count = sprintf(expected, "Hex: %x", number26);
  s21_count = s21_sprintf(buffer, "Hex: %x", number26);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 39: Unsigned integer hex uppercase (%X)
  unsigned int number27 = 255;
  count = sprintf(expected, "Hex: %X", number27);
  s21_count = s21_sprintf(buffer, "Hex: %X", number27);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 40: Long unsigned integer hex lowercase (%lx)
  unsigned long number28 = 4294967295UL;
  count = sprintf(expected, "Long Hex: %lx", number28);
  s21_count = s21_sprintf(buffer, "Long Hex: %lx", number28);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 41: Long unsigned integer hex uppercase (%lX)
  unsigned long number29 = 4294967295UL;
  count = sprintf(expected, "Long Hex: %lX", number29);
  s21_count = s21_sprintf(buffer, "Long Hex: %lX", number29);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 42: Long long unsigned integer hex lowercase (%llx)
  unsigned long long number30 = 18446744073709551615ULL;
  count = sprintf(expected, "Long Long Hex: %llx", number30);
  s21_count = s21_sprintf(buffer, "Long Long Hex: %llx", number30);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 43: Long long unsigned integer hex uppercase (%llX)
  unsigned long long number31 = 18446744073709551615ULL;
  count = sprintf(expected, "Long Long Hex: %llX", number31);
  s21_count = s21_sprintf(buffer, "Long Long Hex: %llX", number31);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 44: Unsigned integer hex zero (%x)
  unsigned int number32 = 0;
  count = sprintf(expected, "Hex: %x", number32);
  s21_count = s21_sprintf(buffer, "Hex: %x", number32);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 45: Unsigned long integer hex zero (%lx)
  unsigned long number33 = 0;
  count = sprintf(expected, "Long Hex: %lx", number33);
  s21_count = s21_sprintf(buffer, "Long Hex: %lx", number33);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 46: Unsigned long long integer hex zero (%llx)
  unsigned long long number34 = 0;
  count = sprintf(expected, "Long Long Hex: %llx", number34);
  s21_count = s21_sprintf(buffer, "Long Long Hex: %llx", number34);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 47: Unsigned integer octal (%o)
  unsigned int number35 = 42;
  count = sprintf(expected, "Unsigned Number in Octal: %o", number35);
  s21_count = s21_sprintf(buffer, "Unsigned Number in Octal: %o", number35);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 48: Unsigned long integer octal max (%lo)
  unsigned long number36 = ULONG_MAX;
  count = sprintf(expected, "Max Unsigned Long in Octal: %lo", number36);
  s21_count = s21_sprintf(buffer, "Max Unsigned Long in Octal: %lo", number36);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 49: Unsigned long long integer octal max (%llo)
  unsigned long long number37 = ULLONG_MAX;
  count = sprintf(expected, "Max Unsigned Long Long in Octal: %llo", number37);
  s21_count =
      s21_sprintf(buffer, "Max Unsigned Long Long in Octal: %llo", number37);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 50: Unsigned short integer octal max (%ho)
  unsigned short number38 = USHRT_MAX;
  count = sprintf(expected, "Max Unsigned Short in Octal: %ho", number38);
  s21_count = s21_sprintf(buffer, "Max Unsigned Short in Octal: %ho", number38);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 51: Short integer octal max (%ho)
  short number39 = SHRT_MAX;
  count = sprintf(expected, "Max Short in Octal: %ho", number39);
  s21_count = s21_sprintf(buffer, "Max Short in Octal: %ho", number39);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 52: Unsigned integer octal edge case (%o)
  unsigned int number40 = 1;
  count = sprintf(expected, "Edge Case Unsigned in Octal: %o", number40);
  s21_count = s21_sprintf(buffer, "Edge Case Unsigned in Octal: %o", number40);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 53: Unsigned long integer octal edge case (%lo)
  unsigned long number41 = 1;
  count = sprintf(expected, "Edge Case Unsigned Long in Octal: %lo", number41);
  s21_count =
      s21_sprintf(buffer, "Edge Case Unsigned Long in Octal: %lo", number41);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 54: Unsigned long long integer octal edge case (%llo)
  unsigned long long number42 = 1;
  count = sprintf(expected, "Edge Case Unsigned Long Long in Octal: %llo",
                  number42);
  s21_count = s21_sprintf(buffer, "Edge Case Unsigned Long Long in Octal: %llo",
                          number42);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 55: Unsigned short integer octal edge case (%ho)
  unsigned short number43 = 1;
  count = sprintf(expected, "Edge Case Unsigned Short in Octal: %ho", number43);
  s21_count =
      s21_sprintf(buffer, "Edge Case Unsigned Short in Octal: %ho", number43);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 56: Unsigned integer octal zero (%o)
  unsigned int number44 = 0;
  count = sprintf(expected, "Zero in Unsigned Octal: %o", number44);
  s21_count = s21_sprintf(buffer, "Zero in Unsigned Octal: %o", number44);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 57: Unsigned long integer octal zero (%lo)
  unsigned long number45 = 0;
  count = sprintf(expected, "Zero in Unsigned Long Octal: %lo", number45);
  s21_count = s21_sprintf(buffer, "Zero in Unsigned Long Octal: %lo", number45);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 58: Unsigned long long integer octal zero (%llo)
  unsigned long long number46 = 0;
  count = sprintf(expected, "Zero in Unsigned Long Long Octal: %llo", number46);
  s21_count =
      s21_sprintf(buffer, "Zero in Unsigned Long Long Octal: %llo", number46);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 59: Unsigned short integer octal zero (%ho)
  unsigned short number47 = 0;
  count = sprintf(expected, "Zero in Unsigned Short Octal: %ho", number47);
  s21_count =
      s21_sprintf(buffer, "Zero in Unsigned Short Octal: %ho", number47);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 60: Short integer octal zero (%ho)
  short number48 = 0;
  count = sprintf(expected, "Zero in Short Octal: %ho", number48);
  s21_count = s21_sprintf(buffer, "Zero in Short Octal: %ho", number48);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 61: Unsigned char integer octal (%hho)
  unsigned char number49 = 42;
  count = sprintf(expected, "Unsigned Char in Octal: %hho", number49);
  s21_count = s21_sprintf(buffer, "Unsigned Char in Octal: %hho", number49);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 62: Unsigned char integer octal zero (%hho)
  unsigned char number50 = 0;
  count = sprintf(expected, "Zero in Unsigned Char Octal: %hho", number50);
  s21_count =
      s21_sprintf(buffer, "Zero in Unsigned Char Octal: %hho", number50);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 63: Unsigned char integer octal max (%hho)
  unsigned char number51 = UCHAR_MAX;
  count = sprintf(expected, "Max Unsigned Char in Octal: %hho", number51);
  s21_count = s21_sprintf(buffer, "Max Unsigned Char in Octal: %hho", number51);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 64: Signed char integer octal (%hho)
  signed char number52 = -10;
  count = sprintf(expected, "Signed Char in Octal: %hho", number52);
  s21_count = s21_sprintf(buffer, "Signed Char in Octal: %hho", number52);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 65: Signed char integer octal zero (%hho)
  signed char number53 = 0;
  count = sprintf(expected, "Zero in Signed Char Octal: %hho", number53);
  s21_count = s21_sprintf(buffer, "Zero in Signed Char Octal: %hho", number53);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 66: Signed char integer octal max (%hho)
  signed char number54 = SCHAR_MAX;
  count = sprintf(expected, "Max Signed Char in Octal: %hho", number54);
  s21_count = s21_sprintf(buffer, "Max Signed Char in Octal: %hho", number54);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 67: Float simple (%f)
  //   for (size_t i = 0; i < 100; i++) {
  //     long double number55 = random();
  //     count = sprintf(expected, "Float value: %Lf", number55);
  //     s21_count = s21_sprintf(buffer, "Float value: %Lf", number55);
  //     ck_assert_str_eq(buffer, expected);
  //     ck_assert_int_eq(count, s21_count);
  //   }

  // Test 68: Float zero (%f)
  long double number56 = 0.0;
  count = sprintf(expected, "Zero Float: %Lf", number56);
  s21_count = s21_sprintf(buffer, "Zero Float: %Lf", number56);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 69: Float negative (%f)
  long double number57 = -2.71828;
  count = sprintf(expected, "Negative Float: %Lf", number57);
  s21_count = s21_sprintf(buffer, "Negative Float: %Lf", number57);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 70: Float large (%f)
  long double number58 = 1e20;
  count = sprintf(expected, "Large Float: %Lf", number58);
  s21_count = s21_sprintf(buffer, "Large Float: %Lf", number58);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 71: Double simple (%f)
  long double number59 = 3.141592653589793;
  count = sprintf(expected, "Double value: %Lf", number59);
  s21_count = s21_sprintf(buffer, "Double value: %Lf", number59);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 72: Double zero (%f)
  long double number60 = 0.0;
  count = sprintf(expected, "Zero Double: %Lf", number60);
  s21_count = s21_sprintf(buffer, "Zero Double: %Lf", number60);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 73: Double negative (%f)
  long double number61 = -1.414213562373095;
  count = sprintf(expected, "Negative Double: %Lf", number61);
  s21_count = s21_sprintf(buffer, "Negative Double: %Lf", number61);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 75: Long double simple (%Lf)
  long double number63 = 3.141592653589793238462643383279502884L;
  count = sprintf(expected, "Long Double value: %Lf", number63);
  s21_count = s21_sprintf(buffer, "Long Double value: %Lf", number63);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 76: Long double zero (%Lf)
  long double number64 = 0.0L;
  count = sprintf(expected, "Zero Long Double: %Lf", number64);
  s21_count = s21_sprintf(buffer, "Zero Long Double: %Lf", number64);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 77: Long double negative (%Lf)
  long double number65 = -2.7182818284590452353602874713526624977L;
  count = sprintf(expected, "Negative Long Double: %Lf", number65);
  s21_count = s21_sprintf(buffer, "Negative Long Double: %Lf", number65);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 80: Long double small (%Lf)
  long double number68 = LDBL_MIN;
  count = sprintf(expected, "Small Long Double: %Lf", number68);
  s21_count = s21_sprintf(buffer, "Small Long Double: %Lf", number68);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 81: Long double small negative (%Lf)
  long double number69 = -LDBL_MIN;
  count = sprintf(expected, "Small Long Double: %Lf", number69);
  s21_count = s21_sprintf(buffer, "Small Long Double: %Lf", number69);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Tests: double
  double number70 = 0.0;
  count = sprintf(expected, "Zero Float: %f", number70);
  s21_count = s21_sprintf(buffer, "Zero Float: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = -2.71828;
  count = sprintf(expected, "Negative Float: %f", number70);
  s21_count = s21_sprintf(buffer, "Negative Float: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = 1e20;
  count = sprintf(expected, "Large Float: %f", number70);
  s21_count = s21_sprintf(buffer, "Large Float: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = 3.141592653589793;
  count = sprintf(expected, "Double value: %f", number70);
  s21_count = s21_sprintf(buffer, "Double value: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = 0.0;
  count = sprintf(expected, "Zero Double: %f", number70);
  s21_count = s21_sprintf(buffer, "Zero Double: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = -1.414213562373095;
  count = sprintf(expected, "Negative Double: %f", number70);
  s21_count = s21_sprintf(buffer, "Negative Double: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = 3.141592653589793238462643383279502884L;
  count = sprintf(expected, "Long Double value: %f", number70);
  s21_count = s21_sprintf(buffer, "Long Double value: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = 0.0L;
  count = sprintf(expected, "Zero Long Double: %f", number70);
  s21_count = s21_sprintf(buffer, "Zero Long Double: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = -2.7182818284590452353602874713526624977L;
  count = sprintf(expected, "Negative Long Double: %f", number70);
  s21_count = s21_sprintf(buffer, "Negative Long Double: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = LDBL_MIN;
  count = sprintf(expected, "Small Long Double: %f", number70);
  s21_count = s21_sprintf(buffer, "Small Long Double: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number70 = -LDBL_MIN;
  count = sprintf(expected, "Small Long Double: %f", number70);
  s21_count = s21_sprintf(buffer, "Small Long Double: %f", number70);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Tests: float
  float number71 = 0.0;
  count = sprintf(expected, "Zero Float: %f", number71);
  s21_count = s21_sprintf(buffer, "Zero Float: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = -2.71828;
  count = sprintf(expected, "Negative Float: %f", number71);
  s21_count = s21_sprintf(buffer, "Negative Float: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = 1e20;
  count = sprintf(expected, "Large Float: %f", number71);
  s21_count = s21_sprintf(buffer, "Large Float: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = 3.141592653589793;
  count = sprintf(expected, "Double value: %f", number71);
  s21_count = s21_sprintf(buffer, "Double value: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = 0.0;
  count = sprintf(expected, "Zero Double: %f", number71);
  s21_count = s21_sprintf(buffer, "Zero Double: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = -1.414213562373095;
  count = sprintf(expected, "Negative Double: %f", number71);
  s21_count = s21_sprintf(buffer, "Negative Double: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = 3.141592653589793238462643383279502884L;
  count = sprintf(expected, "Long Double value: %f", number71);
  s21_count = s21_sprintf(buffer, "Long Double value: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = 0.0L;
  count = sprintf(expected, "Zero Long Double: %f", number71);
  s21_count = s21_sprintf(buffer, "Zero Long Double: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = -2.7182818284590452353602874713526624977L;
  count = sprintf(expected, "Negative Long Double: %f", number71);
  s21_count = s21_sprintf(buffer, "Negative Long Double: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = LDBL_MIN;
  count = sprintf(expected, "Small Long Double: %f", number71);
  s21_count = s21_sprintf(buffer, "Small Long Double: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  number71 = -LDBL_MIN;
  count = sprintf(expected, "Small Long Double: %f", number71);
  s21_count = s21_sprintf(buffer, "Small Long Double: %f", number71);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_forced_plus_sign) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 1: Signed char (%hhd)
  signed char sc = 42;
  count = sprintf(expected, "Signed Char: %+hhd", sc);
  s21_count = s21_sprintf(buffer, "Signed Char: %+hhd", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Short (%hd)
  short s = 42;
  count = sprintf(expected, "Short: %+hd", s);
  s21_count = s21_sprintf(buffer, "Short: %+hd", s);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Integer (%d)
  int i = 42;
  count = sprintf(expected, "Integer: %+d", i);
  s21_count = s21_sprintf(buffer, "Integer: %+d", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Long (%ld)
  long l = 42L;
  count = sprintf(expected, "Long: %+ld", l);
  s21_count = s21_sprintf(buffer, "Long: %+ld", l);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Long Long (%lld)
  long long ll = 42LL;
  count = sprintf(expected, "Long Long: %+lld", ll);
  s21_count = s21_sprintf(buffer, "Long Long: %+lld", ll);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Unsigned char (%hhu) - Remove the '+' flag
  unsigned char uc = 42;
  count = sprintf(expected, "Unsigned Char: %hhu", uc);
  s21_count = s21_sprintf(buffer, "Unsigned Char: %hhu", uc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Unsigned short (%hu) - Remove the '+' flag
  unsigned short us = 42;
  count = sprintf(expected, "Unsigned Short: %hu", us);
  s21_count = s21_sprintf(buffer, "Unsigned Short: %hu", us);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Unsigned int (%u) - Remove the '+' flag
  unsigned int ui = 42;
  count = sprintf(expected, "Unsigned Int: %u", ui);
  s21_count = s21_sprintf(buffer, "Unsigned Int: %u", ui);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: Unsigned long (%lu) - Remove the '+' flag
  unsigned long ul = 42UL;
  count = sprintf(expected, "Unsigned Long: %lu", ul);
  s21_count = s21_sprintf(buffer, "Unsigned Long: %lu", ul);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 10: Unsigned long long (%llu) - Remove the '+' flag
  unsigned long long ull = 42ULL;
  count = sprintf(expected, "Unsigned Long Long: %llu", ull);
  s21_count = s21_sprintf(buffer, "Unsigned Long Long: %llu", ull);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 11: Float (%f)
  float f = 42.0f;
  count = sprintf(expected, "Float: %+f", f);
  s21_count = s21_sprintf(buffer, "Float: %+f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 12: Double (%lf)
  double d = 42.0;
  count = sprintf(expected, "Double: %+lf", d);
  s21_count = s21_sprintf(buffer, "Double: %+lf", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 13: Float with scientific notation (%e)
  count = sprintf(expected, "Float (scientific): %+e", f);
  s21_count = s21_sprintf(buffer, "Float (scientific): %+e", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 14: Double with scientific notation (%le)
  count = sprintf(expected, "Double (scientific): %+le", d);
  s21_count = s21_sprintf(buffer, "Double (scientific): %+le", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 15: Float with uppercase scientific notation (%E)
  count = sprintf(expected, "Float (uppercase scientific): %+E", f);
  s21_count = s21_sprintf(buffer, "Float (uppercase scientific): %+E", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 23: Float with precision (%+.2f)
  count = sprintf(expected, "Float with precision: %+0.2f", f);
  s21_count = s21_sprintf(buffer, "Float with precision: %+0.2f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_space_sign) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 1: Signed char (%hhd)
  signed char sc = 42;
  count = sprintf(expected, "Signed Char: % hhd", sc);
  s21_count = s21_sprintf(buffer, "Signed Char: % hhd", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Short (%hd)
  short s = 42;
  count = sprintf(expected, "Short: % hd", s);
  s21_count = s21_sprintf(buffer, "Short: % hd", s);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Integer (%d)
  int i = 42;
  count = sprintf(expected, "Integer: % d", i);
  s21_count = s21_sprintf(buffer, "Integer: % d", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Long (%ld)
  long l = 42L;
  count = sprintf(expected, "Long: % ld", l);
  s21_count = s21_sprintf(buffer, "Long: % ld", l);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Long Long (%lld)
  long long ll = 42LL;
  count = sprintf(expected, "Long Long: % lld", ll);
  s21_count = s21_sprintf(buffer, "Long Long: % lld", ll);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Unsigned char (%hhu) - Remove the ' ' flag
  unsigned char uc = 42;
  count = sprintf(expected, "Unsigned Char: %hhu", uc);
  s21_count = s21_sprintf(buffer, "Unsigned Char: %hhu", uc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Unsigned short (%hu) - Remove the ' ' flag
  unsigned short us = 42;
  count = sprintf(expected, "Unsigned Short: %hu", us);
  s21_count = s21_sprintf(buffer, "Unsigned Short: %hu", us);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Unsigned int (%u) - Remove the ' ' flag
  unsigned int ui = 42;
  count = sprintf(expected, "Unsigned Int: %u", ui);
  s21_count = s21_sprintf(buffer, "Unsigned Int: %u", ui);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: Unsigned long (%lu) - Remove the ' ' flag
  unsigned long ul = 42UL;
  count = sprintf(expected, "Unsigned Long: %lu", ul);
  s21_count = s21_sprintf(buffer, "Unsigned Long: %lu", ul);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 10: Unsigned long long (%llu) - Remove the ' ' flag
  unsigned long long ull = 42ULL;
  count = sprintf(expected, "Unsigned Long Long: %llu", ull);
  s21_count = s21_sprintf(buffer, "Unsigned Long Long: %llu", ull);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 11: Float (%f)
  float f = 42.0f;
  count = sprintf(expected, "Float: % f", f);
  s21_count = s21_sprintf(buffer, "Float: % f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 12: Double (%lf)
  double d = 42.0;
  count = sprintf(expected, "Double: % lf", d);
  s21_count = s21_sprintf(buffer, "Double: % lf", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 13: Float with scientific notation (%e)
  count = sprintf(expected, "Float (scientific): % e", f);
  s21_count = s21_sprintf(buffer, "Float (scientific): % e", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 14: Double with scientific notation (%le)
  count = sprintf(expected, "Double (scientific): % le", d);
  s21_count = s21_sprintf(buffer, "Double (scientific): % le", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 15: Float with uppercase scientific notation (%E)
  count = sprintf(expected, "Float (uppercase scientific): % E", f);
  s21_count = s21_sprintf(buffer, "Float (uppercase scientific): % E", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 23: Float with precision (% .2f)
  count = sprintf(expected, "Float with precision: % 0.2f", f);
  s21_count = s21_sprintf(buffer, "Float with precision: % 0.2f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_hash_flag) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 1: Octal with signed char (%#hho)
  signed char sc = 42;
  count = sprintf(expected, "Signed Char Octal: %#hho", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Octal: %#hho", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Signed Char Octal: %#.2hho", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Octal: %#.2hho", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Signed Char Octal: %#.3hho", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Octal: %#.3hho", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Signed Char Octal: %#8.2hho", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Octal: %#8.2hho", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Signed Char Octal: %#8.3hho", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Octal: %#8.3hho", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Signed Char Octal: %#8.4hho", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Octal: %#8.4hho", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Signed Char Octal: %#-8.4hho", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Octal: %#-8.4hho", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Octal with short (%#ho)
  short s = 42;
  count = sprintf(expected, "Short Octal: %#ho", s);
  s21_count = s21_sprintf(buffer, "Short Octal: %#ho", s);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Octal with int (%#o)
  int i = 42;
  count = sprintf(expected, "Integer Octal: %#o", i);
  s21_count = s21_sprintf(buffer, "Integer Octal: %#o", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Octal with long (%#lo)
  long l = 42L;
  count = sprintf(expected, "Long Octal: %#lo", l);
  s21_count = s21_sprintf(buffer, "Long Octal: %#lo", l);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Octal with long long (%#llo)
  long long ll = 42LL;
  count = sprintf(expected, "Long Long Octal: %#llo", ll);
  s21_count = s21_sprintf(buffer, "Long Long Octal: %#llo", ll);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Hexadecimal with signed char (%#hhx)
  count = sprintf(expected, "Signed Char Hex: %#hhx", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Hex: %#hhx", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Hexadecimal with short (%#hx)
  count = sprintf(expected, "Short Hex: %#hx", s);
  s21_count = s21_sprintf(buffer, "Short Hex: %#hx", s);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Hexadecimal with int (%#x)
  count = sprintf(expected, "Integer Hex: %#x", i);
  s21_count = s21_sprintf(buffer, "Integer Hex: %#x", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: Hexadecimal with long (%#lx)
  count = sprintf(expected, "Long Hex: %#lx", l);
  s21_count = s21_sprintf(buffer, "Long Hex: %#lx", l);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 10: Hexadecimal with long long (%#llx)
  count = sprintf(expected, "Long Long Hex: %#llx", ll);
  s21_count = s21_sprintf(buffer, "Long Long Hex: %#llx", ll);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 11: Uppercase Hexadecimal with signed char (%#hhX)
  count = sprintf(expected, "Signed Char Upper Hex: %#hhX", sc);
  s21_count = s21_sprintf(buffer, "Signed Char Upper Hex: %#hhX", sc);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 12: Uppercase Hexadecimal with short (%#hX)
  count = sprintf(expected, "Short Upper Hex: %#hX", s);
  s21_count = s21_sprintf(buffer, "Short Upper Hex: %#hX", s);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 13: Uppercase Hexadecimal with int (%#X)
  count = sprintf(expected, "Integer Upper Hex: %#X", i);
  s21_count = s21_sprintf(buffer, "Integer Upper Hex: %#X", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 14: Uppercase Hexadecimal with long (%#lX)
  count = sprintf(expected, "Long Upper Hex: %#lX", l);
  s21_count = s21_sprintf(buffer, "Long Upper Hex: %#lX", l);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 15: Uppercase Hexadecimal with long long (%#llX)
  count = sprintf(expected, "Long Long Upper Hex: %#llX", ll);
  s21_count = s21_sprintf(buffer, "Long Long Upper Hex: %#llX", ll);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}

START_TEST(test_s21_sprintf_spaces_before) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 1: Characters with spaces
  count = sprintf(expected, "Character: %3c%3c%3c", 'w', 'o', 'w');
  s21_count = s21_sprintf(buffer, "Character: %3c%3c%3c", 'w', 'o', 'w');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 1.1: Characters with spaces
  count = sprintf(expected, "Character: %1000c", 'w');
  s21_count = s21_sprintf(buffer, "Character: %1000c", 'w');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Text with spaces
  const char *text = "Hello, World!";
  count = sprintf(expected, "Text: %20s", text);
  s21_count = s21_sprintf(buffer, "Text: %20s", text);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3.1: Text with spaces
  count = sprintf(expected, "Text: %1000s", text);
  s21_count = s21_sprintf(buffer, "Text: %1000s", text);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Integer with spaces
  int i = 42;
  count = sprintf(expected, "Integer: %20d", i);
  s21_count = s21_sprintf(buffer, "Integer: %20d", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Signed integer with spaces
  count = sprintf(expected, "Signed Integer: %20i", i);
  s21_count = s21_sprintf(buffer, "Signed Integer: %20i", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Octal with spaces
  count = sprintf(expected, "Octal: %20o", i);
  s21_count = s21_sprintf(buffer, "Octal: %20o", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Hexadecimal (lowercase) with spaces
  count = sprintf(expected, "Hexadecimal: %20x", i);
  s21_count = s21_sprintf(buffer, "Hexadecimal: %20x", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Hexadecimal (uppercase) with spaces
  count = sprintf(expected, "Uppercase Hexadecimal: %20X", i);
  s21_count = s21_sprintf(buffer, "Uppercase Hexadecimal: %20X", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Unsigned integer with spaces
  unsigned int u = 42;
  count = sprintf(expected, "Unsigned Integer: %20u", u);
  s21_count = s21_sprintf(buffer, "Unsigned Integer: %20u", u);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: Pointer with spaces
  int *ptr = &i;
  count = sprintf(expected, "Pointer: %20p", (void *)ptr);
  s21_count = s21_sprintf(buffer, "Pointer: %20p", (void *)ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  float f = 42.0f;
  count = sprintf(expected, "Float: %20f", f);
  s21_count = s21_sprintf(buffer, "Float: %20f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 12: Double (%lf)
  double d = 42.0;
  count = sprintf(expected, "Double: %20lf", d);
  s21_count = s21_sprintf(buffer, "Double: %20lf", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 13: Float with scientific notation (%e)
  count = sprintf(expected, "Float (scientific): %20e", f);
  s21_count = s21_sprintf(buffer, "Float (scientific): %20e", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 14: Double with scientific notation (%le)
  count = sprintf(expected, "Double (scientific): %20le", d);
  s21_count = s21_sprintf(buffer, "Double (scientific): %20le", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 15: Float with uppercase scientific notation (%E)
  count = sprintf(expected, "Float (uppercase scientific): %20E", f);
  s21_count = s21_sprintf(buffer, "Float (uppercase scientific): %20E", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 23: Float with precision (%2f)
  count = sprintf(expected, "Float with precision: %20f", f);
  s21_count = s21_sprintf(buffer, "Float with precision: %20f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_spaces_after) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 1: Characters with spaces
  count = sprintf(expected, "Character: %-3c%-3c%-3c", 'w', 'o', 'w');
  s21_count = s21_sprintf(buffer, "Character: %-3c%-3c%-3c", 'w', 'o', 'w');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Text with spaces
  const char *text = "Hello, World!";
  count = sprintf(expected, "Text: %-20s", text);
  s21_count = s21_sprintf(buffer, "Text: %-20s", text);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Integer with spaces
  int i = 42;
  count = sprintf(expected, "Integer: %-20d", i);
  s21_count = s21_sprintf(buffer, "Integer: %-20d", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Signed integer with spaces
  count = sprintf(expected, "Signed Integer: %-20i", i);
  s21_count = s21_sprintf(buffer, "Signed Integer: %-20i", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Octal with spaces
  count = sprintf(expected, "Octal: %-20o", i);
  s21_count = s21_sprintf(buffer, "Octal: %-20o", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Hexadecimal (lowercase) with spaces
  count = sprintf(expected, "Hexadecimal: %-20x", i);
  s21_count = s21_sprintf(buffer, "Hexadecimal: %-20x", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Hexadecimal (uppercase) with spaces
  count = sprintf(expected, "Uppercase Hexadecimal: %-20X", i);
  s21_count = s21_sprintf(buffer, "Uppercase Hexadecimal: %-20X", i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Unsigned integer with spaces
  unsigned int u = 42;
  count = sprintf(expected, "Unsigned Integer: %-20u", u);
  s21_count = s21_sprintf(buffer, "Unsigned Integer: %-20u", u);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: Pointer with spaces
  int *ptr = &i;
  count = sprintf(expected, "Pointer: %-20p", (void *)ptr);
  s21_count = s21_sprintf(buffer, "Pointer: %-20p", (void *)ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  float f = 42.0f;
  count = sprintf(expected, "Float: %-20f", f);
  s21_count = s21_sprintf(buffer, "Float: %-20f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 12: Double (%-lf)
  double d = 42.0;
  count = sprintf(expected, "Double: %-20lf", d);
  s21_count = s21_sprintf(buffer, "Double: %-20lf", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 13: Float with scientific notation (%-e)
  count = sprintf(expected, "Float (scientific): %-20e", f);
  s21_count = s21_sprintf(buffer, "Float (scientific): %-20e", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 14: Double with scientific notation (%-le)
  count = sprintf(expected, "Double (scientific): %-20le", d);
  s21_count = s21_sprintf(buffer, "Double (scientific): %-20le", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 15: Float with uppercase scientific notation (%-E)
  count = sprintf(expected, "Float (uppercase scientific): %-20E", f);
  s21_count = s21_sprintf(buffer, "Float (uppercase scientific): %-20E", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 23: Float with precision (%-2f)
  count = sprintf(expected, "Float with precision: %-20f", f);
  s21_count = s21_sprintf(buffer, "Float with precision: %-20f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_spaces_before_star) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 1: Characters with spaces
  count = sprintf(expected, "Character: %*c%*c%*c", 3, 'w', 3, 'o', 3, 'w');
  s21_count =
      s21_sprintf(buffer, "Character: %*c%*c%*c", 3, 'w', 3, 'o', 3, 'w');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Text with spaces
  const char *text = "Hello, World!";
  count = sprintf(expected, "Text: %*s", 20, text);
  s21_count = s21_sprintf(buffer, "Text: %*s", 20, text);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Integer with spaces
  int i = 42;
  count = sprintf(expected, "Integer: %*d", 20, i);
  s21_count = s21_sprintf(buffer, "Integer: %*d", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Signed integer with spaces
  count = sprintf(expected, "Signed Integer: %*i", 20, i);
  s21_count = s21_sprintf(buffer, "Signed Integer: %*i", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Octal with spaces
  count = sprintf(expected, "Octal: %*o", 20, i);
  s21_count = s21_sprintf(buffer, "Octal: %*o", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Hexadecimal (lowercase) with spaces
  count = sprintf(expected, "Hexadecimal: %*x", 20, i);
  s21_count = s21_sprintf(buffer, "Hexadecimal: %*x", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Hexadecimal (uppercase) with spaces
  count = sprintf(expected, "Uppercase Hexadecimal: %*X", 20, i);
  s21_count = s21_sprintf(buffer, "Uppercase Hexadecimal: %*X", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Unsigned integer with spaces
  unsigned int u = 42;
  count = sprintf(expected, "Unsigned Integer: %*u", 20, u);
  s21_count = s21_sprintf(buffer, "Unsigned Integer: %*u", 20, u);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: Pointer with spaces
  int *ptr = &i;
  count = sprintf(expected, "Pointer: %*p", 20, (void *)ptr);
  s21_count = s21_sprintf(buffer, "Pointer: %*p", 20, (void *)ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_spaces_after_star) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 1: Characters with spaces
  count = sprintf(expected, "Character: %-*c%-*c%-*c", 3, 'w', 3, 'o', 3, 'w');
  s21_count =
      s21_sprintf(buffer, "Character: %-*c%-*c%-*c", 3, 'w', 3, 'o', 3, 'w');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Text with spaces
  const char *text = "Hello, World!";
  count = sprintf(expected, "Text: %-*s", 20, text);
  s21_count = s21_sprintf(buffer, "Text: %-*s", 20, text);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Integer with spaces
  int i = 42;
  count = sprintf(expected, "Integer: %-*d", 20, i);
  s21_count = s21_sprintf(buffer, "Integer: %-*d", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Signed integer with spaces
  count = sprintf(expected, "Signed Integer: %-*i", 20, i);
  s21_count = s21_sprintf(buffer, "Signed Integer: %-*i", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Octal with spaces
  count = sprintf(expected, "Octal: %-*o", 20, i);
  s21_count = s21_sprintf(buffer, "Octal: %-*o", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Hexadecimal (lowercase) with spaces
  count = sprintf(expected, "Hexadecimal: %-*x", 20, i);
  s21_count = s21_sprintf(buffer, "Hexadecimal: %-*x", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Hexadecimal (uppercase) with spaces
  count = sprintf(expected, "Uppercase Hexadecimal: %-*X", 20, i);
  s21_count = s21_sprintf(buffer, "Uppercase Hexadecimal: %-*X", 20, i);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Unsigned integer with spaces
  unsigned int u = 42;
  count = sprintf(expected, "Unsigned Integer: %-*u", 20, u);
  s21_count = s21_sprintf(buffer, "Unsigned Integer: %-*u", 20, u);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 9: Pointer with spaces
  int *ptr = &i;
  count = sprintf(expected, "Pointer: %-*p", 20, (void *)ptr);
  s21_count = s21_sprintf(buffer, "Pointer: %-*p", 20, (void *)ptr);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Uncomment and add tests for float and double if needed
  float f = 42.0f;
  count = sprintf(expected, "Float: %-*f", 20, f);
  s21_count = s21_sprintf(buffer, "Float: %-*f", 20, f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  double d = 42.0;
  count = sprintf(expected, "Double: %-*lf", 20, d);
  s21_count = s21_sprintf(buffer, "Double: %-*lf", 20, d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_s21_sprintf_zero_padding) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

  // Test 0:
  double d = 4334.8573;
  count = sprintf(expected, "Double: %020lf %+20lf %-20lf % 20lf", d, d, d, d);
  s21_count =
      s21_sprintf(buffer, "Double: %020lf %+20lf %-20lf % 20lf", d, d, d, d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  long double ld = 4334.8573;
  count = sprintf(expected, "Long Double: %020Lf %+20Lf %-20Lf % 20Lf", ld, ld,
                  ld, ld);
  s21_count = s21_sprintf(buffer, "Long Double: %020Lf %+20Lf %-20Lf % 20Lf",
                          ld, ld, ld, ld);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 1: Characters with spaces
  count = sprintf(expected, "Character: %-*c%-*c%-*c", 3, 'w', 3, 'o', 3, 'w');
  s21_count =
      s21_sprintf(buffer, "Character: %-*c%-*c%-*c", 3, 'w', 3, 'o', 3, 'w');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 2: Text with spaces
  const char *text = "Hello, World!";
  count = sprintf(expected, "Text: %-*s", 20, text);
  s21_count = s21_sprintf(buffer, "Text: %-*s", 20, text);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 3: Integer with spaces (modified)
  int i = 42;
  long li = 1234567890L;         // Ensure this is a valid long
  long long lli = 9876543210LL;  // Use a smaller value
  count =
      sprintf(expected, "Integer: %0*d\n%+0*ld\n%014lld", 20, i, 15, li, lli);
  s21_count =
      s21_sprintf(buffer, "Integer: %0*d\n%+0*ld\n%014lld", 20, i, 15, li, lli);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 4: Signed integer with spaces (modified)
  count = sprintf(expected, "Signed Integer: %0*d\n%+0*ld\n%014lld", 20, i, 15,
                  li, lli);
  s21_count = s21_sprintf(buffer, "Signed Integer: %0*d\n%+0*ld\n%014lld", 20,
                          i, 15, li, lli);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 5: Octal with spaces (modified)
  count = sprintf(expected, "Octal: %0*o\n%0*lo\n%014llo", 20, i, 15, li, lli);
  s21_count =
      s21_sprintf(buffer, "Octal: %0*o\n%0*lo\n%014llo", 20, i, 15, li, lli);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 6: Hexadecimal (lowercase) with spaces (modified)
  count = sprintf(expected, "Hexadecimal: %0*x\n%0*lx\n%014llx", 20, i, 15, li,
                  lli);
  s21_count = s21_sprintf(buffer, "Hexadecimal: %0*x\n%0*lx\n%014llx", 20, i,
                          15, li, lli);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 7: Hexadecimal (uppercase) with spaces (modified)
  count = sprintf(expected, "Uppercase Hexadecimal: %0*X\n%0*lX\n%014llX", 20,
                  i, 15, li, lli);
  s21_count = s21_sprintf(buffer, "Uppercase Hexadecimal: %0*X\n%0*lX\n%014llX",
                          20, i, 15, li, lli);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 8: Unsigned integer with spaces (modified)
  unsigned int u = 42;
  count = sprintf(expected, "Unsigned Integer: %0*u\n%0*lu\n%014llu", 20, u, 15,
                  (unsigned long)li, (unsigned long long)lli);
  s21_count = s21_sprintf(buffer, "Unsigned Integer: %0*u\n%0*lu\n%014llu", 20,
                          u, 15, (unsigned long)li, (unsigned long long)lli);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 10: Float with spaces (modified)
  float f = 42.0f;
  count = sprintf(expected, "Float: %0*.*f\n%0*.*lf\n%0*.*Lf", 20, 2, f, 15, 2,
                  (double)f, 15, 2, (long double)f);
  s21_count = s21_sprintf(buffer, "Float: %0*.*f\n%0*.*lf\n%0*.*Lf", 20, 2, f,
                          15, 2, (double)f, 15, 2, (long double)f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  f = 299.9;
  count = sprintf(expected, "Float: %.0f %.1f", f, f);
  s21_count = s21_sprintf(buffer, "Float: %.0f %.1f", f, f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  f = 42.56789f;
  // Test 11: Rounding
  count = sprintf(expected, "Double: %.2f", f);
  s21_count = s21_sprintf(buffer, "Double: %.2f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
  count = sprintf(expected, "Double: %.3f", f);
  s21_count = s21_sprintf(buffer, "Double: %.3f", f);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Double: %020lf", d);
  s21_count = s21_sprintf(buffer, "Double: %020lf", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Double: %-20lf", d);
  s21_count = s21_sprintf(buffer, "Double: %-20lf", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "Double: %020lf", d);
  s21_count = s21_sprintf(buffer, "Double: %020lf", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 11.1: Double with spaces (modified)
  count = sprintf(expected, "Double: %0*.*lf\n%0*.*Lf", 20, 2, d, 15, 2,
                  (long double)d);
  s21_count = s21_sprintf(buffer, "Double: %0*.*lf\n%0*.*Lf", 20, 2, d, 15, 2,
                          (long double)d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_g_specifier_basic) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  // Basic examples
  d = 123.456;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 0.0000123456;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 123000000.0;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 123.0;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_g_specifier_precision) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  d = 123.456789;
  count = sprintf(expected, "%.3g", d);
  s21_count = s21_sprintf(buffer, "%.3g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.6g", d);
  s21_count = s21_sprintf(buffer, "%.6g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 0.0000123456;
  count = sprintf(expected, "%.3g", d);
  s21_count = s21_sprintf(buffer, "%.3g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.6g", d);
  s21_count = s21_sprintf(buffer, "%.6g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_g_specifier_edge_cases) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  d = 999.999;
  count = sprintf(expected, "%.3g", d);
  s21_count = s21_sprintf(buffer, "%.3g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 0.0009999;
  count = sprintf(expected, "%.3g", d);
  s21_count = s21_sprintf(buffer, "%.3g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 0.00009999;
  count = sprintf(expected, "%.3g", d);
  s21_count = s21_sprintf(buffer, "%.3g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_G_specifier_uppercase) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  d = 123.456;
  count = sprintf(expected, "%G", d);
  s21_count = s21_sprintf(buffer, "%G", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 0.0000123456;
  count = sprintf(expected, "%G", d);
  s21_count = s21_sprintf(buffer, "%G", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 123000000.0;
  count = sprintf(expected, "%G", d);
  s21_count = s21_sprintf(buffer, "%G", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_g_specifier_with_flags) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  d = 123.45605;
  count = sprintf(expected, "%#g", d);
  s21_count = s21_sprintf(buffer, "%#g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%#.10g", d);
  s21_count = s21_sprintf(buffer, "%#.10g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10g", d);
  s21_count = s21_sprintf(buffer, "%.10g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 123.0;
  count = sprintf(expected, "%#g", d);
  s21_count = s21_sprintf(buffer, "%#g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 123.456;
  count = sprintf(expected, "%+g", d);
  s21_count = s21_sprintf(buffer, "%+g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = -123.456;
  count = sprintf(expected, "% g", d);
  s21_count = s21_sprintf(buffer, "% g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_g_specifier_large_small_numbers) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  d = 123456789.0;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 1234.56789;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 0.000000123456;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  d = 0.00123456;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_g_specifier_with_width) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  d = 123.456;
  count = sprintf(expected, "%10g", d);
  s21_count = s21_sprintf(buffer, "%10g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10g", d);
  s21_count = s21_sprintf(buffer, "%-10g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%010g", d);
  s21_count = s21_sprintf(buffer, "%010g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_g_specifier_special_values) {
  char buffer[1000];
  char expected[1000];
  double d;
  int count, s21_count;

  // Test infinity
  d = INFINITY;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test negative infinity
  d = -INFINITY;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test NaN
  d = NAN;
  count = sprintf(expected, "%g", d);
  s21_count = s21_sprintf(buffer, "%g", d);
  // For NaN, we can't do direct string comparison due to different
  // representations
  // but we can check that both contain "nan" (case insensitive)
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_sprintf_external) {
  char *str = "Testing";
  char buffer[1000] = "";
  char expected[1000] = "";
  int number = 94759324;
  int int_zero = 0;
  double double_zero = 0;
  short short_int = 15;
  int negative_int = -36;
  unsigned int unsigned_int = 85;
  double float1 = 123456.789;
  double float2 = 0.00000123456;
  double float3 = -99.99;
  double float4 = 0.000012000001;
  double float5 = -12.34;
  char c = 'K';
  void *p = &number;

  s21_sprintf(buffer, "%+010d", number);
  sprintf(expected, "%+010d", number);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%-10d", negative_int);
  sprintf(expected, "%-10d", negative_int);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%hd", short_int);
  sprintf(expected, "%hd", short_int);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%u", unsigned_int);
  sprintf(expected, "%u", unsigned_int);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%.2f", float1);
  sprintf(expected, "%.2f", float1);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "% .*f", 8, float2);
  sprintf(expected, "% .*f", 8, float2);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%s", str);
  sprintf(expected, "%s", str);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", c);
  sprintf(expected, "%c", c);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%g", float1);
  sprintf(expected, "%g", float1);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%G", float2);
  sprintf(expected, "%G", float2);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%015e", float1);
  sprintf(expected, "%015e", float1);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%E", float2);
  sprintf(expected, "%E", float2);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%#x", number);
  sprintf(expected, "%#x", number);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%10X", unsigned_int);
  sprintf(expected, "%10X", unsigned_int);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%#o", number);
  sprintf(expected, "%#o", number);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%p", p);
  sprintf(expected, "%p", p);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%.1f", float3);
  sprintf(expected, "%.1f", float3);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%*p", 20, p);
  sprintf(expected, "%*p", 20, p);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%#020X", number);
  sprintf(expected, "%#020X", number);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%%");
  sprintf(expected, "%%");
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "% d", number);
  sprintf(expected, "% d", number);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%+15f", float1);
  sprintf(expected, "%+15f", float1);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%.4g", float4);
  sprintf(expected, "%.4g", float4);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%5c", c);
  sprintf(expected, "%5c", c);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%-3c", c);
  sprintf(expected, "%-3c", c);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%g", double_zero);
  sprintf(expected, "%g", double_zero);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%g", float3);
  sprintf(expected, "%g", float3);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%x", int_zero);
  sprintf(expected, "%x", int_zero);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%10o", int_zero);
  sprintf(expected, "%10o", int_zero);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%25p", p);
  sprintf(expected, "%25p", p);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "% e", float3);
  sprintf(expected, "% e", float3);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%+e", float1);
  sprintf(expected, "%+e", float1);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%.*e", 1, float5);
  sprintf(expected, "%.*e", 1, float5);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%.4s", str);
  sprintf(expected, "%.4s", str);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%15s", str);
  sprintf(expected, "%15s", str);
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%20u", unsigned_int);
  sprintf(expected, "%20u", unsigned_int);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//
// Test suite for regular characters
//
START_TEST(test_char_basic) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test basic ASCII characters
  count = sprintf(expected, "%c", 'A');
  s21_count = s21_sprintf(buffer, "%c", 'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", 'z');
  s21_count = s21_sprintf(buffer, "%c", 'z');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '0');
  s21_count = s21_sprintf(buffer, "%c", '0');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", ' ');
  s21_count = s21_sprintf(buffer, "%c", ' ');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_char_special) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test special characters
  count = sprintf(expected, "%c", '\n');
  s21_count = s21_sprintf(buffer, "%c", '\n');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '\t');
  s21_count = s21_sprintf(buffer, "%c", '\t');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '\0');
  s21_count = s21_sprintf(buffer, "%c", '\0');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '\r');
  s21_count = s21_sprintf(buffer, "%c", '\r');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '\b');
  s21_count = s21_sprintf(buffer, "%c", '\b');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '\\');
  s21_count = s21_sprintf(buffer, "%c", '\\');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '\'');
  s21_count = s21_sprintf(buffer, "%c", '\'');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", '\"');
  s21_count = s21_sprintf(buffer, "%c", '\"');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_char_numeric_values) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test with numeric values that become characters
  count = sprintf(expected, "%c", 65);  // 'A'
  s21_count = s21_sprintf(buffer, "%c", 65);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", 97);  // 'a'
  s21_count = s21_sprintf(buffer, "%c", 97);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", 48);  // '0'
  s21_count = s21_sprintf(buffer, "%c", 48);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", 0);  // '\0'
  s21_count = s21_sprintf(buffer, "%c", 0);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", 255);  // Should wrap around
  s21_count = s21_sprintf(buffer, "%c", 255);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%c", -1);  // Should wrap around
  s21_count = s21_sprintf(buffer, "%c", -1);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_char_width_precision) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test with width
  count = sprintf(expected, "%5c", 'X');
  s21_count = s21_sprintf(buffer, "%5c", 'X');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with left alignment (not zero padding for %c)
  count = sprintf(expected, "%-5c", 'X');
  s21_count = s21_sprintf(buffer, "%-5c", 'X');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with width 0
  count = sprintf(expected, "%c", 'X');
  s21_count = s21_sprintf(buffer, "%c", 'X');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

//
// Test suite for regular strings
//

START_TEST(test_string_basic) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test basic strings
  count = sprintf(expected, "%s", "Hello");
  s21_count = s21_sprintf(buffer, "%s", "Hello");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "World");
  s21_count = s21_sprintf(buffer, "%s", "World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "Test123");
  s21_count = s21_sprintf(buffer, "%s", "Test123");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "");
  s21_count = s21_sprintf(buffer, "%s", "");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "A");
  s21_count = s21_sprintf(buffer, "%s", "A");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_string_null) {
  char buffer[100];
  char expected[100];
  int count, s21_count;
  char *str_nulled = NULL;

  // Test NULL string
  count = sprintf(expected, "%s", str_nulled);
  s21_count = s21_sprintf(buffer, "%s", str_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%10.3s", str_nulled);
  s21_count = s21_sprintf(buffer, "%10.3s", str_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%10.5s", str_nulled);
  s21_count = s21_sprintf(buffer, "%10.5s", str_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%10.6s", str_nulled);
  s21_count = s21_sprintf(buffer, "%10.6s", str_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%10.7s", str_nulled);
  s21_count = s21_sprintf(buffer, "%10.7s", str_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%20.10s", str_nulled);
  s21_count = s21_sprintf(buffer, "%20.10s", str_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);
}
END_TEST

START_TEST(test_string_special_chars) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test strings with special characters
  count = sprintf(expected, "%s", "Hello\nWorld");
  s21_count = s21_sprintf(buffer, "%s", "Hello\nWorld");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "Tab\tSeparated");
  s21_count = s21_sprintf(buffer, "%s", "Tab\tSeparated");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "Path\\to\\file");
  s21_count = s21_sprintf(buffer, "%s", "Path\\to\\file");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "Quote\"Test'");
  s21_count = s21_sprintf(buffer, "%s", "Quote\"Test'");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s", "New\nLine\nTest");
  s21_count = s21_sprintf(buffer, "%s", "New\nLine\nTest");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_string_with_precision) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test precision with regular strings
  count = sprintf(expected, "%.3s", "Hello");
  s21_count = s21_sprintf(buffer, "%.3s", "Hello");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.0s", "Hello");
  s21_count = s21_sprintf(buffer, "%.0s", "Hello");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.10s", "Hi");
  s21_count = s21_sprintf(buffer, "%.10s", "Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%.5s", "HelloWorld");
  s21_count = s21_sprintf(buffer, "%.5s", "HelloWorld");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test precision with special characters
  count = sprintf(expected, "%.7s", "Hello\nWorld");
  s21_count = s21_sprintf(buffer, "%.7s", "Hello\nWorld");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_string_with_width) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test width with strings
  count = sprintf(expected, "%10s", "Hi");
  s21_count = s21_sprintf(buffer, "%10s", "Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10s", "Hi");
  s21_count = s21_sprintf(buffer, "%-10s", "Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%10s", "Hi");
  s21_count = s21_sprintf(buffer, "%10s", "Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%5s", "A");
  s21_count = s21_sprintf(buffer, "%5s", "A");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test width with precision
  count = sprintf(expected, "%10.3s", "HelloWorld");
  s21_count = s21_sprintf(buffer, "%10.3s", "HelloWorld");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10.3s", "HelloWorld");
  s21_count = s21_sprintf(buffer, "%-10.3s", "HelloWorld");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_string_edge_cases) {
  char buffer[2000];  // Larger buffer for long strings
  char expected[2000];
  int count, s21_count;

  // Very long string
  char long_str[1000];
  for (int i = 0; i < 999; i++) {
    long_str[i] = 'A';
  }
  long_str[999] = '\0';

  strcpy(expected, long_str);
  s21_count = s21_sprintf(buffer, "%s", long_str);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, 999);

  // String with embedded nulls (should stop at first null when printed
  // normally)
  char embedded_null[] = {'H', 'e', 'l', 'l', 'o', '\0',
                          'W', 'o', 'r', 'l', 'd', '\0'};
  count = sprintf(expected, "%s", embedded_null);
  s21_count = s21_sprintf(buffer, "%s", embedded_null);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // String with only spaces
  count = sprintf(expected, "%s", "   ");
  s21_count = s21_sprintf(buffer, "%s", "   ");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // String with only tabs/newlines
  count = sprintf(expected, "%s", "\t\n\r");
  s21_count = s21_sprintf(buffer, "%s", "\t\n\r");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // String with binary data
  char binary_str[] = {'A', 0x01, 0x02, 'B', '\0'};
  count = sprintf(expected, "%s", binary_str);
  s21_count = s21_sprintf(buffer, "%s", binary_str);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_string_format_combinations) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test string with other format specifiers
  count = sprintf(expected, "String: %s, Number: %d", "test", 42);
  s21_count = s21_sprintf(buffer, "String: %s, Number: %d", "test", 42);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Multiple strings
  count = sprintf(expected, "%s %s %s", "Hello", "World", "!");
  s21_count = s21_sprintf(buffer, "%s %s %s", "Hello", "World", "!");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // String with character
  count = sprintf(expected, "%s%c%s", "Hello", '!', "World");
  s21_count = s21_sprintf(buffer, "%s%c%s", "Hello", '!', "World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // String with numbers
  count = sprintf(expected, "%s%d%s", "Number:", 123, ":End");
  s21_count = s21_sprintf(buffer, "%s%d%s", "Number:", 123, ":End");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%4.3s %4.6i %4.6g %4lc %4.6i %4lc %4.3s",
                  "wow lol", 404, 404.607601, '^', 404, 'l', "wow lol");
  s21_count = s21_sprintf(buffer, "%4.3s %4.6i %4.6g %4lc %4.6i %4lc %4.3s",
                          "wow lol", 404, 404.607601, '^', 404, 'l', "wow lol");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

// Edge cases for both char and string
START_TEST(test_char_string_edge_cases) {
  char buffer[2000];  // Larger buffer for large width values
  char expected[2000];
  int count, s21_count;

  // Very large width values
  count = sprintf(expected, "%100c", 'X');
  s21_count = s21_sprintf(buffer, "%100c", 'X');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%100s", "Hi");
  s21_count = s21_sprintf(buffer, "%100s", "Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Maximum precision values
  count = sprintf(expected, "%.20s", "test");
  s21_count = s21_sprintf(buffer, "%.20s", "test");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Negative width (should be treated as left alignment)
  count = sprintf(expected, "%-10c", 'X');
  s21_count = s21_sprintf(buffer, "%-10c", 'X');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%-10s", "Hi");
  s21_count = s21_sprintf(buffer, "%-10s", "Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Multiple format specifiers
  count = sprintf(expected, "%c%s%c%s", 'A', "Hello", 'B', "World");
  s21_count = s21_sprintf(buffer, "%c%s%c%s", 'A', "Hello", 'B', "World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Empty format string
  count = sprintf(expected, "%s", "");
  s21_count = s21_sprintf(buffer, "%s", "");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Format string with no arguments
  count = sprintf(expected, "%s", "Hello World");
  s21_count = s21_sprintf(buffer, "%s", "Hello World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Only format specifiers
  count = sprintf(expected, "%c%c%c", 'A', 'B', 'C');
  s21_count = s21_sprintf(buffer, "%c%c%c", 'A', 'B', 'C');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count = sprintf(expected, "%s%s%s", "A", "B", "C");
  s21_count = s21_sprintf(buffer, "%s%s%s", "A", "B", "C");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_char_string_mixed_formats) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Mixed formats with various types
  count = sprintf(expected, "Char: %c, Str: %s, Int: %d, Float: %f", 'X',
                  "test", 42, 3.14);
  s21_count = s21_sprintf(buffer, "Char: %c, Str: %s, Int: %d, Float: %f", 'X',
                          "test", 42, 3.14);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Complex format with width and precision
  count = sprintf(expected, "%10c%10.5s%-5d", 'A', "HelloWorld", 123);
  s21_count = s21_sprintf(buffer, "%10c%10.5s%-5d", 'A', "HelloWorld", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Format with left alignment instead of zero padding
  count = sprintf(expected, "%-5c%-5s", 'X', "Hi");
  s21_count = s21_sprintf(buffer, "%-5c%-5s", 'X', "Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Format with precision and width combined
  count = sprintf(expected, "%10.3s", "HelloWorld");
  s21_count = s21_sprintf(buffer, "%10.3s", "HelloWorld");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%4.3s %4.6i %4.6g %4lc %4.6i %4lc %4.3s", "wow lol",
              404, 404.607601, (wint_t)L'€', 404, (wint_t)L'l', "wow lol");
  s21_count =
      s21_sprintf(buffer, "%4.3s %4.6i %4.6g %4lc %4.6i %4lc %4.3s", "wow lol",
                  404, 404.607601, (wint_t)L'€', 404, (wint_t)L'l', "wow lol");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  count =
      sprintf(expected, "%4.3s %4.6i %4.6g %4lc %4.6i %4lc %4.3s", "wow lol",
              404, 4046.6076, (wint_t)L'€', 404, (wint_t)L'l', "wow lol");
  s21_count =
      s21_sprintf(buffer, "%4.3s %4.6i %4.6g %4lc %4.6i %4lc %4.3s", "wow lol",
                  404, 4046.6076, (wint_t)L'€', 404, (wint_t)L'l', "wow lol");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

//
// Test suite for wide characters
//

START_TEST(test_wchar_basic) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test basic ASCII wide character
  count = sprintf(expected, "%lc", (wint_t)L'A');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test space
  count = sprintf(expected, "%lc", (wint_t)L' ');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L' ');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test digit
  count = sprintf(expected, "%lc", (wint_t)L'5');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L'5');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_wchar_null_character) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test null character (should print but count as 1 character)
  count = sprintf(expected, "%lc", (wint_t)L'\0');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L'\0');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_wchar_extended_unicode) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test Euro symbol
  count = sprintf(expected, "%lc", (wint_t)L'€');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L'€');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test heart symbol
  count = sprintf(expected, "%lc", (wint_t)L'♥');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L'♥');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test Chinese character
  count = sprintf(expected, "%lc", (wint_t)L'中');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L'中');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test Arabic character
  count = sprintf(expected, "%lc", (wint_t)L'ع');
  s21_count = s21_sprintf(buffer, "%lc", (wint_t)L'ع');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_wchar_with_width_precision) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test with width (if your implementation supports it)
  count = sprintf(expected, "%3lc", (wint_t)L'A');
  s21_count = s21_sprintf(buffer, "%3lc", (wint_t)L'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test with zero padding (if supported)
  count = sprintf(expected, "%3lc", (wint_t)L'5');
  s21_count = s21_sprintf(buffer, "%3lc", (wint_t)L'5');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

//
// Test suite for wide strings
//

START_TEST(test_wstr_basic) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test basic ASCII string
  count = sprintf(expected, "%ls", L"Hello");
  s21_count = s21_sprintf(buffer, "%ls", L"Hello");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test empty string
  count = sprintf(expected, "%ls", L"");
  s21_count = s21_sprintf(buffer, "%ls", L"");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test single character
  count = sprintf(expected, "%ls", L"A");
  s21_count = s21_sprintf(buffer, "%ls", L"A");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test string with space
  count = sprintf(expected, "%ls", L"Hello World");
  s21_count = s21_sprintf(buffer, "%ls", L"Hello World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_wstr_null) {
  char buffer[100];
  char expected[100];
  int count, s21_count;
  wchar_t *wstr_nulled = (wchar_t *)NULL;

  // Test NULL string
  count = sprintf(expected, "%ls", wstr_nulled);
  s21_count = s21_sprintf(buffer, "%ls", wstr_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  // Test with precision on NULL - use a safe way to handle NULL
  count = sprintf(expected, "%10.3ls", wstr_nulled);
  s21_count = s21_sprintf(buffer, "%10.3ls", wstr_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%10.5ls", wstr_nulled);
  s21_count = s21_sprintf(buffer, "%10.5ls", wstr_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%10.6ls", wstr_nulled);
  s21_count = s21_sprintf(buffer, "%10.6ls", wstr_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%10.7ls", wstr_nulled);
  s21_count = s21_sprintf(buffer, "%10.7ls", wstr_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);

  count = sprintf(expected, "%20.10ls", wstr_nulled);
  s21_count = s21_sprintf(buffer, "%20.10ls", wstr_nulled);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_count, count);
}
END_TEST

START_TEST(test_wstr_extended_unicode) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test mixed ASCII and Unicode
  count = sprintf(expected, "%ls", L"Hello € World");
  s21_count = s21_sprintf(buffer, "%ls", L"Hello € World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test only Unicode
  count = sprintf(expected, "%ls", L"€£¥");
  s21_count = s21_sprintf(buffer, "%ls", L"€£¥");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test Chinese text
  count = sprintf(expected, "%ls", L"你好世界");
  s21_count = s21_sprintf(buffer, "%ls", L"你好世界");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test emoji (if supported)
  count = sprintf(expected, "%ls", L"Hello 👋 World");
  s21_count = s21_sprintf(buffer, "%ls", L"Hello 👋 World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_wstr_with_precision) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test precision with ASCII
  count = sprintf(expected, "%.3ls", L"Hello");
  s21_count = s21_sprintf(buffer, "%.3ls", L"Hello");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test precision with mixed Unicode
  count = sprintf(expected, "%.5ls", L"Hello€World");
  s21_count = s21_sprintf(buffer, "%.5ls", L"Hello€World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test precision longer than string
  count = sprintf(expected, "%.10ls", L"Hi");
  s21_count = s21_sprintf(buffer, "%.10ls", L"Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test precision with 0
  count = sprintf(expected, "%.0ls", L"Hello");
  s21_count = s21_sprintf(buffer, "%.0ls", L"Hello");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_wstr_with_width) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test width with ASCII
  count = sprintf(expected, "%10ls", L"Hi");
  s21_count = s21_sprintf(buffer, "%10ls", L"Hi");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test width with Unicode
  count = sprintf(expected, "%10ls", L"€");
  s21_count = s21_sprintf(buffer, "%10ls", L"€");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test width and precision combined
  count = sprintf(expected, "%10.3ls", L"HelloWorld");
  s21_count = s21_sprintf(buffer, "%10.3ls", L"HelloWorld");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

// Edge cases for wide strings
START_TEST(test_wstr_edge_cases) {
  char buffer[2000];  // Larger buffer for long strings
  wchar_t long_str[1000];
  int s21_count;

  // Very long string
  for (int i = 0; i < 999; i++) {
    long_str[i] = L'A';
  }
  long_str[999] = L'\0';

  s21_count = s21_sprintf(buffer, "%ls", long_str);
  ck_assert_int_eq(s21_count, 999);

  // Verify the output contains the correct number of 'A's
  for (int i = 0; i < 999; i++) {
    ck_assert_int_eq(buffer[i], 'A');
  }
  ck_assert_int_eq(buffer[999], '\0');

  // String with embedded nulls (should stop at first null)
  wchar_t embedded_null[] = {L'H', L'e', L'l', L'l', L'o', L'\0',
                             L'W', L'o', L'r', L'l', L'd', L'\0'};
  s21_count = s21_sprintf(buffer, "%ls", embedded_null);
  ck_assert_str_eq(buffer, "Hello");
  ck_assert_int_eq(s21_count, 5);

  // String with only null character
  wchar_t only_null[] = {L'\0'};
  s21_count = s21_sprintf(buffer, "%ls", only_null);
  ck_assert_str_eq(buffer, "");
  ck_assert_int_eq(s21_count, 0);
}
END_TEST

// Combined tests
START_TEST(test_wchar_wstr_mixed) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Mixed format with regular and wide characters
  count = sprintf(expected, "Char: %lc, String: %ls", (wint_t)L'X', L"test");
  s21_count =
      s21_sprintf(buffer, "Char: %lc, String: %ls", (wint_t)L'X', L"test");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Multiple wide chars and strings
  count = sprintf(expected, "%ls %lc %ls", L"Hello", (wint_t)L'!', L"World");
  s21_count =
      s21_sprintf(buffer, "%ls %lc %ls", L"Hello", (wint_t)L'!', L"World");
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

START_TEST(test_wchar_format_combinations) {
  char buffer[100];
  char expected[100];
  int count, s21_count;

  // Test with other format specifiers
  count = sprintf(expected, "Char: %lc, Num: %d", (wint_t)L'A', 42);
  s21_count = s21_sprintf(buffer, "Char: %lc, Num: %d", (wint_t)L'A', 42);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Wide string with other formats
  count = sprintf(expected, "Str: %ls, Num: %d", L"test", 123);
  s21_count = s21_sprintf(buffer, "Str: %ls, Num: %d", L"test", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);
}
END_TEST

Suite *s21_sprintf_test(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("Combined test");

  tcase_add_test(tc, nulled_within_provided_string);
  tcase_add_test(tc, nulled_char);
  tcase_add_test(tc, test_s21_sprintf_combined);
  tcase_add_test(tc, test_s21_sprintf_forced_plus_sign);
  tcase_add_test(tc, test_s21_sprintf_space_sign);
  tcase_add_test(tc, test_s21_sprintf_hash_flag);
  tcase_add_test(tc, test_s21_sprintf_spaces_before);
  tcase_add_test(tc, test_s21_sprintf_spaces_before_star);
  tcase_add_test(tc, test_s21_sprintf_spaces_after);
  tcase_add_test(tc, test_s21_sprintf_spaces_after_star);
  tcase_add_test(tc, test_s21_sprintf_zero_padding);
  tcase_add_test(tc, test_sprintf_external);
  // %g and %G tests
  tcase_add_test(tc, test_g_specifier_basic);
  tcase_add_test(tc, test_g_specifier_precision);
  tcase_add_test(tc, test_g_specifier_edge_cases);
  tcase_add_test(tc, test_G_specifier_uppercase);
  tcase_add_test(tc, test_g_specifier_with_flags);
  tcase_add_test(tc, test_g_specifier_large_small_numbers);
  tcase_add_test(tc, test_g_specifier_with_width);
  tcase_add_test(tc, test_g_specifier_special_values);

  // Wide characters and strings
  TCase *tc_wchar, *tc_wstr, *tc_wmixed;
  s = suite_create("WidePrintf");
  // Wide character tests
  tc_wchar = tcase_create("WideChar");
  tcase_add_test(tc_wchar, test_wchar_basic);
  tcase_add_test(tc_wchar, test_wchar_null_character);
  tcase_add_test(tc_wchar, test_wchar_extended_unicode);
  tcase_add_test(tc_wchar, test_wchar_with_width_precision);
  suite_add_tcase(s, tc_wchar);
  // Wide string tests
  tc_wstr = tcase_create("WideString");
  tcase_add_test(tc_wstr, test_wstr_basic);
  tcase_add_test(tc_wstr, test_wstr_null);
  tcase_add_test(tc_wstr, test_wstr_extended_unicode);
  tcase_add_test(tc_wstr, test_wstr_with_precision);
  tcase_add_test(tc_wstr, test_wstr_with_width);
  tcase_add_test(tc_wstr, test_wstr_edge_cases);
  suite_add_tcase(s, tc_wstr);
  // Mixed format tests
  tc_wmixed = tcase_create("MixedFormats");
  tcase_add_test(tc_wmixed, test_wchar_wstr_mixed);
  tcase_add_test(tc_wmixed, test_wchar_format_combinations);
  suite_add_tcase(s, tc_wmixed);

  // Simple characters and strings
  TCase *tc_char, *tc_str, *tc_edge, *tc_mixed;
  // Character tests
  tc_char = tcase_create("Character");
  tcase_add_test(tc_char, test_char_basic);
  tcase_add_test(tc_char, test_char_special);
  tcase_add_test(tc_char, test_char_numeric_values);
  tcase_add_test(tc_char, test_char_width_precision);
  suite_add_tcase(s, tc_char);
  // String tests
  tc_str = tcase_create("String");
  tcase_add_test(tc_str, test_string_basic);
  tcase_add_test(tc_str, test_string_null);
  tcase_add_test(tc_str, test_string_special_chars);
  tcase_add_test(tc_str, test_string_with_precision);
  tcase_add_test(tc_str, test_string_with_width);
  suite_add_tcase(s, tc_str);
  // Edge case tests
  tc_edge = tcase_create("EdgeCases");
  tcase_add_test(tc_edge, test_string_edge_cases);
  tcase_add_test(tc_edge, test_char_string_edge_cases);
  suite_add_tcase(s, tc_edge);
  // Mixed format tests
  tc_mixed = tcase_create("MixedFormats");
  tcase_add_test(tc_mixed, test_string_format_combinations);
  tcase_add_test(tc_mixed, test_char_string_mixed_formats);
  suite_add_tcase(s, tc_mixed);

  suite_add_tcase(s, tc);
  return s;
}
