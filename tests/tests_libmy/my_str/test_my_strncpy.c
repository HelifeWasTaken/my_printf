/*
** EPITECH PROJECT, 2020
** test_my_strncpy
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_strncpy, simple_string_copy, cr_stdout)
{
    char *str = "Hello";
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));

    str2 = my_strncpy(my_strdup(str2), my_strdup(str), my_strlen(str));
    my_printf("%s", str2);
    str2 = my_strncpy(my_strdup(str2), my_strdup("abcdef"), 3);
    my_printf("%s", str2);
    cr_assert_stdout_eq_str("Helloabclo");
}

Test(my_strncpy, not_enough_numbers)
{
    char *str = "Hello";
    char *str2 = malloc(sizeof(char) * 23);
    str2 = my_strncpy(my_strdup(str2), my_strdup(str), 20);
    cr_assert_eq(str2[16] == 0, true);
}
