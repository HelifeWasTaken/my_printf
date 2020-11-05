/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_revstr, test_empty)
{
    cr_assert_str_eq(my_revstr(my_strdup("")), "");
}

Test(my_revstr, test_one_letter)
{
    cr_assert_str_eq(my_revstr(my_strdup("a")), "a");
}
