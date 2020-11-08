/*
** EPITECH PROJECT, 2020
** my_vn_putpointer.c
** File description:
** my_putpointer
*/

#include <my_stdio.h>
#include <my_printf.h>

void my_putpointer(long nb);

int my_vn_putpointer(va_list *arg, flag_modifiers_t modification_flag)
{
    (void)modification_flag;
    my_putpointer(va_arg(*arg, long));
    return (14);
}