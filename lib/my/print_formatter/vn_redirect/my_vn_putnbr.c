/*
** EPITECH PROJECT, 2020
** my_vn_putnbr
** File description:
** putnbr_redirection
*/

#include <stdarg.h>
#include <my_printf.h>
#include <my_stdio.h>
#include <my_math.h>
#include <my_str.h>

static long long parse_my_int(va_list *arg, flag_modifiers_t modification_flag)
{
    char *temp = modification_flag.last_flag;

    if (my_strncmp(temp, "d", my_strlen(temp)) == 0 ||
            my_strncmp(temp, "i", my_strlen(temp)) == 0)
        return ((int)va_arg(*arg, int));
    if (my_strncmp(temp, "ld", my_strlen(temp)) == 0 ||
            my_strncmp(temp, "li", my_strlen(temp)) == 0)
        return ((long)va_arg(*arg, long));
    if (my_strncmp(temp, "lld", my_strlen(temp)) == 0 ||
            my_strncmp(temp, "lli", my_strlen(temp)) == 0)
        return ((long long)va_arg(*arg, long long));
    if (my_strncmp(temp, "hd", my_strlen(temp)) == 0 ||
            my_strncmp(temp, "hi", my_strlen(temp)) == 0)
        return ((short int)va_arg(*arg, int));
    if (my_strncmp(temp, "hhd", my_strlen(temp)) == 0 ||
            my_strncmp(temp, "hhi", my_strlen(temp)) == 0)
        return ((char)va_arg(*arg, int));
    return ((long long)va_arg(*arg, long long));
}

int my_vn_putnbr(va_list *arg, flag_modifiers_t modification_flag)
{
    long long new_data = parse_my_int(arg, modification_flag);
    int new_data_size = get_nb_size(new_data, 10);
    int potential_spaces = 0;

    prepare_print_int(&modification_flag, new_data_size, &potential_spaces,
            new_data);
    my_put_nbr(new_data);
    prints_the_following_spaces(potential_spaces);
    if (modification_flag.precision - new_data_size > 0)
        return (potential_spaces + new_data_size +
                modification_flag.already_printed);
    else
        return (potential_spaces + new_data_size +
                modification_flag.already_printed);
}
