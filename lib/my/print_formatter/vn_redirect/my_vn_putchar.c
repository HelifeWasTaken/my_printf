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
    write(1, va_arg(*arg, char *), 1);
    return (1);
}
