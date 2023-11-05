#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0;  // To keep track of the number of characters printed
    
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            
            if (*format == 'c') {
                char character = va_arg(args, int);
                _putchar(character);
                count++;
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                while (*str) {
                    _putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                _putchar('%');
                count++;
            }
        } else {
            _putchar(*format);
            count++;
        }
        
        format++; // Move to the next character in the format string
    }
    
    va_end(args);
    return count;
}
