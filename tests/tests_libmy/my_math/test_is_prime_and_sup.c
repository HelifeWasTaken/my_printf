/*
** EPITECH PROJECT, 2020
** test_is_prime_and_find_prime_sup
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_is_prime, send_zero)
{
    cr_assert_eq(my_is_prime(0), false);
    cr_assert_eq(my_find_prime_sup(0), 2);
}

Test(my_is_prime, send_two)
{
    cr_assert_eq(my_is_prime(2), true);
    cr_assert_eq(my_find_prime_sup(2), 2);
}

Test(my_is_prime, send_twelve)
{
    cr_assert_eq(my_is_prime(12), false);
    cr_assert_eq(my_find_prime_sup(12), 13);
}
