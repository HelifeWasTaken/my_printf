/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <stdarg.h>
#include <my_printf.h>
#include <my_math.h>
#include <my_stdio.h>

int my_vn_putfloat(va_list *arg, flag_modifiers_t flag_modificater)
{
    double new_data = va_arg(*arg, double);

    if (flag_modificater.default_precision ||
        !(flag_modificater.found_precision)) {
        my_putfloat((float)new_data, 6);
        return (7 + get_nb_size((long long)new_data, 10));
    } else {
        my_putfloat((float)new_data, flag_modificater.precision);
        return (1 + flag_modificater.precision +
                get_nb_size((long long)new_data, 10));
    }
}
