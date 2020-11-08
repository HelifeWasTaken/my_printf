/*
** EPITECH PROJECT, 2020
** my_vn_putoctal
** File description:
** put_in_hex
*/

#include <stdbool.h>
#include <stdarg.h>
#include <my_printf.h>
#include <my_math.h>

int my_vn_putoctal(va_list *arg, flag_modifiers_t modification_flag)
{
    int new_data = va_arg(*arg, int);
    int size_new_data = get_nb_size(new_data, 8);

    prepare_print_oct(&modification_flag, size_new_data);
    my_putnbr_base(new_data, 8, 1);
    return (size_new_data + modification_flag.already_printed);
}