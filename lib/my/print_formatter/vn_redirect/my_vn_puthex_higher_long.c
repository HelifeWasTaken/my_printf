/*
** EPITECH PROJECT, 2020
** my_vn_puthex_higher
** File description:
** put_in_hex
*/

#include <stdbool.h>
#include <stdarg.h>

void my_putnbr_base(long long nb, int base, bool uppercase);

int get_nb_size(long long nb, int base);

int my_vn_puthex_higher_long(va_list *arg)
{
    long new_data = va_arg(*arg, long);

    my_putnbr_base(new_data, 16, 1);
    return (get_nb_size(new_data, 16));
}
