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

/*
**
** This function with the offset provided by flag_modifiers_t it permits me
** to send print the whole invalid string safely
**
** If a '.' is encountered a '0' will be printed before
**
** The percent sign will always be printed
** At the end if **str is equivalent to '\0'
**
** I need to return 255 as real the real function does
**
*/

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

/*
**
** Here as the sstructure flag_modificater is passed as an argument
** I check before if the last flag was a %n if so I can proceed to send it
** into the right function
**
** Otherwise I ask it to send it to print_invalid_stuff()
**
*/

int my_printf_exception(char const **str, va_list *arg,
        flag_modifiers_t flag_modificater, int count_char)
{
    if (flag_modificater.last_flag != NULL) {
        (*str) += flag_modificater.offset;
        return (my_vn_get_send_to_stdio(arg, count_char));
    }
    return (print_invalid_stuff(str, flag_modificater));
}
