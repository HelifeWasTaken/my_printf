/*
** EPITECH PROJECT, 2020
** my_vn_putoctal
** File description:
** put_in_hex
*/

#include <stdbool.h>

void my_putnbr_base(int nb, int base, bool uppercase);

int get_nb_size(long nb, int base);

int my_vn_putoctal(void *data)
{
    int new_data = (long)data;

    my_putnbr_base(new_data, 8, 1);
    return (get_nb_size(new_data, 8));
}
