/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <stdbool.h>
#include <unistd.h>

void my_putfloat(float nb, int precision);

int get_nb_size(double nb);

int my_vn_putfloat_precision_6(void *data)
{
    float *new_data = (float *)data;
    my_putfloat(*new_data, 6);
    return (7 + get_nb_size(((long)data)));
}
