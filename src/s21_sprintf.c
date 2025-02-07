#include "s21_string.h"
#include <stdarg.h>

// %[flags][width][.precision][length]specifier
typedef struct Fmt {
    // Flags that modify output format:
    // '-' : Left-justify is |text        |, default is |        text|
    // '+' : Forces to precede the result with a plus or minus sign (+ or -) 
    // ' ' : Space before positive numbers
    // '#' : Used with o, x or X specifiers the value is preceded with 0, 0x or 0X
    // '0' : Left-pads the number with zeroes
    char flags[5];

    // Minimum width of the output; padded if shorter.
    // number
    // *: additional integer value in argument
    int width;          

    // Number of digits after decimal for floats; max chars for strings.
    // .number
    // .*: additional integer value in argument
    int precision;      

    // Length modifier for data type:
    // 'h' : short int
    // 'l' : long
    // 'L' : long double
    char length[3];        

    // Format specifier for data type:
    // 'c' : char
    // 'd' : signed int
    // 'i' : signed int (may be decimal, octal or hexadecimal)
    // 'e' : scientific notation using e character
    // 'E' : Scientific notation using E character
    // 'f' : float
    // 'g' : Uses the shortest representation of decimal floating point
    // 'G' : Uses the shortest representation of decimal floating point
    // 'o' : Unsigned octal
    // 's' : string
    // 'u' : unsigned int
    // 'x' : Unsigned hexadecimal integer
    // 'X' : Unsigned hexadecimal integer (capital letters)
    // 'p' : pointer address
    // 'n' : Number of characters printed until %n occurs
    // '%' : literal percent
    char specifier;

    // Variable argument list to hold the additional arguments
    va_list args;

    // The pointer to current position in the formatted string (str)
    char * str;
} Fmt;

const char* parse_int(const char *p, Fmt *fmt);
void insert_integer(Fmt *fmt);
void insert_string(Fmt *fmt);
void insert_character(Fmt *fmt);
void insert_unsigned_integer(Fmt *fmt);
void insert_hexadecimal(Fmt *fmt);
void insert_pointer(Fmt *fmt);
void return_count(Fmt *fmt, char *str);

int s21_sprintf(char *str, const char *format, ...) {
    Fmt fmt = {0};
    fmt.str = str;

    va_start(fmt.args, format);
    
    for (const char *p = format; *p ; p++) {
        if (*p == '%') {
            p++;
            int flag_index = 0;

            // Handle flags
            while (*p == '-' || *p == '+' || *p == '0' || *p == ' ' || *p == '#') {
                if (flag_index < 5) {
                    fmt.flags[flag_index++] = *p;
                }
                p++;
            }

            // Handle width
            if (*p >= '0' && *p <= '9') p = parse_int(p, &fmt);

            // Handle precision
            if (*p == '.') {
                p++;
                p = parse_int(p, &fmt);
            }

            // Handle length modifier
            if (*p == 'h' || *p == 'l' || *p == 'L') {
                fmt.length[0] = *p;
                fmt.length[1] ='\0';
                p++;
            }
            // long long int (ll[i|d]) or signed char (hh[i|d])
            if (*p == 'l' || *p == 'h') {
                fmt.length[1] = *p;
                fmt.length[2] = '\0';
                p++;
            }

            // Handle the format specifier
            fmt.specifier = *p;
            
            // Process the specifier
            switch (fmt.specifier) {
                case 'd':
                case 'i':
                    insert_integer(&fmt);
                    break;
                case 's':
                    insert_string(&fmt);
                    break;
                case 'c':
                    insert_character(&fmt);
                    break;
                case 'e':
                case 'E':
                case 'f':
                case 'g':
                case 'G':
                    break;
                case 'o':
                    break;
                case 'u':
                    insert_unsigned_integer(&fmt);
                    break;
                case 'x':
                case 'X':
                    insert_hexadecimal(&fmt);
                    break;
                case 'p':
                    insert_pointer(&fmt);
                    break;
                case 'n':
                    return_count(&fmt, str);
                    break;
                case '%':
                    *fmt.str++ = '%';
                    break;
                default:
                    *fmt.str++ = *p;
                    break;
            }
        } else {
            *fmt.str++ = *p;
        }
    }

    *fmt.str = '\0';
    va_end(fmt.args);
    
    return fmt.str - str;
}

const char* parse_int(const char *p, Fmt *fmt) {
    fmt->width = 0;

    while (*p >= '0' && *p <= '9') {
        fmt->width = fmt->width * 10 + (*p - '0');
        p++;
    }

    return p;
}

// Macro to convert an integer to a string
#define int_to_str(number, str)     \
  char *start = str;                \
  int is_negative = 0;              \
  int i = 0;                        \
                                    \
  if (number < 0) {                 \
    is_negative = 1;                \
    number = -number;               \
  }                                 \
                                    \
  do {                              \
    *str++ = (number % 10) + '0';   \
    number /= 10;                   \
    i++;                            \
  } while (number > 0);             \
                                    \
  if (is_negative) {                \
    *str++ = '-';                   \
    i++;                            \
  }                                 \
                                    \
  *str = '\0';                      \
                                    \
  for (int j = 0; j < i / 2; j++) { \
    char temp = start[j];           \
    start[j] = start[i - j - 1];    \
    start[i - j - 1] = temp;        \
  }                                 \

