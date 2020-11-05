/*
** EPITECH PROJECT, 2020
** get_nb_size
** File description:
** test
*/

#include <my_criterion.h>

Test(get_nb_size, simple_number)
{
    cr_assert_eq(get_nb_size(3456789, 10), 7);
}

Test(get_nb_size, simmple_negative_number)
{
    cr_assert_eq(get_nb_size(-3456789, 10), 8);
}

Test(get_nb_size, simple_number_unsigned)
{
    cr_assert_eq(get_nb_size_unsigned(3456789, 10), 7);
}
