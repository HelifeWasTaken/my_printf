#include <my_stdio.h>
#include <stdio.h>

int main(void)
{
    char *a = "hello\n\t";
    int b = 5678;
    char *c;
    int d = 0;
    int e = 245657575757;

    /*
    printf("printf %%p : %p\n", (void *)&a);
    my_printf("my %%p : %p\n", (void *)&a);
    printf("printf %%s : %s\n", a);
    my_printf("my %%s : %s\n", a);
    printf("printf %%d : %d\n", a);
    my_printf("my %%d : %d\n", a);
    printf("printf %%i : %i\n", a);
    my_printf("my %%i : %i\n", a);
    printf("printf %%x : %x\n", a);
    my_printf("my %%x : %x\n", a);
    printf("printf %%X : %X\n", a);
    my_printf("my %%X : %X\n", a);
    printf("printf %%b : %b\n", a);
    printf("a %%s but weird : % s\n", a);
    my_printf("b %%s but weird : % s\n", a);
    printf("a %%b but weird : %      r\n", a);
    my_printf("b %%b but weird : %      r\n", a);
    printf("a %%s but weird : %      \n", a);
    my_printf("b %%s but weird : %      a a\n", a);
    printf("%s empty printf\n", c);
    printf("%s empty my\n", c);
    */

    /*
    my_printf("d before == %d\n", d);
    my_printf("for testing %n\n", &d);
    my_printf("d after == %d\n", d);
    */

    //my_putstr(a);
    my_printf("%S", a);

    //return (my_printf("aled%s%d", a, b));
    return (0);
}

/*
printf %p : 0x7ffdaccfa878
my %p : 0x7ffdaccfa878

printf %s : hello
my %s : hello

printf %d : 4211032
my %d : 4211032

printf %i : 4211032
my %i : 4211032

printf %x : 404158
my %x : 404158

printf %X : 404158
my %X : 404158

printf %b : %b
printf %s but weird : hello

my %s but weird :  s
printf %s but weird : %b

my %s but weird :       b
printf %s but weird : %

my %s but weird :       a a
*/
