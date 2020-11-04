/*
** EPITECH PROJECT, 2020
** my_vn_putstr
** File description:
** putstr
*/

#include <my_str.h>

void my_putstr(char const *str);

int my_vn_putstr(void *data)
{
    my_putstr(data);
    return (my_strlen(data));
}
