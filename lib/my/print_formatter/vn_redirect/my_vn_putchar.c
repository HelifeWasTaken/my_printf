/*
** EPITECH PROJECT, 2020
** my_vn_putchar
** File description:
** putchar_for_printf
*/

#include <stdarg.h>
#include <my_printf.h>
#include <unistd.h>
#include <wchar.h>
#include <my_str.h>

int my_vn_putchar(va_list *arg, flag_modifiers_t modification_flag)
{
    wint_t new_data = va_arg(*arg, wint_t);
    int potential_following_spaces = 0;

    prepare_print_str(&modification_flag, 1, &potential_following_spaces);
    if (my_strncmp(modification_flag.last_flag, "c", 1) == 0) {
        write(1, (unsigned char *)&new_data, 1);
        prints_the_following_spaces(potential_following_spaces);
    } else {
        write(1, &new_data, 1);
        prints_the_following_spaces(potential_following_spaces);
    }
    return (1 + potential_following_spaces + modification_flag.already_printed);
}
