/*
** EPITECH PROJECT, 2020
** prepare_print_hex
** File description:
** preapre_for_format_print
*/

#include <my_printf.h>
#include <stdbool.h>
#include <my_stdio.h>

static void print_hashtag_exception(flag_modifiers_t *modification_flag,
                                    bool is_upper)
{
    if (modification_flag->hashtag) {
        if (is_upper)
            my_putstr("0x");
        else
            my_putstr("0X");
        modification_flag->already_printed += 2;
    }
}

static void process_print_hex_precision(flag_modifiers_t *modification_flag,
                                        bool is_upper)
{
    print_hashtag_exception(modification_flag, is_upper);
    for (int i = 0; i < modification_flag->precision; i++)
        my_putchar('0');
    modification_flag->already_printed += modification_flag->precision;
}

void prepare_print_hex(flag_modifiers_t *modification_flag,
                       int *potential_following_space, int to_be_printed,
                       bool is_upper)
{
    if (modification_flag->space_padding <= to_be_printed)
        return;
    if (modification_flag->found_precision) {
        process_print_hex_precision(modification_flag, is_upper);
        return;
    }
    if (modification_flag->minus) {
        *potential_following_space = modification_flag->space_padding;
        modification_flag->space_padding = 0;
    }
    prints_the_following_spaces(modification_flag->space_padding);
    modification_flag->already_printed += modification_flag->space_padding;
    print_hashtag_exception(modification_flag, is_upper);
}