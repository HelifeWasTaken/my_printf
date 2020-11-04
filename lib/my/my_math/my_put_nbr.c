/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

void my_putchar(const char c);

static void process_number(long long nb)
{
   if (nb >= 10) {
        process_number(nb / 10);
        my_putchar((nb % 10) + '0');
    } else
        my_putchar(nb + '0');
}

void my_put_nbr(long long nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    process_number(nb);
}
