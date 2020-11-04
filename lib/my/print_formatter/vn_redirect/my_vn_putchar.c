/*
** EPITECH PROJECT, 2020
** my_vn_putchar
** File description:
** putchar_for_printf
*/

#include <unistd.h>

int my_vn_putchar(void *data)
{
    write(1, (char *)&data, 1);
    return (1);
}
