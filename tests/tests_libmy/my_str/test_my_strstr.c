/*
** EPITECH PROJECT, 2020
** test_my_strstr
** File description:
** test_libmy
*/

#include <my_criterion.h>

Test(my_strstr, find_an_occurence, cr_stdout)
{
   char *str = "Hello";

   str = my_strstr(my_strdup(str), "lo");
   my_printf("%s\n", str);
   cr_assert_stdout_eq_str("lo\n");
}

Test(my_strstr, empty_str, cr_stdout)
{
   char *str = "";

   str = my_strstr(my_strdup(str), "lo");
   my_printf("%s\n", str);
   cr_assert_stdout_eq_str("\n");
}

Test(my_strstr, empty_occurence, cr_stdout)
{
   char *str = "tes";

   str = my_strstr(my_strdup(str), "");
   my_printf("%s", str);
   cr_assert_stdout_eq_str("tes");
}
