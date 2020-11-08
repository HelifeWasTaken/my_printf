/*
** EPITECH PROJECT, 2020
** my_vn_putnbr
** File description:
** putnbr_redirection
*/

#include <stdarg.h>
#include <my_printf.h>
#include <my_stdio.h>
#include <my_math.h>

int my_vn_putnbr(va_list *arg, flag_modifiers_t modification_flag)
{
    int new_data = va_arg(*arg, int);
    int new_data_size = get_nb_size(new_data, 10);
    int potential_spaces = 0;

    prepare_print_int(&modification_flag, new_data_size, &potential_spaces,
                      new_data);
    for (int i = 0; i < modification_flag.precision - new_data_size; i++)
        my_putchar('0');
    my_put_nbr(new_data);
    prints_the_following_spaces(potential_spaces);
    if (modification_flag.precision - new_data_size > 0)
        return (potential_spaces + new_data_size +
                (modification_flag.precision - new_data_size) +
                modification_flag.already_printed);
    else
        return (potential_spaces + new_data_size +
                modification_flag.already_printed);
}
