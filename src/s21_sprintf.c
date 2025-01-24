#include "s21_string.h"
#include <stdarg.h>

typedef struct Fmt {
    // Flags that modify output format:
    // '-' : Left-justify
    // '+' : Forces to precede the result with a plus or minus sign (+ or -) 
    // ' ' : Space before positive numbers
    // '#' : Used with o, x or X specifiers the value is preceded with 0, 0x or 0X
    // '0' : Left-pads the number with zeroes
    char flags[10];     

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
    char length;        

    // Format specifier for data type:
    // 'c' : char
    // 'd' : signed int
    // 'i' : signed int
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
} Fmt;




int s21_sprintf(char *str, const char *format, ...) {
    Fmt fmt;
    va_list args;
    va_start(args, format);
    
    int count = 0;
    char *p;
    // %[flags][width][.precision][length]specifier
    for (p = (char *)format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd': {
                    break;
                }
                case 's': {
                    break;
                }
               
                default:
                    str[count++] = *p;
                    break;
            }
        } else {
            str[count++] = *p;
        }
    }
    str[count] = '\0';
    va_end(args);
    return count;
}