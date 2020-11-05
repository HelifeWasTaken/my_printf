/*
** EPITECH PROJECT, 2020
** my_putpointer
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_put_pointer, test_with_printf, cr_stdout)
{
    char *str = "Hello";
    my_printf("%p", str);
}
