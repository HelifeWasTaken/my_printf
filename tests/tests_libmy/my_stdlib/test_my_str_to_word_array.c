/*
** EPITECH PROJECT, 2020
** test_my_str_to_word_array
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_str_to_word_array, sending_basic_phrase)
{
    char *str = "Hello|World howare, you";
    char **result = NULL;

    result = my_str_to_word_array(str);
    my_printf("%s\n", result[1]);
}

Test(my_str_to_word_array, sending_empty_phrase)
{
    char *str = "";
    char **result = NULL;

    result = my_str_to_word_array(str);
    my_printf("%s\n", result[1]);
}
