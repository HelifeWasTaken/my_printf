/*
** EPITECH PROJECT, 2020
** test_my_compute_power_rec
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_compute_power_rec, send_power_inferior_than_zero)
{
    cr_assert_eq(my_compute_power_rec(15, -1), 0);
}

Test(my_compute_power_rec, send_power_equal_to_zero)
{
    cr_assert_eq(my_compute_power_rec(15, 0), 1);
}

Test(my_compute_power_rec, send_power_superior_than_zero)
{
    cr_assert_eq(my_compute_power_rec(15, 2), 225);
}
