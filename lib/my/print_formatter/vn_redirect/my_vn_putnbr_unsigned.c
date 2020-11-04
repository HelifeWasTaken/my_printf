/*
** EPITECH PROJECT, 2020
** my_vn_putbin
** File description:
** put_in_bin
*/

#include <stdbool.h>
#include <stdarg.h>

void my_put_nbr_unsigned(unsigned long long nb, int base, bool uppercase);

int get_nb_size(unsigned long long nb, int base);

int my_vn_putnbr_unsigned(va_list *arg)
{
    unsigned int new_data = va_arg(*arg, unsigned int);

    my_put_nbr_unsigned(new_data, 10, 0);
    return (get_nb_size(new_data, 10));
}
