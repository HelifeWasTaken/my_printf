/*
** EPITECH PROJECT, 2020
** my_vn_putbin
** File description:
** put_in_bin
*/

#include <stdbool.h>

void my_putnbr_base_unsigned(unsigned int nb, int base, bool uppercase);

int get_nb_size(long nb, int base);

int my_vn_putbin(void *data)
{
    unsigned int new_data = (long)data;

    my_putnbr_base_unsigned(new_data, 2, 0);
    return (get_nb_size(new_data, 2));
}
