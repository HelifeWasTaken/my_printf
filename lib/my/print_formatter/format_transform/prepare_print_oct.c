/*
** EPITECH PROJECT, 2020
** prepare_print_oct
** File description:
** prepare
*/

#include <my_stdio.h>
#include <my_printf.h>
#include <my_all.h>

static void get_first_octal_info(flag_modifiers_t *modification_flag,
        int to_be_printed, int *potential_following_spaces,
        int *real_space_padding)
{
    if (modification_flag->precision < to_be_printed &&
            modification_flag->space_padding < to_be_printed)
        return;
    if (modification_flag->found_precision)
        modification_flag->zero = false;
    if (modification_flag->minus) {
        *potential_following_spaces = *real_space_padding;
        *real_space_padding = 0;
    } else if (modification_flag->zero) {
        for (int i = 0; i < *real_space_padding; i++)
            my_putchar('0');
        modification_flag->already_printed = *real_space_padding;
        *real_space_padding = 0;
    }
}

void prepare_print_oct(flag_modifiers_t *modification_flag, int to_be_printed,
        int *potential_following_spaces)
{
    int nb_size = (modification_flag->precision > to_be_printed) ?
        modification_flag->precision : to_be_printed;
    int real_space_padding =
        (modification_flag->space_padding - nb_size > 0) ?
        modification_flag->space_padding - nb_size : 0;

    get_first_octal_info(modification_flag, to_be_printed,
            potential_following_spaces, &real_space_padding);
    prints_the_following_spaces(real_space_padding);
    modification_flag->already_printed += real_space_padding - nb_size;
    if (nb_size - to_be_printed > 0) {
        for (int i = 0; i < nb_size - to_be_printed; i++)
            my_putchar('0');
        modification_flag->already_printed +=
            modification_flag->precision - to_be_printed;
    }
}
