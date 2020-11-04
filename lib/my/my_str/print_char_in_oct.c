/*
** EPITECH PROJECT, 2020
** print_char_in_hex
** File description:
** print_in_hex
*/

#include <stdbool.h>

void my_putchar(char const c);

void my_putstr(char const *str);

void my_putnbr_base(int nb, int base, bool uppercase);

void print_char_in_oct(unsigned char c)
{
    if (!c)
        return;
    my_putchar('\\');
    if (c < 0x7)
        my_putstr("00");
    else if (c > 0x7 && c < 0x3F)
        my_putstr("0");
    my_putnbr_base(c, 8, 1);
}
