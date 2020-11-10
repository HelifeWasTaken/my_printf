/*
** EPITECH PROJECT, 2020
** test_my_printf
** File description:
** test_libmy
*/

#include <wchar.h>
#include <stdlib.h>
#include <my_criterion.h>


/*
** Everything below each output has been already test remove cr_stdout
** if you want to see the output
*/

Test(test_printf_scilence, check_that_it_does_not_segfault, cr_stdout)
{
    char *strptr = "hello";

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

    my_printf("%p\n", strptr);
    printf("%p\n", strptr);

    my_printf("%f\n", 50.313);
    printf("%f\n", 50.313);

    my_printf("%F\n", 50.4567);
    printf("%F\n", 50.4567);

    printf("%ld\n", 999999999999);
    my_printf("%ld\n", 999999999999);

    my_printf("%lld\n", (unsigned long long)999999999999);
    printf("%lld\n", (unsigned long long)999999999999);

    my_printf("%llu\n", (unsigned long long)999999999999);
    printf("%llu\n", (unsigned long long)999999999999);

    my_printf("%llx\n", (unsigned long long)999999999999);
    printf("%llx\n", (unsigned long long)999999999999);

    my_printf("%llX\n", (unsigned long long)999999999999);
    printf("%llX\n", (unsigned long long)999999999999);

    printf("q output\n");

    my_printf("%qd\n", (unsigned long long)999999999999);
    printf("%lld\n", (unsigned long long)999999999999);

    my_printf("%qu\n", (unsigned long long)999999999999);
    printf("%llu\n", (unsigned long long)999999999999);

    my_printf("%qx\n",  (unsigned long long)999999999999);
    printf("%llx\n",  (unsigned long long)999999999999);

    my_printf("%qX\n",  (unsigned long long)999999999999);
    printf("%llX\n",  (unsigned long long)999999999999);

    my_printf("%hhd\n", 9999999);
    printf("%hhd\n",  9999999);

    my_printf("%hhi\n",  9999999);
    printf("%hhi\n",  9999999);

    my_printf("%hho\n",  9999999);
    printf("%hho\n",  9999999);

    my_printf("%hhu\n",  9999999);
    printf("%hhu\n",  9999999);

    my_printf("%hhx\n",  9999999);
    printf("%hhx\n",  9999999);

    my_printf("%hhX\n",  9999999);
    printf("%hhX\n",  9999999);

    my_printf("%hd\n", 9999999);
    printf("%hd\n",  9999999);

    my_printf("%hi\n",  9999999);
    printf("%hi\n",  9999999);

    my_printf("%ho\n",  9999999);
    printf("%ho\n",  9999999);

    my_putstr("hello\n");
    my_printf("%hu\n",  9999999);
    printf("%hu\n",  999999);
    my_putstr("hello\n");

    my_printf("%hx\n",  9999999);
    printf("%hx\n",  9999999);

    my_printf("%hX\n",  9999999);
    printf("%hX\n",  9999999);
    char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    int aled = 0;
    char *flag = "%s%d\n";
    my_printf(flag, str, my_strlen(str));
    printf(flag, str, strlen(str));
    my_printf("%s%n\n", str, &aled);
    my_printf("aled = %d\n", aled);
    my_printf("aled == %d\n", aled);
    my_putchar('\n');
    printf("result %d\n", printf("%s\n", str));
    char *str2 = "Hello";
    int i = 56;
    my_printf("%8.0d", i);          // "      56"
    my_putchar('\n');
    printf("%8.0d", i);             // "      56"


    my_printf("%-8.6d", i);         // "56      "
    my_putchar('\n');
    printf("%-8.6d", i);         // "56      "


    my_printf("%o", 56);
    printf("%-8.6d", i);         // "56      "
    my_putchar('\n');
    my_printf("%-8.6d", i);         // "56      "


    my_printf("%-8.12d", i);        // "000000000012"


    my_printf("%+-8.12lld", (long long int)i);       // +000000000056
    my_putchar('\n');


    my_printf("%lc\n", 'd');

    my_printf("%ls\n", L"hello");
    my_printf("%s", "aled");
    printf("%ls\n", L"hello");
    my_printf("%llx && %llX\n", 78, 78);
    my_printf("%llu", (long long unsigned)0x2345678945678);
    my_putchar('\n');
    printf("%llu", (long long unsigned)0x2345678945678);
    my_printf("%ls\n", "aledjppaidezmoisvp");
    my_printf("%s\n", "hello");
    my_printf("%b\n", 50);
    my_printf("%f\n", (float)1000);
    my_printf("%.2d\n", 456);
    my_printf("%.-0f", (float)199.34567);
    my_printf("% #10s\n", "Hello");
   // printf("% #10s\n", "Hello");
    my_printf("%-067.31d", 78);
    my_putchar('\n');
    printf("%s\n", "Hello");
    //printf("% #18s\n", "Hello");
    my_printf("% #18s\n", "Hello");
    my_printf("% #18.2s\n", "Hello");
    my_printf("% #18.2z\n", "Hello");
    my_printf("% #18.2s\n", "Hello");
//    printf("% 18.2z\n", "Hello");
//    printf("%18.2z", "Hello");
    my_printf("%#4.3c", 'a');
    my_printf("%-05d", 5);
    printf("%.d\n", 76789);


    my_printf("%o\n", 43);         // 53
    my_printf("%05o\n", 43);       // 00053
    my_printf("%.1o\n", 43);       // 53
    my_printf("%#-5.7o\n", 43);    // 0000053
    my_printf("%#.0o\n", 43);      // 053
    my_printf("%.0o\n", 43);       // 53
    my_printf("%.o\n", 43);        // 53
    printf("%#3.19X\n", 15); // 39 char
    my_printf("%#3.19X\n", 15);
    my_printf("%.d\n", 76789);
    my_putchar('\n');
    printf("%.3d", 76789);
    my_putchar('\n');
    my_printf("% -+05d", 5);
    my_printf("%s", "Hello");
    my_printf("%18.2z", "Hello");
    printf("%s\n", "Hello");
    my_printf("%#18.2z\n", "Hello");
    my_printf("%d\n", 50);
    my_printf("%c\n", 50);
    printf("%d\n", 50);

    printf("%i\n", 50);

    my_printf("%i\n", 50);
    printf("%c\n", 50);

    my_printf("%x\n", 50);
    printf("%x\n", 50);
    my_printf("%b\n", 50);
    //printf("%b\n", 50);


    my_printf("%X\n", 50);
    printf("%X\n", 50);


    my_printf("%o\n", 50);
    printf("%o\n", 50);

    my_printf("showstr_epi : %S\n", "He\nl lo\t");
    //printf("%S\n", "Hello");

    my_printf("%u\n", 50);
    printf("%u\n", 50);

    my_printf("%p\n", str2);
    printf("%p\n", str2);

    my_printf("%f\n", 50.313);
    printf("%f\n", 50.313);

    my_printf("%F\n", 50.4567);
    printf("%F\n", 50.4567);

    int ac = 0;
    printf("tempforn%n\n", &ac);
    printf("n value is : %d\n", ac);
    ac = 0;
    my_printf("tempforn%n\n", &ac);
    printf("n value is : %d\n", ac);

    my_printf("%ld\n", 999999999999);
    printf("%ld\n", 999999999999);

    my_printf("%lld\n", (long long int)999999999999);
    printf("%lld\n", (long long int)999999999999);

    my_printf("%llu\n", (long long unsigned)999999999999);
    printf("%llu\n", (long long unsigned)999999999999);

    my_printf("%llx\n", (long long unsigned)999999999);
    printf("%llx\n", (long long unsigned)999999999);

    my_printf("%llX\n", (long long unsigned)999999999);
    printf("%llX\n", (long long unsigned)999999999);

    printf("q output\n");

    my_printf("%qd\n", (long long int)999999999999);
    printf("%lld\n", (long long int)999999999999);

    my_printf("%qu\n", 999999999999);
    printf("%llu\n", (long long unsigned)999999999999);

    my_printf("%qx\n", (long long unsigned)999999999);
    printf("%llx\n", (long long unsigned)999999999);

    my_printf("%qX\n", (long long unsigned)999999999);
    printf("%llX\n", (long long unsigned)999999999);

    my_printf("%hhd\n", 678999);
    printf("%hhd\n", 678999);

    my_printf("%hhi\n", 678999);
    printf("%hhi\n", 678999);

    my_printf("%hho\n", 678999);
    printf("%hho\n", 678999);

    my_printf("%hhu\n", 678999);
    printf("%hhu\n", 678999);

    my_printf("%hhx\n", 678999);
    printf("%hhx\n", 678999);

    my_printf("%hhX\n", 678999);
    printf("%hhX\n", 678999);

    my_printf("%hd\n", 678999);
    printf("%hd\n", 678999);

    my_printf("%hi\n", 678999);
    printf("%hi\n", 678999);

    my_printf("%ho\n", 678999);
    printf("%ho\n", 678999);

    my_printf("%hu\n", 678999);
    printf("%hu\n", 678999);

    my_printf("%hx\n", 678999);
    my_printf("%hx\n", 678999);

    printf("%hX\n", 678999);
    my_printf("%hX\n", 678999);

    //printf("\% ");
    //my_printf("\% ");
    my_printf("% %");
    my_putchar('\n');
    printf("%%");
    my_printf("%-03hho", 23456789);
    my_putchar('\n');
    printf("%035hho", 23456789);
    my_printf("%%");
    my_printf("%035hho", 23456789);
    my_putchar(10);
    //printf("% %");
    my_printf("%d\n", my_printf("%"));
    my_printf("%u", 456789);
    my_printf("%lu", 456789);
    my_printf("%llu", 456789);
    my_printf("%.32llu", 456789);
    my_printf("%56.32llu", 456789);
    my_printf("%56.llu", 456789);
    my_printf("%-56.llu", 456789);
    my_printf("%-#56.llu", 456789);
    my_printf("%-#056.llu", 456789);
    my_printf("%-056.llu", 456789);
    my_printf("%+056.llu", 456789);
}
