/*
** EPITECH PROJECT, 2020
** my_vn_putoctal
** File description:
** put_in_hex
*/

#include <stdbool.h>
#include <stdarg.h>

void my_putnbr_base(long long nb, int base, bool uppercase);

int get_nb_size(long long nb, int base);

int my_vn_putoctal(va_list *arg)
{
    int new_data = va_arg(*arg, int);

    my_putnbr_base(new_data, 8, 1);
    return (get_nb_size(new_data, 8));
}
