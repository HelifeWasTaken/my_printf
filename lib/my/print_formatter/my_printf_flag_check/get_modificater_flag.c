/*
** EPITECH PROJECT, 2020
** get_modification_flag
** File description:
** get_modification
*/

#include <my_printf.h>
#include <my_math.h>
#include <my_str.h>
#include <stdbool.h>
#include <my_stdlib.h>
#include <my_stdio.h>

static bool get_the_flag(char const c, flag_modifiers_t *flag_modificater)
{
    switch (c) {
        case '0':
            flag_modificater->zero = true;
            return (true);
        case '#':
            flag_modificater->hashtag = true;
            return (true);
        case ' ':
            flag_modificater->count_spaces += 1;
            return (true);
        case '+':
            flag_modificater->plus = true;
            return (true);
        case '-':
            flag_modificater->minus = true;
            return (true);
        default:
            return (false);
    }
}

static void intialize_struct_to_zero(flag_modifiers_t *flag_modificater)
{
    flag_modificater->last_flag = NULL;
    flag_modificater->zero = false;
    flag_modificater->hashtag = false;
    flag_modificater->plus = false;
    flag_modificater->minus = false;
    flag_modificater->found_precision = false;
    flag_modificater->count_spaces = 0;
    flag_modificater->space_padding = 0;
    flag_modificater->precision = 0;
    flag_modificater->offset = 0;
    flag_modificater->already_printed = 0;
}

static void get_precision(char const **str, flag_modifiers_t *flag_modificater)
{
    (flag_modificater->offset)++;
    flag_modificater->found_precision = true;
    if (is_num_letter(*(*str + flag_modificater->offset))) {
        flag_modificater->precision =
            my_getnbr(*str + flag_modificater->offset);
        flag_modificater->offset +=
            get_nb_size(flag_modificater->precision, 10);
    } else
        flag_modificater->precision = 1;
}

void get_modification_flag(char const **str, flag_modifiers_t *flag_modificater)
{
    intialize_struct_to_zero(flag_modificater);
    while ((**str) + flag_modificater->offset &&
            get_the_flag(*(*str + flag_modificater->offset), flag_modificater))
        (flag_modificater->offset)++;
    if (is_num_letter(*(*str + flag_modificater->offset))) {
        flag_modificater->space_padding =
            my_getnbr(*str + flag_modificater->offset);
        flag_modificater->offset +=
            get_nb_size(flag_modificater->space_padding, 10);
    }
    if (*(*str + flag_modificater->offset) == '.') {
        get_precision(str, flag_modificater);
    }
}
