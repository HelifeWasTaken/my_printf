/*
** EPITECH PROJECT, 2020
** get_nb_size_base.c
** File description:
** get_a_number_asize
*/

#include <my_stdio.h>

int get_nb_size_unsigned(unsigned long long nb, int base)
{
    int count = 0;

    do {
        nb /= base;
        count++;
    } while (nb > (unsigned int)base);
    return (count);
}
