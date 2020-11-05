/*
** EPITECH PROJECT, 2020
** test_concat_params
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(concat_params, simple_double_str, cr_stdout)
{
    char **str = malloc(sizeof(char *) * 2);

    str[0] = my_strdup("Hello");
    str[1] = my_strdup("World");
    my_printf("%s", concat_params(2, str));
    cr_assert_stdout_eq_str("Hello\nWorld");
}
