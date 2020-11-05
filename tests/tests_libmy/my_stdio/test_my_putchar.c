/*
** EPITECH PROJECT, 2020
** test_my_putchar
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_putchar, put_a_char, cr_stdout)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}
