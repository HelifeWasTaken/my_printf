/*
** EPITECH PROJECT, 2020
** prepare_print_oct
** File description:
** prepare
*/

#include <my_stdio.h>
#include <my_printf.h>

void process_print_oct_precision(flag_modifiers_t *modification_flag,
                                 int to_be_printed)
{
    int tmp = 0;

    if (modification_flag->hashtag) {
        my_putchar('0');
        (modification_flag->already_printed)++;
        tmp = 1;
    }
    for (int i = 0; i < modification_flag->precision - tmp - to_be_printed; i++)
        my_putchar('0');
    if (modification_flag->precision - to_be_printed - tmp > 0)
        modification_flag->already_printed +=
                modification_flag->precision - to_be_printed - tmp;
}

void prepare_print_oct(flag_modifiers_t *modification_flag, int to_be_printed)
{
    int tmp = 0;

    if (modification_flag->found_precision) {
        process_print_oct_precision(modification_flag, to_be_printed);
        return;
    }
    if (modification_flag->hashtag) {
        my_putchar('0');
        (modification_flag->already_printed)++;
        tmp = 1;
    }
    for (int i = 0; i < modification_flag->space_padding - tmp - to_be_printed;
         i++)
        my_putchar('0');
    if (modification_flag->space_padding - to_be_printed - tmp > 0)
        modification_flag->already_printed +=
                modification_flag->space_padding - to_be_printed - tmp;
}