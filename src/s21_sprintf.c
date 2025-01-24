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
    char length[2];        

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
    // 'p' : pointer
    // 'n' : Number of characters printed until %n occurs
    // '%' : literal percent
    char specifier;

    // Variable argument list to hold the additional arguments
    va_list args;
} Fmt;

const char* parse_int(const char *p, Fmt *fmt);
void insert_integer(char *str, Fmt *fmt);
void insert_string(char *str, Fmt *fmt);

int s21_sprintf(char *str, const char *format, ...) {
    Fmt fmt = {0};
    va_start(fmt.args, format);
    
    int i = 0;
    for (const char *p = format; *p; p++) {
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
            if (*p++ == '.') p = parse_int(p, &fmt);

            // Handle length modifier
            if (*p == 'h' || *p == 'l' || *p == 'L') {
                fmt.length[0] = *p;
                p++;
            }
            // long long int
            if (*p == 'l') {
                fmt.length[1] = *p;
                p++;
            }

            // Handle the format specifier
            fmt.specifier = *p;

            // Process the specifier
            switch (fmt.specifier) {
                case 'd':
                case 'i':
                    insert_integer(str, &fmt);
                    break;
                case 's':
                    insert_string(str, &fmt);
                    break;
                case 'c':
                    // insert_character(str, &fmt);
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
                    break;
                case 'x':
                case 'X':
                    break;
                case 'p':
                    break;
                case 'n':
                    break;
                case '%':
                    str[i++] = '%';
                    break;
                default:
                    str[i++] = *p;
                    break;
            }
        } else {
            str[i++] = *p;
        }
    }

    str[i] = '\0';
    va_end(fmt.args);
    
    return i;
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
#define int_to_str(number, str)       \
  do {                                \
    int is_negative = 0;              \
    int i = 0;                        \
                                      \
    if (number < 0) {                 \
      is_negative = 1;                \
      number = -number;               \
    }                                 \
                                      \
    do {                              \
      str[i++] = (number % 10) + '0'; \
      number /= 10;                   \
    } while (number > 0);             \
                                      \
    if (is_negative) {                \
      str[i++] = '-';                 \
    }                                 \
                                      \
    str[i] = '\0';                    \
                                      \
    for (int j = 0; j < i / 2; j++) { \
      char temp = str[j];             \
      str[j] = str[i - j - 1];        \
      str[i - j - 1] = temp;          \
    }                                 \
  } while (0)

void insert_integer(char *str, Fmt *fmt) {
    if(fmt->specifier == 'd'){
        if(fmt->length == 0){
            int number = va_arg(fmt->args, int);
            int_to_str(number, str);
            
        } else if(s21_strcmp(fmt->length, "l") == 0){
            long int number = va_arg(fmt->args, long int);
            int_to_str(number, str);

        } else if(s21_strcmp(fmt->length, "ll") == 0){
            long long int number = va_arg(fmt->args, long long int);
            int_to_str(number, str);
            
        }
    } else /* 'i' */ {
        if(fmt->length == 0){
            int number = va_arg(fmt->args, int);
            int_to_str(number, str);

        } else if(s21_strcmp(fmt->length, "l") == 0){
            long int number = va_arg(fmt->args, long int);
            int_to_str(number, str);

        } else if(s21_strcmp(fmt->length, "ll") == 0){
            long long int number = va_arg(fmt->args, long long int);
            int_to_str(number, str);
            
        }
    }

}

void insert_string(char *str, Fmt *fmt){
    char* string = va_arg(fmt->args, char*);
    s21_strcat(str, string);
}
