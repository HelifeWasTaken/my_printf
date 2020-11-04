/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <my_stdio.h>
#include <stdbool.h>

static void process_number(int nb, int base_size, char const *base)
{
    if (nb >= base_size) {
        process_number(nb / base_size, base_size, base);
        my_putchar(base[nb % base_size]);
    } else
        my_putchar(base[nb]);
}

void my_putnbr_base_unsigned(unsigned int nb, int base_size, bool uppercase)
{
    char const base_higher[36] = "0123456789ABCDEFGHJKLMNOPQRSTUVWXZ";
    char const base_lower[36] = "0123456789abcdefghijklmnopqrstuvwxyz";

    if (base_size < 2 || base_size > 36) {
        my_putstr_err("You must have base size beetween 2 and 36");
        return;
    }
    if (uppercase)
        process_number(nb, base_size, base_higher);
    else
        process_number(nb, base_size, base_lower);
}
