/*
** EPITECH PROJECT, 2020
** pointer_swap
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(pointer_swap, my_pointer_swap, cr_stdout)
{
    char *str = "Hello";
    char *str2 = "Hello2";

    my_pointer_swap((void **)&str, (void **)&str);
    my_printf("%s%s", str, str2);
    cr_assert_stdout_eq_str("HelloHello2");
}

Test(pointer_swap, my_swap, cr_stdout)
{
    int a = 5;
    int b = 6;

    my_swap(&a, &b);
    my_printf("%d%d", a, b);
    cr_assert_stdout_eq_str("65");
}
