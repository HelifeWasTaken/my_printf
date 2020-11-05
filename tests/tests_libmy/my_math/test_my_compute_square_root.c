/*
** EPITECH PROJECT, 2020
** test_my_compute_square_root
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_compute_square_root, send_nb_inferior_than_zero)
{
    cr_assert_eq(my_compute_square_root(-1), 0);
}

Test(my_compute_square_root, send_nb_equal_to_zero)
{
    cr_assert_eq(my_compute_square_root(0), 0);
}

Test(my_compute_square_root, send_nb_equal_to_one)
{
    cr_assert_eq(my_compute_square_root(1), 1);
}

Test(my_compute_square_root, send_sqrt_441)
{
    cr_assert_eq(my_compute_square_root(441), 21);
}

Test(my_compute_square_root, send_not_a_whole_number)
{
    cr_assert_eq(my_compute_square_root(456), 0);
}