// Macro to convert an unsigned integer to a string
#define unsigned_int_to_str(number, str) \
  char *start = str;                     \
  int i = 0;                             \
                                         \
  do {                                   \
    *str++ = (number % 10) + '0';        \
    number /= 10;                        \
    i++;                                 \
  } while (number > 0);                  \
                                         \
  *str = '\0';                           \
                                         \
  for (int j = 0; j < i / 2; j++) {      \
    char temp = start[j];                \
    start[j] = start[i - j - 1];         \
    start[i - j - 1] = temp;             \
  }

// Macro to convert an hexadecimal to a string
#define hexadecimal_to_str(number, str, hex_case) \
  char *start = str;                              \
  int i = 0;                                      \
                                                  \
  do {                                            \
    if ((number % 16) < 10) {                     \
      *str++ = '0' + (number % 16);               \
    } else {                                      \
      *str++ = hex_case + ((number % 16) - 10);   \
    }                                             \
                                                  \
    number /= 16;                                 \
                                                  \
    i++;                                          \
  } while (number > 0);                           \
                                                  \
  *str = '\0';                                    \
                                                  \
  for (int j = 0; j < i / 2; j++) {               \
    char temp = start[j];                         \
    start[j] = start[i - j - 1];                  \
    start[i - j - 1] = temp;                      \
  }

void insert_integer(Fmt *fmt) {
    if(s21_strcmp(fmt->length, "") == 0){
        int number = va_arg(fmt->args, int);
        int_to_str(number, fmt->str);

    } else if(s21_strcmp(fmt->length, "l") == 0){
        long int number = va_arg(fmt->args, long int);
        int_to_str(number, fmt->str);

    } else if(s21_strcmp(fmt->length, "ll") == 0){
        long long int number = va_arg(fmt->args, long long int);
        int_to_str(number, fmt->str);
        
    } else if(s21_strcmp(fmt->length, "h") == 0){
        int number = va_arg(fmt->args, int);
        int_to_str(number, fmt->str);

    } else if(s21_strcmp(fmt->length, "hh") == 0){
        int number = va_arg(fmt->args, int);
        int_to_str(number, fmt->str);
    }
}

void insert_string(Fmt *fmt){
    char* string = va_arg(fmt->args, char*);
    
    while (*string) *fmt->str++ = *string++;
    *fmt->str = '\0';
}

void insert_character(Fmt *fmt){
    *fmt->str++ = va_arg(fmt->args, int);
    *fmt->str = '\0';
}

void insert_unsigned_integer(Fmt *fmt){
    if(s21_strcmp(fmt->length, "") == 0){
        unsigned int number = va_arg(fmt->args, unsigned int);
        unsigned_int_to_str(number, fmt->str);
        
    } else if(s21_strcmp(fmt->length, "l") == 0){
        unsigned long int number = va_arg(fmt->args, unsigned long int);
        unsigned_int_to_str(number, fmt->str);

    } else if(s21_strcmp(fmt->length, "ll") == 0){
        unsigned long long int number = va_arg(fmt->args, unsigned long long int);
        unsigned_int_to_str(number, fmt->str);
    } else if(s21_strcmp(fmt->length, "h") == 0){
        int number = va_arg(fmt->args, int);
        unsigned_int_to_str(number, fmt->str);
    } else if(s21_strcmp(fmt->length, "hh") == 0){
        int number = va_arg(fmt->args, int);
        unsigned_int_to_str(number, fmt->str);
    }
}

void insert_hexadecimal(Fmt *fmt){
    char hex_case;

    if(fmt->specifier == 'x'){
        hex_case = 'a';
    } else {
        hex_case = 'A';
    }

    if(s21_strcmp(fmt->length, "") == 0){
        unsigned int number = va_arg(fmt->args, unsigned int);
        hexadecimal_to_str(number, fmt->str, hex_case);
    } else if(s21_strcmp(fmt->length, "l") == 0){
        unsigned long number = va_arg(fmt->args, unsigned long);
        hexadecimal_to_str(number, fmt->str, hex_case);
    } else if(s21_strcmp(fmt->length, "ll") == 0){
        unsigned long long number = va_arg(fmt->args, unsigned long long);
        hexadecimal_to_str(number, fmt->str, hex_case);
    } else if(s21_strcmp(fmt->length, "h") == 0){
        int number = va_arg(fmt->args, int);
        hexadecimal_to_str(number, fmt->str, hex_case);
    } else if(s21_strcmp(fmt->length, "hh") == 0){
        int number = va_arg(fmt->args, int);
        hexadecimal_to_str(number, fmt->str, hex_case);
    }
}

void insert_pointer(Fmt *fmt) {
    void *ptr = va_arg(fmt->args, void *);
    unsigned long address = (unsigned long)ptr;

    if(address == 0){
      *fmt->str++ = '(';
      *fmt->str++ = 'n';
      *fmt->str++ = 'i';
      *fmt->str++ = 'l';
      *fmt->str++ = ')';
      *fmt->str = '\0';
      return;
    }

    *fmt->str++ = '0';
    *fmt->str++ = 'x';

    hexadecimal_to_str(address, fmt->str, 'a');
}

void return_count(Fmt *fmt, char *str){
    int *count = va_arg(fmt->args, int *);

    *count = fmt->str - str;
}
