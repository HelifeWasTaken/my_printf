/*
** EPITECH PROJECT, 2020
** get_send_to_stdio
** File description:
** transferring_value_for_percentage_n_flag
*/

#include <stdarg.h>

int my_vn_get_send_to_stdio(va_list *arg, int count_char)
{
    int *new_data = va_arg(*arg, int *);

    *new_data = count_char;
    return (0);
}