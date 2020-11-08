/*
** EPITECH PROJECT, 2020
** prepare_print_str
** File description:
** prepare_the_string
*/

#include <my_printf.h>
#include <my_stdio.h>

void prepare_print_str(flag_modifiers_t *modification_flag, int to_be_printed,
        int *potential_following_space)
{
    if (to_be_printed >= modification_flag->space_padding)
        return;
    if (modification_flag->space_padding) {
        if (modification_flag->minus)
            *potential_following_space = modification_flag->space_padding;
        else
            modification_flag->already_printed =
                modification_flag->space_padding;
    }
    if (modification_flag->already_printed) {
        for (int i = 0;
        i < modification_flag->already_printed - to_be_printed; i++)
            my_putchar(' ');
    }
}
