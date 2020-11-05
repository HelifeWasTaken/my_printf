/*
** EPITECH PROJECT, 2020
** test_my_showstr
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_showstr, test_simple_string, cr_stdout)
{
    char *str = "Hello";
    my_showstr(str);
    cr_assert_stdout_eq_str("Hello");
}

Test(my_showstr, test_with_backslahn, cr_stdout)
{
    char *str = "Hel\nlo";
    my_showstr(str);
    cr_assert_stdout_eq_str("Hel\\0alo");
}
