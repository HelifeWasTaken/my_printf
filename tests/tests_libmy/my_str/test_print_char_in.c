/*
** EPITECH PROJECT, 2020
** print_char_in
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(print_char_in, simple_tests, cr_stdout)
{
    print_char_in_hex('c');
    print_char_in_oct('c');
    print_char_in_hex('a');
    print_char_in_oct('a');

    my_printf("%x %X %S", 'c', 'c', "Hello\nworld");
    cr_assert_stdout_eq_str("\\63\\143\\61\\14163 63 Hello\\012world");
}

Test(print_char_in, simple_tests_v2, cr_stdout)
{
    print_char_in_oct(3);
    print_char_in_oct(0x3F);
    print_char_in_oct(0x7F);
    print_char_in_oct(0x3C);
    cr_assert_stdout_eq_str("\\003\\077\\177\\074");
}
