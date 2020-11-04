/*
** EPITECH PROJECT, 2020
** my_vn_putbin
** File description:
** put_in_bin
*/

#include <stdbool.h>
#include <stdarg.h>

void my_putnbr_base_unsigned(unsigned int nb, int base, bool uppercase);

int get_nb_size_unsigned(unsigned long long nb, int base);

int my_vn_putbin(va_list *arg)
{
    unsigned int new_data = va_arg(*arg, unsigned int);

    my_putnbr_base_unsigned(new_data, 2, 0);
    return (get_nb_size_unsigned(new_data, 2));
}
