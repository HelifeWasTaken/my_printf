/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <stdarg.h>
#include <unistd.h>

void my_putfloat(double nb, int precision);

int get_nb_size(long long nb, int base);

int my_vn_putfloat_precision_6(va_list *arg)
{
    double new_data = va_arg(*arg, double);

    my_putfloat((float)new_data, 6);
    return (7 + get_nb_size((long long)new_data, 10));
}
