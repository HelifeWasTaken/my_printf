/*
** EPITECH PROJECT, 2020
** my_vn_putoctal
** File description:
** put_in_hex
*/

#include <stdarg.h>
#include <my_printf.h>
#include <my_math.h>
#include <my_str.h>

static unsigned long long parse_my_oct(va_list *arg,
        flag_modifiers_t flag_modficater)
{
    char *temp = flag_modficater.last_flag;

    if (my_strncmp(temp, "o", 1) == 0)
        return (va_arg(*arg, unsigned int));
    if (my_strncmp(temp, "lo", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "llo", 3) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "qo", 2) == 0)
        return (va_arg(*arg, unsigned long long));
    if (my_strncmp(temp, "hho", 3) == 0)
        return ((char)va_arg(*arg, unsigned int));
    return ((short int)va_arg(*arg, unsigned int));
}

int my_vn_putoctal(va_list *arg, flag_modifiers_t modification_flag)
{
    unsigned long long new_data = parse_my_oct(arg, modification_flag);
    int size_new_data = get_nb_size_unsigned(new_data, 8);
    int potential_following_spaces = 0;

    prepare_print_oct(&modification_flag, size_new_data,
            &potential_following_spaces);
    my_putnbr_base_unsigned(new_data, 8, 1);
    prints_the_following_spaces(potential_following_spaces);
    return (size_new_data + modification_flag.already_printed +
            potential_following_spaces);
}
