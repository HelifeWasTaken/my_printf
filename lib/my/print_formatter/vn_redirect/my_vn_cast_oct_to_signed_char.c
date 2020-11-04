/*
** EPITECH PROJECT, 2020
** my_cast_int_to_signed_char
** File description:
** cast_numbers
*/

#include <stdarg.h>
#include <stdbool.h>

void my_putnbr_base(long long nb, int base, bool uppercase);

int get_nb_size(long long nb, int base);

int my_vn_cast_oct_to_signed_char(va_list *arg)
{
    signed char new_data = va_arg(*arg, int);

    my_putnbr_base(new_data, 8, 1);
    return (get_nb_size(new_data, 8));
}
