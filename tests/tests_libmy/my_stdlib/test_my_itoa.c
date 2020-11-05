/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_itoa, send_negative_value, cr_stdout)
{
    char *str = my_calloc(sizeof(char), 50);

    my_itoa(-789, str, "0123456789");
    my_printf("%s", str);
    cr_assert_stdout_eq_str("-789");
}
