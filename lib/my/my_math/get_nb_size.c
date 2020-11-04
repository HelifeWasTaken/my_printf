/*
** EPITECH PROJECT, 2020
** get_nb_size_base.c
** File description:
** get_a_number_asize
*/

#include <my_stdio.h>

int get_nb_size(long long nb, int base)
{
    int count = 0;

    if (nb < 0) {
        nb = -nb;
        count++;
    }
    do {
        nb /= base;
        count++;
    } while (nb > base);
    return (count);
}
