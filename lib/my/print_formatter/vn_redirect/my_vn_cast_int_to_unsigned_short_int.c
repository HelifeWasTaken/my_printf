/*
** EPITECH PROJECT, 2020
** my_cast_int_to_signed_char
** File description:
** cast_numbers
*/

#include <stdarg.h>
#include <stdbool.h>

void my_put_nbr(long long nb);

int get_nb_size(long long nb, int base);

int my_vn_cast_int_to_unsigned_short_int(va_list *arg)
{
    unsigned short int new_data = va_arg(*arg, unsigned int);

    my_put_nbr(new_data);
    return (get_nb_size(new_data, 10));
}