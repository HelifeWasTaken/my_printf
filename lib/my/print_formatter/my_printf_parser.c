/*
** EPITECH PROJECT, 2020
** my_printf_parser
** File description:
** parse
*/

#include <my_printf.h>
#include <stdlib.h>
#include <my_str.h>
#include <stdbool.h>
#include <my_str.h>
#include <my_stdio.h>
#include <my_math.h>

/*
**
**    This is simply a global structure containing every flags
**    that I need to procces my parsing
**
**    The structure looks like this :
**
**    typedef struct my_printf_struct {
**        char *flag;
**        int (*flag_function)(va_list , flag_modificater_t );
**    } my_printf_flags;
**
**    And the function looks like that now :
**
**    A second structure containing the flag modfification state is sended
**    into the pointer function as you can see and it permits to
**    transform the string given as you want
**
*/

static const my_printf_flags_t array_flags[71] = {
    { "d", &my_vn_putnbr },
    { "i", &my_vn_putnbr },
    { "c", &my_vn_putchar },
    { "s", &my_vn_putstr },
    { "x", &my_vn_puthex_lower },
    { "X", &my_vn_puthex_upper },
    { "b", &my_vn_putbin },
    { "o", &my_vn_putoctal },
    { "n", 0 },
    { "S", &my_vn_showstr_oct },
    { "p", &my_vn_putpointer },
    { "u", &my_vn_putnbr_unsigned },
    { "f", &my_vn_putfloat },
    { "F", &my_vn_putfloat },
    { "lc", &my_vn_putchar },
    { "ls", &my_vn_putstr },
    { "ld", &my_vn_putnbr },
    { "li", &my_vn_putnbr },
    { "lo", &my_vn_putoctal },
    { "lu", &my_vn_putnbr_unsigned },
    { "lx", &my_vn_puthex_lower },
    { "lX", &my_vn_puthex_upper },
    { "lld", &my_vn_putnbr },
    { "lli", &my_vn_putnbr },
    { "llo", &my_vn_putoctal },
    { "llu", &my_vn_putnbr_unsigned },
    { "llx", &my_vn_puthex_lower },
    { "llX", &my_vn_puthex_upper },
    { "qd", &my_vn_putnbr },
    { "qi", &my_vn_putnbr },
    { "qo", &my_vn_putoctal },
    { "qu", &my_vn_putnbr_unsigned },
    { "qx", &my_vn_puthex_lower },
    { "qX", &my_vn_puthex_upper },
    { "hhd", &my_vn_putnbr },
    { "hhi", &my_vn_putnbr },
    { "hho", &my_vn_putoctal },
    { "hhu", &my_vn_putnbr_unsigned },
    { "hhx", &my_vn_puthex_lower },
    { "hhX", &my_vn_puthex_upper },
    { "hd", &my_vn_putnbr },
    { "hi", &my_vn_putnbr },
    { "ho", &my_vn_putoctal },
    { "hu", &my_vn_putnbr_unsigned },
    { "hx", &my_vn_puthex_lower },
    { "hX", &my_vn_puthex_upper },
    { "Zd", &my_vn_putnbr },
    { "Zi", &my_vn_putnbr },
    { "Zo", &my_vn_putoctal },
    { "Zu", &my_vn_putnbr_unsigned },
    { "Zx", &my_vn_puthex_lower },
    { "ZX", &my_vn_puthex_upper },
    { "zd", &my_vn_putnbr },
    { "zi", &my_vn_putnbr },
    { "zo", &my_vn_putoctal },
    { "zu", &my_vn_putnbr_unsigned },
    { "zx", &my_vn_puthex_lower },
    { "zX", &my_vn_puthex_upper },
    { "jd", &my_vn_putnbr },
    { "ji", &my_vn_putnbr },
    { "jo", &my_vn_putoctal },
    { "ju", &my_vn_putnbr_unsigned },
    { "jx", &my_vn_puthex_lower },
    { "jX", &my_vn_puthex_upper },
    { "td", &my_vn_putnbr },
    { "ti", &my_vn_putnbr },
    { "to", &my_vn_putoctal },
    { "tu", &my_vn_putnbr_unsigned },
    { "tx", &my_vn_puthex_lower },
    { "tX", &my_vn_puthex_upper },
    { NULL, 0 },
};

/*
**
** This functions is called by my_printf()
** when the function find a % that is not followed by an another %
**
** It permits me to use the array of pointers in a structure
** defined in "my_printf.h" that should be in the current folder
** and the array filled in global at the top
**
** It is a simple for loop that checks for each character individually
** and points to the adequate function
**
** For example %d and %i will point to my_vn_putnbr
**
** Now the flag function is no more getting a void * but
** the complete va_list linked list
** It simply send the list to avoir UB and cast with va_arg directly
**
** For the %n flag management it is processed as an exception
**
** everything else is handled into each own function
**
*/

int my_printf_parser(char const **str, va_list *arg, int count_char)
{
    flag_modifiers_t flag_modificater;
    int (*flag_func)(va_list *arg, flag_modifiers_t flag_modificater) = NULL;

    get_modification_flag(str, &flag_modificater);
    for (int i = 0; array_flags[i].flag != NULL; i++) {
        if (my_strncmp(array_flags[i].flag, *str + flag_modificater.offset,
                    my_strlen(array_flags[i].flag)) == 0) {
            flag_modificater.last_flag = array_flags[i].flag;
            flag_func = array_flags[i].flag_function;
            break;
        }
    }
    if (flag_func != NULL) {
        (*str) +=
            my_strlen(flag_modificater.last_flag) + flag_modificater.offset;
        return (flag_func(arg, flag_modificater));
    } else
        return (my_printf_exception(str, arg, flag_modificater, count_char));
}
