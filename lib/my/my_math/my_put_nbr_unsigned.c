/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

void my_putchar(const char c);

void my_put_nbr_unsigned(unsigned long long nb)
{
    if (nb >= 10) {
        my_put_nbr_unsigned(nb / 10);
        my_putchar((nb % 10) + '0');
    } else
        my_putchar(nb + '0');
}
