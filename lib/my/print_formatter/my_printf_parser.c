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

/*
**    This is simply a global structure containing every flags
**    that I need to procces my parsing
**
**    structure looks like this :
**    typedef struct my_printf_struct {
**        char *flag;
**        int (*flag_function)(void *data);
**    } my_printf_flags;
**
**    my_vn_something is a reference to an old hack
**    of redirecting everything with void * in structures
**    and casting it in the adequates functions
**
**    for example :
**    int my_vn_putstr(void *data)
**    {
**        my_putstr(data);
**        return (my_strlen(data));  To return how many characters have
**    }                              been printed
**
**    As the write buffer takes a (void *) as argument
**    and it is not a problem to do a my_strlen on void * as while
**    it is being passed as argument it is
**    casted automatically to a char * and so can be dereferenced
**
**    But :
**
**    int my_vn_putnbr(void *data)
**    {
**        long new_data = (long)data;   Need to be casted !
**
**        my_putnbr(new_data);
**        return (get_nb_size(new_data, 10)) calculate
**    }                                      how many characters
**                                           have been printed
**
**    Originally I wanted to cast it in int but I learned a lot
**    about casting and from compiler errors mostly
**    Knowing that I could not do arithmetic with a void *
**    I just casted to an integer that had the size of a void *
**
**    // Deprecated
**
**    But now nothing is passed as void * anymore as my vn_function get the
**    va_list argument directly and are casted with va_arg
**    which seems much more safe
**    Because of casting from void * to float had some weird bit level hacking
**
**    That looked like :
**
**    int my_vn_putfloat(void *data)
**    {
**       void *data = 5678.878;
**       float *new_data = *(float *)&data;
**       evil floating point bit level hacking
**
**       my_putfloat(*new_data);
**       return (get_nb_size((double)*new_data, 10) + 7);
**    }
**
**    And I was scared of undefined behaviour with this kind that was tho legit
**    And still worked perfectly for the little time that I used it
**
**    so now the structure looks like this :
**    typedef struct my_printf_struct {
**        char *flag;
**        int (*flag_function)(va_list *arg);
**    } my_printf_flags;
**
**    And the function looks like that now :
**
**    int my_vn_putfloat(va_list *arg)
**    {
**        double new_data = va_arg(*arg, double);
**
**        my_putfloat((float)new_data, 6);
**        return (7 + get_nb_size(new_data));
**    }
**
**    As you can see this version seems more portable
**    than the casting to float * with weird bit level hacking
**
**    For the vn_stuff name I kept it as va_arg is still a linked list
**    of void * and I do the cast in the other functions
**
*/

static const my_printf_flags_t array_flags[12] = {
    { "d", &my_vn_putnbr },
    { "i", &my_vn_putnbr },
    { "c", &my_vn_putchar },
    { "s", &my_vn_putstr },
    { "x", &my_vn_puthex_lower },
    { "X", &my_vn_puthex_higher },
    { "b", &my_vn_putbin },
    { "o", &my_vn_putoctal },
    { "n", 0 },
    { "S", &my_vn_showstr_oct },
    { "p", &my_vn_putpointer },
    /*
    { "u", &my_vn_putnbr_unsigned },
    { "f", &my_vn_putfloat },
    { "F", &my_vn_putfloat },
    { "ld", &my_vn_putnbr_long },
    { "li", &my_vn_putnbr_long },
    { "lo", &my_vn_putoctal_long },
    { "lu", &my_vn_putnbr_unsigned_long },
    { "lx", &my_vn_puthex_lower_long },
    { "lX", &my_vn_puthex_higher_long },
    { "lld", &my_vn_putnbr_long_long },
    { "lli", &my_vn_putnbr_long_long },
    { "llo", &my_vn_putoctal_long_long },
    { "llu", &my_vn_putnbr_unsigned_long_long },
    { "llx", &my_vn_puthex_lower_long_long },
    { "llX", &my_vn_puthex_higher_long_long },
    { "qd", &my_vn_putnbr_long_long },
    { "qi", &my_vn_putnbr_long_long },
    { "qo", &my_vn_putoctal_long_long },
    { "qu", &my_vn_putnbr_unsigned_long_long },
    { "qx", &my_vn_puthex_lower_long_long },
    { "qX", &my_vn_puthex_higher_long_long },
    { "hhd", &my_vn_cast_int_to_unsigned_char },
    { "hhi", &my_vn_cast_int_to_unsigned_char },
    { "hho", &my_vn_cast_oct_to_unsigned_char },
    { "hhu", &my_vn_cast_unsigned_to_unsigned_char },
    { "hhx", &my_vn_cast_hex_low_to_unsigned_char },
    { "hhX", &my_vn_cast_hex_high_to_unsigned_char },
    { "hd", &my_vn_cast_int_to_unsigned_short_int },
    { "hi", &my_vn_cast_int_to_unsigned_short_int },
    { "ho", &my_vn_cast_oct_to_unsigned_short_int },
    { "hu", &my_vn_cast_unsigned_to_unsigned_short_int },
    { "hx", &my_vn_cast_hex_low_to_unsigned_short_int },
    { "hX", &my_vn_cast_hex_high_to_unsigned_short_int },
    */
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
** As I could not pass the counter of character into the function
** because the function pointer could handle only one argument that was
** void *data I did a check in a "brute force may kind of" and
** just sended to a function manually
**
** Otherwise if the flag was not recognizable it is simply going into
** (*flag_func)(void *data); and doing the display with the given argument
**
** // Deprecated
**
** Now the flag function is no more getting a void * but
** the complete va_list linked list
** It simply send the list to avoir UB and cast with va_arg directly
**
*/

int my_printf_parser(char const **str, va_list *arg, int count_char)
{
    flag_modifiers_t flag_modificater;
    int (*flag_func)(va_list * arg, flag_modifiers_t flag_modificater) = NULL;

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