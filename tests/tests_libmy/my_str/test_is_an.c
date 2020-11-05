/*
** EPITECH PROJECT, 2020
** test_is_an
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(is_an, send_number)
{
    cr_assert_eq(is_char_alphanum('5'), true);
    cr_assert_eq(is_num_letter('5'), true);
    cr_assert_eq(is_an_alpha_letter('5'), false);
    cr_assert_eq(is_lowercase_letter('5'), false);
    cr_assert_eq(is_capital_letter('5'), false);
    cr_assert_eq(is_printable('5'), true);
}

Test(is_an, send_alpha)
{
    cr_assert_eq(is_char_alphanum('a'), true);
    cr_assert_eq(is_num_letter('a'), false);
    cr_assert_eq(is_an_alpha_letter('a'), true);
    cr_assert_eq(is_lowercase_letter('a'), true);
    cr_assert_eq(is_capital_letter('A'), true);
    cr_assert_eq(is_printable('a'), true);
}

Test(is_an, not_printable)
{
    cr_assert_eq(is_char_alphanum('\n'), false);
    cr_assert_eq(is_num_letter('\n'), false);
    cr_assert_eq(is_an_alpha_letter('\n'), false);
    cr_assert_eq(is_lowercase_letter('\n'), false);
    cr_assert_eq(is_capital_letter('\n'), false);
    cr_assert_eq(is_printable('\n'), false);
    cr_assert_eq(is_printable(127), false);
}
