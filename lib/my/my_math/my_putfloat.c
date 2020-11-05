/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <my_stdio.h>
#include <stdbool.h>

static void process_zeros(int precision)
{
    my_putstr("0.");
    for (int i = 0; i < precision; i++)
        my_putchar('0');
}

static void process_number(unsigned long long nb, int precision)
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
    unsigned long long round_nb = 0;

    if (precision < 1 || precision > 6) {
        my_putstr_err("Precision should be between 1 and 6");
        return;
    }
    if (nb == 0) {
        process_zeros(precision);
        return;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    for (int i = 0; i < precision; i++)
        nb *= 10;
    round_nb = nb;
    if (round_nb % 10 == 9 && (round_nb / 10) % 10 == 9)
        round_nb++;
    process_number(round_nb, precision);
}
