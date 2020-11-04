/*
** EPITECH PROJECT, 2020
** my_put_pointer.c
** File description:
** Printing numbers
*/

#include <stdbool.h>

void my_putstr(char const *str);

void my_putchar(char const c);

static void process_number(long nb, int base_size, char const *base)
{
    if (nb >= base_size) {
        process_number(nb / base_size, base_size, base);
        my_putchar(base[nb % base_size]);
    } else
        my_putchar(base[nb]);
}

void my_putpointer(long nb)
{
    my_putstr("0x");
    process_number(nb, 16, "0123456789abcdef");
}
