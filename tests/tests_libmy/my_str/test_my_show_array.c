/*
** EPITECH PROJECT, 2020
** test_my_show_array
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_show_word_array, test_simple_string, cr_stdout)
{
    char **str = my_calloc(sizeof(char *), 2);

    str[0] = my_strdup("Hello");
    str[1] = my_strdup("Bello");
    my_show_word_array(str);
}
Test(my_show_word_array, empty, cr_stdout)
{
    char **str = my_calloc(sizeof(char *), 2);

    my_show_word_array(str);
}
