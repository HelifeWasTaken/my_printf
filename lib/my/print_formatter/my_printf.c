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
** The error check function is created in case the guy printed a single
** % potentially multiple spaces and nothing more
**
** If this case is true my_printf end up returning -1
**
*/

static bool check_my_printf_basic_errors(char const *str, va_list *arg)
{
    int found_twice = false;

    for (int i = 0; str[i]; i++) {
        if ((str[i] != ' ' && str[i] != '%') || found_twice == 2)
            return (true);
        if (str[i] == '%')
            found_twice++;
    }
    if (found_twice == 2)
        return (true);
    va_end(*arg);
    return (false);
}

/*
** This loop check for a moment in the string
** that has a single percentage and no % following it to go into the parser
** Otherwise it simply print each character
**
** This loop also permits me to handle the %% flag
**
*/

int my_vprintf(char const *str, va_list *arg)
{
    int count = 0;

    while (*str) {
        if (*str == '%' && str[1] != '%') {
            str++;
            count += my_printf_parser(&str, arg, count);
        } else if (*str == '%' && str[1] == '%') {
            my_putchar('%');
            str += 2;
            count += 2;
        } else {
            my_putchar(*str++);
            count++;
        }
        va_end(*arg);
    }
    return (count);
}

/*
** This simply initiate a va_list
** and call the my_printf loop and the error chec
*/

int my_printf(char const *str, ...)
{
    va_list arg;
    va_start(arg, str);

    if (!check_my_printf_basic_errors(str, &arg))
        return (-1);
    return (my_vprintf(str, &arg));
}
