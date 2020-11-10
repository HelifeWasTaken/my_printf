/*
** EPITECH PROJECT, 2020
** prepare_print_unsigned_int
** File description:
** prepare_the_string
*/

#include <my_printf.h>
#include <my_stdio.h>
#include <my_math.h>

    static void
get_print_unsigned_int_transformations(flag_modifiers_t *modification_flag)
{
    if (modification_flag->plus) {
        modification_flag->found_space = false;
        modification_flag->already_printed += 1;
        modification_flag->space_padding -= 1;
    }
    if (modification_flag->found_space) {
        my_putchar(' ');
        modification_flag->already_printed += 1;
        modification_flag->space_padding -= 1;
    }
    if (modification_flag->zero && modification_flag->minus)
        modification_flag->zero = false;
}

    static void
print_precision_with_bigger_padding(flag_modifiers_t *modification_flag,
        int to_be_printed)
{
    int temp = modification_flag->space_padding - to_be_printed -
        modification_flag->already_printed;
    int temp2 = modification_flag->precision - to_be_printed -
        modification_flag->already_printed;

    if (modification_flag->zero) {
        for (int i = 0; i < temp; i++)
            my_putchar('0');
        if (temp > 0)
            modification_flag->already_printed += temp;
    } else if (modification_flag->found_precision) {
        for (int i = 0; i < temp2; i++)
            my_putchar('0');
        if (temp2 > 0)
            modification_flag->already_printed += temp2;
    }
}

static void process_print_no_precision(flag_modifiers_t *modification_flag,
        int to_be_printed,
        int *potential_following_space)
{
    print_precision_with_bigger_padding(modification_flag, to_be_printed);
    if (modification_flag->space_padding - to_be_printed -
            modification_flag->already_printed >
            0 &&
            !(modification_flag->zero)) {
        if (modification_flag->minus) {
            *potential_following_space = modification_flag->space_padding -
                to_be_printed -
                modification_flag->already_printed;
        } else
            prints_the_following_spaces(modification_flag->space_padding -
                    to_be_printed -
                    modification_flag->already_printed);
    }
    if (modification_flag->plus)
        my_putchar('+');
}

void process_print_unsigned_int_precision(flag_modifiers_t *modfication_flag,
        int to_be_printed)
{
    if (modfication_flag->plus)
        my_putchar('+');
    for (int i = 0; i < modfication_flag->precision - to_be_printed; i++)
        my_putchar('0');
    if (modfication_flag->precision - to_be_printed > 0)
        modfication_flag->already_printed +=
            modfication_flag->precision - to_be_printed;
}

void prepare_print_unsigned_int(flag_modifiers_t *modification_flag,
        int to_be_printed,
        int *potential_following_space)
{
    if (modification_flag->precision < to_be_printed &&
            modification_flag->space_padding < to_be_printed) {
        if (modification_flag->plus)
            my_putchar('+');
        return;
    }
    get_print_unsigned_int_transformations(modification_flag);
    if (modification_flag->precision > modification_flag->space_padding) {
        process_print_unsigned_int_precision(modification_flag, to_be_printed);
        return;
    }
    process_print_no_precision(modification_flag, to_be_printed,
            potential_following_space);
}
