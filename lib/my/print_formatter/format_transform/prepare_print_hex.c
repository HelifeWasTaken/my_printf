/*
** EPITECH PROJECT, 2020
** prepare_print_hex
** File description:
** preapre_for_format_print
*/

#include <my_printf.h>
#include <my_math.h>
#include <stdbool.h>
#include <my_stdio.h>

static void print_hashtag_exception(flag_modifiers_t *modification_flag,
        bool is_upper)
{
    if (modification_flag->hashtag) {
        if (is_upper)
            my_putstr("0X");
        else
            my_putstr("0x");
        modification_flag->already_printed += 2;
        if (modification_flag->hashtag && modification_flag->space_padding >= 2)
            modification_flag->space_padding -= 2;
    }
}

static void process_print_hex_precision(flag_modifiers_t *modification_flag,
        bool is_upper, int to_be_printed)
{
    int temp_hashtag_value = 0;

    if (modification_flag->hashtag)
        temp_hashtag_value += 2;
    if (modification_flag->precision > 8) {
        prints_the_following_spaces(modification_flag->space_padding -
                modification_flag->precision - temp_hashtag_value);
        modification_flag->already_printed = modification_flag->space_padding;
    } else if (modification_flag->space_padding) {
        prints_the_following_spaces(modification_flag->space_padding -
                to_be_printed - temp_hashtag_value);
        modification_flag->already_printed += modification_flag->space_padding -
            to_be_printed - temp_hashtag_value;
    }
    print_hashtag_exception(modification_flag, is_upper);
    for (int i = 0; i < modification_flag->precision - to_be_printed; i++)
        my_putchar('0');
}

void prepare_print_hex(flag_modifiers_t *modification_flag,
        int *potential_following_space, int to_be_printed,
        bool is_upper)
{
    if (modification_flag->found_precision) {
        process_print_hex_precision(modification_flag, is_upper, to_be_printed);
        return;
    }
    if (modification_flag->space_padding <= to_be_printed) {
        print_hashtag_exception(modification_flag, is_upper);
        return;
    }
    if (modification_flag->minus) {
        *potential_following_space = modification_flag->space_padding;
        modification_flag->space_padding = 0;
    }
    print_hashtag_exception(modification_flag, is_upper);
    modification_flag->space_padding -= to_be_printed;
    if (modification_flag->zero)
        for (int i = 0; i < modification_flag->space_padding; i++)
            my_putchar('0');
    else
        prints_the_following_spaces(modification_flag->space_padding);
    modification_flag->already_printed += modification_flag->space_padding;
}
