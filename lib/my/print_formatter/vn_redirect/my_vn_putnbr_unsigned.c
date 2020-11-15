/*
** EPITECH PROJECT, 2020
** my_vn_putbin
** File description:
** put_in_bin
*/

#include <stdarg.h>
#include <my_printf.h>
#include <my_stdio.h>
#include <my_math.h>
#include <my_str.h>
#include <stdint.h>

static long long parse_my_unsigned_int(va_list *arg,
        flag_modifiers_t modification_flag)
{
    char *temp = modification_flag.last_flag;

    if (my_strncmp(temp, "u", 1) == 0)
        return (va_arg(*arg, unsigned int));
    if (my_strncmp(temp, "lu", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "llu", 3) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "qu", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "hhu", 3) == 0)
        return ((char)va_arg(*arg, unsigned int));
    if (my_strncmp(temp, "ju", 2) == 0)
        return ((uintmax_t)va_arg(*arg, uintmax_t));
    if (my_strncmp(temp, "zu", 2) == 0 || my_strncmp(temp, "Zu", 2) == 0 ||
            my_strncmp(temp, "tu", 2) == 0 || my_strncmp(temp, "tu", 2) == 0)
        return ((size_t)va_arg(*arg, size_t));
    return ((short int)va_arg(*arg, unsigned int));
}

int my_vn_putnbr_unsigned(va_list *arg, flag_modifiers_t modification_flag)
{
    unsigned long long new_data = parse_my_unsigned_int(arg, modification_flag);
    int new_data_size = get_nb_size_unsigned(new_data, 10);
    int potential_spaces = 0;

    prepare_print_unsigned_int(&modification_flag, new_data_size,
            &potential_spaces);
    my_put_nbr_unsigned(new_data);
    prints_the_following_spaces(potential_spaces);
    if (modification_flag.precision - new_data_size > 0)
        return (potential_spaces + new_data_size +
                modification_flag.already_printed);
    else
        return (potential_spaces + new_data_size +
                modification_flag.already_printed);
}
