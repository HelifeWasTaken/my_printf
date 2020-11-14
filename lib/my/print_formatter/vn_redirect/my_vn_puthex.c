/*
** EPITECH PROJECT, 2020
** my_vn_puthex_higher
** File description:
** put_in_hex
*/

#include <stdbool.h>
#include <stdarg.h>
#include <my_math.h>
#include <my_stdio.h>
#include <my_printf.h>
#include <my_str.h>
#include <stdint.h>

static unsigned long long parse_my_hex_lower(va_list *arg,
        flag_modifiers_t flag_modficater)
{
    char *temp = flag_modficater.last_flag;

    if (my_strncmp(temp, "x", 1) == 0)
        return (va_arg(*arg, unsigned int));
    if (my_strncmp(temp, "lx", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "llx", 3) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "qx", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "hhx", 3) == 0)
        return ((char)va_arg(*arg, unsigned int));
    if (my_strncmp(temp, "jx", 2) == 0)
        return ((uintmax_t)va_arg(*arg, uintmax_t));
    if (my_strncmp(temp, "zx", 2) == 0 || my_strncmp(temp, "Zx", 2) == 0 ||
        my_strncmp(temp, "tx", 2) == 0 || my_strncmp(temp, "tx", 2) == 0)
        return ((size_t)va_arg(*arg, size_t));
    return ((short int)va_arg(*arg, unsigned int));
}

static unsigned long long parse_my_hex_upper(va_list *arg,
        flag_modifiers_t flag_modficater)
{
   char *temp = flag_modficater.last_flag;

    if (my_strncmp(temp, "X", 1) == 0)
        return (va_arg(*arg, unsigned int));
    if (my_strncmp(temp, "lX", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "llX", 3) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "qX", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "hhX", 3) == 0)
        return ((char)va_arg(*arg, unsigned int));
    if (my_strncmp(temp, "jX", 2) == 0)
        return ((uintmax_t)va_arg(*arg, uintmax_t));
    if (my_strncmp(temp, "zX", 2) == 0 || my_strncmp(temp, "ZX", 2) == 0 ||
        my_strncmp(temp, "tX", 2) == 0 || my_strncmp(temp, "tX", 2) == 0)
        return ((size_t)va_arg(*arg, size_t));
    return ((short int)va_arg(*arg, unsigned int));
}

int my_vn_puthex_lower(va_list *arg, flag_modifiers_t flag_modificater)
{
    unsigned long long new_data = parse_my_hex_lower(arg, flag_modificater);
    int new_data_size = get_nb_size_unsigned(new_data, 16);
    int potential_following_spaces = 0;

    prepare_print_hex(&flag_modificater, &potential_following_spaces,
            new_data_size, 0);
    prints_the_following_spaces(potential_following_spaces);
    my_putnbr_base_unsigned(new_data, 16, 0);
    if (flag_modificater.precision > 8) {
        if (flag_modificater.space_padding > flag_modificater.precision)
            return (flag_modificater.space_padding);
        return (flag_modificater.precision);
    }
    return (new_data_size + potential_following_spaces +
            flag_modificater.already_printed);
}

int my_vn_puthex_upper(va_list *arg, flag_modifiers_t flag_modificater)
{
    unsigned long long new_data = parse_my_hex_upper(arg, flag_modificater);
    int new_data_size = get_nb_size_unsigned(new_data, 16);
    int potential_following_spaces = 0;

    prepare_print_hex(&flag_modificater, &potential_following_spaces,
            new_data_size, 1);
    prints_the_following_spaces(potential_following_spaces);
    my_putnbr_base_unsigned(new_data, 16, 1);
    if (flag_modificater.precision > 8) {
        if (flag_modificater.space_padding > flag_modificater.precision)
            return (flag_modificater.space_padding);
        return (flag_modificater.precision);
    }
    return (new_data_size + potential_following_spaces +
            flag_modificater.already_printed);
}
