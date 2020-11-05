/*
** EPITECH PROJECT, 2020
** test_my_printf
** File description:
** test_libmy
*/

#include <my_criterion.h>

/*
** Everything below each output has been already test remove cr_stdout
** if you want to see the output
*/

Test(test_printf_scilence, check_that_it_does_not_segfault, cr_stdout)
{
    char *str = "Hello";
    int a = 0;

    my_printf("%s\n", "Hello");
    printf("%s\n", "Hello");

    my_printf("%d\n", 50);
    printf("%d\n", 50);

    my_printf("%i\n", 50);
    printf("%i\n", 50);

    my_printf("%c\n", 50);
    printf("%c\n", 50);

    my_printf("%x\n", 50);
    printf("%x\n", 50);

    my_printf("%X\n", 50);
    printf("%X\n", 50);

    my_printf("%b\n", 50);
    //printf("%b\n", 50);

    my_printf("%o\n", 50);
    printf("%o\n", 50);

    my_printf("showstr_epi : %S\n", "Hello");
    //printf("%S\n", "Hello");

    my_printf("%u\n", 50);
    printf("%u\n", 50);

    my_printf("%p\n", str);
    printf("%p\n", str);

    my_printf("%f\n", 50.313);
    printf("%f\n", 50.313);

    my_printf("%F\n", 50.4567);
    printf("%F\n", 50.4567);

    printf("tempforn%n\n", &a);
    printf("n value is : %d\n", a);
    a = 0;
    my_printf("tempforn%n\n", &a);
    printf("n value is : %d\n", a);

    printf("%ld\n", 999999999999);
    my_printf("%ld\n", 999999999999);
}
