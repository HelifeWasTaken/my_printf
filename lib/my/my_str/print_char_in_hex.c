/*
** EPITECH PROJECT, 2020
** print_char_in_hex
** File description:
** print_in_hex
*/

#include <stdbool.h>

void my_putchar(char const c);

void my_putnbr_base(int nb, int base, bool uppercase);

void print_char_in_hex(unsigned char c)
{
    if (!c)
        return;
    my_putchar('\\');
    if (c <= 0xF)
        my_putchar('0');
    my_putnbr_base(c, 16, 0);
}
