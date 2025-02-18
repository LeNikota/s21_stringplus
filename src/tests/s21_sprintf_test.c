#include "test.h"

START_TEST(test_s21_sprintf_combined) {
  char buffer[100000];
  char expected[100000];
  int count, s21_count;

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
  long double number55 = 3.14159;
  count = sprintf(expected, "Float value: %Lf", number55);
  s21_count = s21_sprintf(buffer, "Float value: %Lf", number55);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

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
  long double number58 = 1e38;
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

  // Test 74: Double large (%f)
  long double number62 = 1e308;
  count = sprintf(expected, "Large Double: %Lf", number62);
  s21_count = s21_sprintf(buffer, "Large Double: %Lf", number62);
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

  // Test 78: Long double large (%Lf)
  long double number66 = LDBL_MAX;
  count = sprintf(expected, "Large Long Double: %Lf", number66);
  s21_count = s21_sprintf(buffer, "Large Long Double: %Lf", number66);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count, s21_count);

  // Test 79: Long double large negative (%Lf)
  long double number67 = -LDBL_MAX;
  count = sprintf(expected, "Large Long Double: %Lf", number67);
  s21_count = s21_sprintf(buffer, "Large Long Double: %Lf", number67);
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
}
END_TEST

Suite *s21_sprintf_test(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("Combined Tests");

  tcase_add_test(tc, test_s21_sprintf_combined);

  suite_add_tcase(s, tc);
  return s;
}
