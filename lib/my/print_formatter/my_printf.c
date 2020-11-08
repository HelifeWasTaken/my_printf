/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_in_a_format_given
*/

#include <stdarg.h>
#include <my_stdlib.h>
#include <my_printf.h>
#include <stdlib.h>
#include <my_stdio.h>
#include <my_math.h>
#include <my_str.h>
#include <stdio.h>

/*
**
** This the first function invoked like the original one
**
** It simply goes into the whole string and parse
** it in a very primitive algorithm
**
** It looks at the first one if it's a percentage and the second is not
** send the argument to the my_printf parser
**
** Edit :
** It does no send the argument anymore directly but send the list of arguments
**
**
** If both *str and str[1] are a percentage it prints a percentage
** then process
**
** Otherwise it simply print with my_putchar
**
*/

int my_printf(char const *str, ...)
{
    int count = 0;
    va_list arg;
    va_start(arg, str);

    if (!str)
        return (0);
    while (*str) {
        if (*str == '%' && str[1] != '%') {
            str++;
            count += my_printf_parser(&str, &arg, count);
        } else if (*str == '%' && str[1] == '%') {
            my_putstr("%");
            str += 2;
            count += 2;
        } else {
            my_putchar(*str++);
            count++;
        }
    }
    va_end(arg);
    return (count);
}
