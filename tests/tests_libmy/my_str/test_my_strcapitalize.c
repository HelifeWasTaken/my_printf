/*
** EPITECH PROJECT, 2020
** test_my_str_capitalize
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_strcapitalize, simple_string, cr_stdout)
{
    char *str = my_strdup("Hello,world5howareyou");

    str = my_strcapitalize(str);
    my_printf("%s", str);
    cr_assert_stdout_eq_str("Hello,World5howareyou");
}
