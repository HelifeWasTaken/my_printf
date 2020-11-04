/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <my_stdio.h>
#include <stdbool.h>

static void process_number(unsigned long nb, int precision)
{
    if (nb >= 10) {
        process_number(nb / 10, precision - 1);
        my_putchar((nb % 10) + '0');
    } else
        my_putchar((nb % 10) + '0');
    if (precision == 0)
        my_putchar('.');
}

void my_putfloat(double nb, int precision)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    for (int i = 0; i < precision; i++)
        nb *= 10;
    process_number((unsigned long)nb, precision);
}
