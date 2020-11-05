/*
** EPITECH PROJECT, 2020
** test_my_putfloat_and_putfloat_unsigned
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_putfloat, send_fifty, cr_stdout)
{
    my_putfloat(50, 6);
    cr_assert_stdout_eq_str("50.000000");
}

Test(my_putfloat, send_zero, cr_stdout)
{
    my_putfloat(0, 4);
    cr_assert_stdout_eq_str("0.0000");
}

Test(my_putfloat, send_negative_no_unsigned, cr_stdout)
{
    my_putfloat(-789.235, 5);
    cr_assert_stdout_eq_str("-789.23500");
}

Test(my_putfloat, giving_invalid_base, cr_stderr)
{
    my_putfloat(15, 0);
    my_putfloat(15, 40);
}
