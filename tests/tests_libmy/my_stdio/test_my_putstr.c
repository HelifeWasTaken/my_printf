/*
** EPITECH PROJECT, 2020
** test_my_putstr
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_putstr, put_a_string, cr_stdout)
{
    my_putstr("Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(my_putstr_err, put_a_string, cr_stderr)
{
    my_putstr_err("Hello");
    cr_assert_stderr_eq_str("Hello");
}
