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
#include <stdint.h>
#include <sys/types.h>

static long long parse_my_int(va_list *arg, flag_modifiers_t modification_flag)
{
    char *temp = modification_flag.last_flag;

    if (my_strncmp(temp, "d", 1) == 0 || my_strncmp(temp, "i", 1) == 0)
        return ((int)va_arg(*arg, int));
    if (my_strncmp(temp, "ld", 2) == 0 || my_strncmp(temp, "li", 2) == 0)
        return ((long)va_arg(*arg, long));
    if (my_strncmp(temp, "lld", 3) == 0 || my_strncmp(temp, "lli", 3) == 0)
        return ((long long)va_arg(*arg, long long));
    if (my_strncmp(temp, "hd", 2) == 0 || my_strncmp(temp, "hi", 2) == 0)
        return ((short int)va_arg(*arg, int));
    if (my_strncmp(temp, "hhd", 3) == 0 || my_strncmp(temp, "hhi", 3) == 0)
        return ((char)va_arg(*arg, int));
    if (my_strncmp(temp, "zd", 2) == 0 || my_strncmp(temp, "zi", 2) == 0 ||
        my_strncmp(temp, "Zd", 2) == 0 || my_strncmp(temp, "Zi", 2) == 0)
        return ((ssize_t)va_arg(*arg, ssize_t));
    if (my_strncmp(temp, "jd", 2) == 0 || my_strncmp(temp, "ji", 2) == 0)
        return ((intmax_t)va_arg(*arg, intmax_t));
    if (my_strncmp(temp, "td", 2) == 0 || my_strncmp(temp, "ti", 2) == 0)
        return ((ptrdiff_t)va_arg(*arg, ptrdiff_t));
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
