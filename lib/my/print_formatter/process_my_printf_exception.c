/*
** EPITECH PROJECT, 2020
** process_exception
** File description:
** exception
*/

#include <my_printf.h>
#include <my_stdio.h>
#include <my_math.h>
#include <my_str.h>
#include <stdlib.h>

static int print_invalid_stuff(char const **str,
                               flag_modifiers_t flag_modificater)
{
    int tmp_count = 0;
    int i = 0;

    if (*(*str + flag_modificater.offset + 1)) {
        my_putchar('%');
        tmp_count++;
        for (i = 0; i < flag_modificater.offset; i++) {
            my_putchar(**str);
            if (**str == '.') {
                my_putchar('0');
                tmp_count++;
            }
            (*str)++;
        }
    }
    return ((**str) ? i + tmp_count : 255);
}

int my_printf_exception(char const **str, va_list *arg,
                        flag_modifiers_t flag_modificater, int count_char)
{
    if (flag_modificater.last_flag != NULL) {
        (*str) += flag_modificater.offset;
        return (my_vn_get_send_to_stdio(arg, count_char));
    }
    return (print_invalid_stuff(str, flag_modificater));
}
