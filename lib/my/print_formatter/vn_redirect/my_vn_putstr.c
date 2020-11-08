/*
** EPITECH PROJECT, 2020
** my_vn_putstr
** File description:
** putstr
*/

#include <my_str.h>
#include <my_printf.h>
#include <stdarg.h>
#include <unistd.h>
#include <my_stdio.h>
#include <my_math.h>

int my_vn_putstr(va_list *arg, flag_modifiers_t modification_flag)
{
    char *new_data = va_arg(*arg, char *);
    int size_new_data = my_strlen(new_data);
    int potential_following_space = 0;

    prepare_print_str(&modification_flag, size_new_data,
            &potential_following_space);
    if (modification_flag.found_precision &&
            modification_flag.precision < size_new_data) {
        write(1, new_data, modification_flag.precision);
        prints_the_following_spaces(potential_following_space);
        return (modification_flag.precision + potential_following_space +
                modification_flag.already_printed);
    }
    write(1, new_data, size_new_data);
    prints_the_following_spaces(potential_following_space);
    return (size_new_data + potential_following_space +
            modification_flag.already_printed);
}
