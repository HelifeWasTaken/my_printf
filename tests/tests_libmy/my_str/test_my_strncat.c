/*
** EPITECH PROJECT, 2020
** test_my_strncat
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_strncat, error_case_v1)
{
    my_strncat(my_strdup("hello"), my_strdup(""), 3);
}

Test(my_strncat, error_case_v2)
{
    my_strncat(my_strdup("abc"), my_strdup("str"), 1);
}

Test(my_strncat, error_case_v3)
{
    my_strncat(my_strdup(""), my_strdup("str"), 3);
}
