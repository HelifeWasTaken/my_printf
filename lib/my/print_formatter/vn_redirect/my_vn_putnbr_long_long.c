/*
** EPITECH PROJECT, 2020
** my_vn_putnbr
** File description:
** putnbr_redirection
*/

#include <stdarg.h>

void my_put_nbr(long long nb);

int get_nb_size(long long nb, int base);

int my_vn_putnbr_long_long(va_list *arg)
{
    long long new_data = va_arg(*arg, long long);

    my_put_nbr(new_data);
    return (get_nb_size(new_data, 10));
}
