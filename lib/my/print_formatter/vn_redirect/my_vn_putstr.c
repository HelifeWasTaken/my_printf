/*
** EPITECH PROJECT, 2020
** my_vn_putstr
** File description:
** putstr
*/

#include <my_str.h>
#include <stdarg.h>
#include <unistd.h>

void my_putstr(char const *str);

int my_vn_putstr(va_list *arg)
{
    char *new_data = va_arg(*arg, char *);
    int size_new_data = my_strlen(new_data);

    write(1, new_data, size_new_data);
    return (size_new_data);
}
