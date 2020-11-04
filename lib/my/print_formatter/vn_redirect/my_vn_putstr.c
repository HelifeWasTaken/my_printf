/*
** EPITECH PROJECT, 2020
** my_vn_putstr
** File description:
** putstr
*/

#include <my_str.h>
#include <stdarg.h>

void my_putstr(char const *str);

int my_vn_putstr(va_list *arg)
{
    char *new_data = va_arg(*arg, char *);

    my_putstr(new_data);
    return (my_strlen(new_data));
}
