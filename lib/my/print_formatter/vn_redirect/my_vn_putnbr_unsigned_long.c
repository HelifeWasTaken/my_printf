/*
** EPITECH PROJECT, 2020
** my_vn_putoctal
** File description:
** put_in_hex
*/

#include <stdbool.h>
#include <stdarg.h>

void my_putnbr_base_unsigned(unsigned long long nb, int base, bool uppercase);

int get_nb_size_unsigned(unsigned long long nb, int base);

int my_vn_putnbr_unsigned_long(va_list *arg)
{
    unsigned long new_data = va_arg(*arg, unsigned long);

    my_putnbr_base_unsigned(new_data, 10, 1);
    return (get_nb_size_unsigned(new_data, 10));
}
