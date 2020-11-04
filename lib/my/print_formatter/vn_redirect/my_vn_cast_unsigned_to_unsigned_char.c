/*
** EPITECH PROJECT, 2020
** my_cast_int_to_signed_char
** File description:
** cast_numbers
*/

#include <stdarg.h>

void my_put_nbr(long long nb);

int get_nb_size(long long nb, int base);

int my_vn_cast_unsigned_to_unsigned_char(va_list *arg)
{
    unsigned char new_data = va_arg(*arg, unsigned int);

    my_put_nbr((unsigned char)new_data);
    return (get_nb_size((unsigned char)new_data, 10));
}
