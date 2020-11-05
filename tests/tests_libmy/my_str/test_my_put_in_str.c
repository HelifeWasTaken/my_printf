/*
** EPITECH PROJECT, 2020
** my_put_in_str
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_put_in_str, simple_put, cr_stdout)
{
    char *str = "Hello";
    char *new_str = my_strdup(str);

    new_str = my_put_in_str(new_str, 2, 'a');
    my_printf("%s\n", new_str);
    cr_assert_stdout_eq_str("Heallo\n");
}
