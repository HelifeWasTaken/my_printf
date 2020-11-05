/*
** EPITECH PROJECT, 2020
** test_my_getnbr
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_getnbr, multiple_plus_and_minus_end_up_on_a_minus)
{
    cr_assert_eq(my_getnbr("+++---+-+-+-+-+-+---+55678721"), -55678721);
}

Test(my_getnbr, multiple_plus_and_minus_end_up_on_a_plus)
{
    cr_assert_eq(my_getnbr("+++---+-+-+-+-+-+--+55678721"), 55678721);
}

Test(my_getnbr, zero)
{
    cr_assert_eq(my_getnbr("0"), 0);
}

Test(my_getnbr, int_min)
{
    cr_assert_eq(my_getnbr("-2147483648"), INT_MIN);
}

Test(my_getnbr, int_min_minus_one)
{
    cr_assert_eq(my_getnbr("-2147483649"), 0);
}

Test(my_getnbr, int_max)
{
    char *nb = my_calloc(sizeof(char), 50);

    my_itoa(INT_MAX, nb, "0123456789");
    cr_assert_eq(my_getnbr(nb), INT_MAX);
}

Test(my_getnbr, oveflow_positive)
{
    cr_assert_eq(my_getnbr("222222222222"), 0);
}

Test(my_getnbr, oveflow_negative)
{
    cr_assert_eq(my_getnbr("-222222222222"), 0);
}

Test(my_getnbr, notannumber)
{
    cr_assert_eq(my_getnbr("A-222222222222"), 0);
}

Test(my_getnbr, letter_in_the_middle)
{
    cr_assert_eq(my_getnbr("-22222222222a2"), 0);
}

Test(my_getnbr, space_in_the_middle)
{
    cr_assert_eq(my_getnbr("-22222222222 2"), 0);
}

Test(my_getnbr, letter_after_sign)
{
    cr_assert_eq(my_getnbr("-a22222222222 2"), 0);
}

Test(my_getnbr, empty_str)
{
    cr_assert_eq(my_getnbr(""), 0);
}
