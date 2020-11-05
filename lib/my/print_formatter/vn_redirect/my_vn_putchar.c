/*
** EPITECH PROJECT, 2020
** my_vn_putchar
** File description:
** putchar_for_printf
*/

#include <unistd.h>
#include <stdarg.h>

int my_vn_putchar(va_list *arg)
{
    int new_data = va_arg(*arg, int);

    write(1, &new_data, 1);
    return (1);
}
