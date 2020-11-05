/*
** EPITECH PROJECT, 2020
** test_my_bzero
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_bzero, fill_a_str_of_zero, cr_stdout)
{
    char *str = malloc(sizeof(char) * 3);

    str[0] = 'a';
    str[1] = 'a';
    str[2] = 'a';
    my_printf("%d%d%d\n", str[0], str[1], str[2]);
    my_bzero(str, 3);
    my_printf("%d%d%d\n", str[0], str[1], str[2]);
    cr_assert_stdout_eq_str("979797\n000\n");
}

Test(my_memset, fill_of_backslashn, cr_stdout)
{
    char *str = malloc(sizeof(char) * 3);

    my_memset(str, 'j', 2);
    str[2] = '\0';
    my_printf("%s", str);
    cr_assert_stdout_eq_str("jj");
}

Test(my_calloc, print_the_value_of_the_first_char, cr_stdout)
{
    char *str = my_calloc(sizeof(char), 3);

    my_printf("%d\n", *str);
    cr_assert_stdout_eq_str("0\n");
}
