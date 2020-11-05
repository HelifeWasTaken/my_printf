/*
** EPITECH PROJECT, 2020
** test_my_put_nbr_and_put_nbr_unsigned
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_put_nbr, send_fifty, cr_stdout)
{
    my_put_nbr(50);
    my_put_nbr_unsigned(50);
    cr_assert_stdout_eq_str("5050");
}

Test(my_put_nbr, send_zero, cr_stdout)
{
    my_put_nbr(0);
    my_put_nbr_unsigned(0);
    cr_assert_stdout_eq_str("00");
}

Test(my_put_nbr, send_negative_no_unsigned, cr_stdout)
{
    my_put_nbr(-789);
    cr_assert_stdout_eq_str("-789");
}
