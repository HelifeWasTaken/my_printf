/*
** EPITECH PROJECT, 2020
** prepare_print_int
** File description:
** prepare_the_string
*/

#include <my_printf.h>
#include <my_stdio.h>
#include <my_math.h>

static void continue_print_int(flag_modifiers_t *modification_flag,
        int *potential_following_space,
        int to_be_printed)
{
    if (modification_flag->plus) {
        my_putchar('+');
        modification_flag->already_printed += 1;
    }
    if (modification_flag->minus) {
        *potential_following_space = modification_flag->space_padding -
            modification_flag->plus - to_be_printed;
        return;
    }
    if (modification_flag->zero) {
        modification_flag->already_printed += modification_flag->space_padding;
        for (int i = 0; i < modification_flag->space_padding; i++)
            my_putchar('0');
    }
}

void prepare_print_int(flag_modifiers_t *modification_flag, int to_be_printed,
        int *potential_following_space, long long nb)
{
    if (to_be_printed > modification_flag->space_padding)
        return;
    if (modification_flag->plus && modification_flag->space_padding) {
        if (nb > 0)
            modification_flag->space_padding -= 1;
        else
            modification_flag->plus = 0;
    }
    if ((modification_flag->minus || modification_flag->precision) &&
            modification_flag->zero) {
        modification_flag->zero = 0;
        prints_the_following_spaces(modification_flag->space_padding -
                to_be_printed);
    }
    continue_print_int(modification_flag, potential_following_space,
            to_be_printed);
}
