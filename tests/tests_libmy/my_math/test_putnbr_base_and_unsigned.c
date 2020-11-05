/*
** EPITECH PROJECT, 2020
** test_my_putnbr_base_and_putnbr_base_unsigned
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_putnbr_base, send_fifty, cr_stdout)
{
    my_putnbr_base(50, 10, 1);
    my_putnbr_base_unsigned(50, 10, 1);
    cr_assert_stdout_eq_str("5050");
}

Test(my_putnbr_base, send_zero, cr_stdout)
{
    my_putnbr_base(0, 10, 0);
    my_putnbr_base_unsigned(0, 10, 0);
    cr_assert_stdout_eq_str("00");
}

Test(my_putnbr_base, send_negative_no_unsigned, cr_stdout)
{
    my_putnbr_base(-789, 16, 1);
    cr_assert_stdout_eq_str("-315");
}

Test(my_putnbr_base, giving_invalid_base, cr_stderr)
{
    my_putnbr_base(15, 1, 0);
    my_putnbr_base_unsigned(15, 1, 0);

    my_putnbr_base(15, 40, 0);
    my_putnbr_base_unsigned(15, 40, 0);
}
