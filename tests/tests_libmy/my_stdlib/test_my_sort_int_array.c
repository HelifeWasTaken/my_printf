/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_sort_int_array, sort_array_of_int, cr_stdout)
{
    int array[10] = { 5, 3, 789, 445654, 12, 74, 9, 12, 9, 234567 };
    my_sort_int_array(array, 10);
    for (int i = 0; i < 10; i++)
        my_printf("%i", array[i]);
    cr_assert_stdout_eq_str("3599121274789234567445654");
}
