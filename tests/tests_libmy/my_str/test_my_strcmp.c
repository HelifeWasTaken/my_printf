/*
** EPITECH PROJECT, 2020
** test_my_strcmp
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_strcmp, test_strcmp)
{
    char *str = "hello";
    int a = my_strcmp(str, "hello") == 0;
    int b = my_strncmp(str, "hello", 3) == 0;

    cr_assert_eq(a, true);
    cr_assert_eq(b, true);
}

Test(my_strcmp, test_strcmp_2)
{
    char *str = "hello";
    int a = my_strcmp(str, "ello") == 1;
    int b = my_strncmp(str, "ello", 3) == ('h' - 'e');
    int c = my_strcmp(str, "zello") == -1;
    int d = my_strcmp("", "zello") == -1;
    int e = my_strcmp(str, "") == 1;

    cr_assert_eq(a, true);
    cr_assert_eq(b, true);
    cr_assert_eq(c, true);
    cr_assert_eq(d, true);
    cr_assert_eq(e, true);
}
