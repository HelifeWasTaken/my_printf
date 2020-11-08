/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** Print every non printable character with their hex value
*/

#include <stddef.h>
#include <my_stdio.h>
#include <my_printf.h>
#include <my_str.h>

int my_vn_showstr_oct(va_list *arg, flag_modifiers_t flag_modification)
{
    size_t i;
    char *new_data = va_arg(*arg, char *);

    (void)flag_modification;
    if (!new_data)
        return (0);
    for (i = 0; new_data[i]; i++) {
        if (!(new_data[i] >= 32 && new_data[i] <= 126))
            print_char_in_oct(new_data[i]);
        else
            my_putchar(new_data[i]);
    }
    return ((int)i);
}
