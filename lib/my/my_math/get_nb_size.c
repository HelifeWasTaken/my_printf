/*
** EPITECH PROJECT, 2020
** get_nb_size_base.c
** File description:
** get_a_number_asize
*/

#include <my_stdio.h>

int get_nb_size(long long int nb, int base)
{
    int count = 1;

    if (nb < 0) {
        nb = -nb;
        count++;
    }
    while (nb >= base) {
        nb /= base;
        count++;
    }
    return (count);
}
