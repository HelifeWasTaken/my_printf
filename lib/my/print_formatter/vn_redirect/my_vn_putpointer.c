/*
** EPITECH PROJECT, 2020
** my_vn_putpointer.c
** File description:
** my_putpointer
*/

#include <my_stdio.h>

void my_putpointer(long nb);

int my_vn_putpointer(va_list *arg)
{
    my_putpointer(va_arg(*arg, long));
    return (14);
}
