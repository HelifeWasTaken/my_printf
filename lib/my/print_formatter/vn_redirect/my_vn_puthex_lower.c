/*
** EPITECH PROJECT, 2020
** my_vn_puthex_lower
** File description:
** put_in_hex
*/

#include <stdbool.h>
#include <stdarg.h>
#include <my_math.h>
#include <my_printf.h>

int my_vn_puthex_lower(va_list *arg, flag_modifiers_t flag_modificater)
{
    unsigned int new_data = va_arg(*arg, unsigned int);
    int new_data_size = get_nb_size_unsigned(new_data, 16);
    int potential_following_spaces = 0;

    prepare_print_hex(&flag_modificater, &potential_following_spaces,
                      new_data_size, 0);
    prints_the_following_spaces(potential_following_spaces);
    my_putnbr_base_unsigned(new_data, 16, 0);
    return (new_data_size + potential_following_spaces +
            flag_modificater.already_printed);
}