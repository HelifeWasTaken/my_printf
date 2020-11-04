/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_in_a_format_given
*/

#include <stdarg.h>
#include <my_stdlib.h>
#include <my_printf.h>
#include <stdlib.h>
#include <my_stdio.h>
#include <my_str.h>
#include <stdio.h>

/*
**
**    This simply a global structure containing every flags
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
**    As you can see this version seems more portable than the casting to float *
**
**    For the vn_stuff name I kept it as va_arg is still a linked list
**    of void * and I do the cast in the other functions
**
*/

static const my_printf_flags array_flags[33] = {
    { "s", &my_vn_putstr },
    { "d", &my_vn_putnbr },
    { "i", &my_vn_putnbr },
    { "c", &my_vn_putchar },
    { "x", &my_vn_puthex_lower },
    { "X", &my_vn_puthex_higher },
    { "b", &my_vn_putbin },
    { "o", &my_vn_putoctal },
    { "S", &my_vn_showstr_oct },
    { "u", &my_vn_putnbr_unsigned },
    { "p", &my_vn_putpointer },
    { "f", &my_vn_putfloat_precision_6 },
    { "F", &my_vn_putfloat_precision_6 },
    { "n", 0 },
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
    { "hhd", &my_vn_cast_int_to_signed_char },
    { "hhi", &my_vn_cast_int_to_signed_char },
    { "hho", &my_vn_cast_oct_to_signed_char },
    { "hhu", &my_vn_cast_unsigned_to_signed_char },

    { "hhx", &my_vn_cast_hex_low_to_signed_char },
    { "hhX", &my_vn_cast_hex_high_to_signed_char },
    { NULL, 0 },
};

/*
**
**  This function is invoked by my_printf and is here in case my_printf
**  did not found any flag that could be used to format output
**  it basically check if there is still an str after removing traling spaces
**  If there is an alpha or numeric character
**  And else ...
**
**  This function was made in case of weird formatting such as :
**
**  #include <my_stdio.h>
**
**  int main(void)
**  {
**      char *str = "Hello world";
**      my_printf("%    s\n", str);
**      return (0);
**  }
**
**  Here it should print Hello World but you can have other type of stuff
**  like when the flag is unknown
**
*/

static int process_exception(char const **str, int found_space)
{
    if (!(**str))
        return (0);
    if (!found_space && is_char_alphanum(**str)) {
        my_putchar('%');
        my_putchar(**str++);
        return (2);
    } else {
        for (int i = 0; i < found_space; i++)
            my_putchar(' ');
        my_putchar(**str++);
        return (found_space + 1);
    }
}

/*
**
**  This function was made as said to remove trailing spaces
**
**  It is made to facilitate the parsing of stuff like :
**
**  int main(void)
**  {
**      char *str = "Hello world";
**      my_printf("%    s\n", str);
**      return (0);
**  }
**
**  And keep the numbers of spaces in case you need to do some padding
**
*/

static int remove_trailing_spaces(char const **str)
{
    int count = 0;

    if (**str != ' ')
        return (0);
    while (**str && **str != ' ') {
        count++;
        (*str)++;
    }
    return (count);
}

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

static int my_printf_parser(char const **str, va_list *arg, int count_char)
{
    char *temp_flag = NULL;
    char *last_flag = NULL;
    int (*flag_func)(va_list *arg);
    int found_space = remove_trailing_spaces(str);

    for (int i = 0; array_flags[i].flag != NULL; i++) {
        temp_flag = array_flags[i].flag;
        if (my_strncmp(temp_flag, *str, my_strlen(temp_flag)) == 0) {
            last_flag = temp_flag;
            flag_func = array_flags[i].flag_function;
            break;
        }
    }
    if (last_flag != NULL) {
        if (*last_flag == 'n')
            return (my_vn_get_send_to_stdio(arg, count_char));
        (*str) += my_strlen(last_flag);
        return (flag_func(arg));
    }
    else
        return (process_exception(str, found_space));
}

/*
**
** This the first function invoked like the original one
**
** It simply goes into the whole string and parse
** it in a very primitive algorithm
**
** It looks at the first one if it's a percentage and the second is not
** send the argument to the my_printf parser
**
** Edit :
** It does no send the argument anymore directly but send the list of arguments
**
**
** If both *str and str[1] are a percentage it prints a percentage
** then process
**
** Otherwise it simply print with my_putchar
**
*/

int my_printf(char const *str, ...)
{
    int count = 0;
    va_list arg;
    va_start(arg, str);

    if (!str)
        return (0);
    while (*str) {
        if (*str == '%' && str[1] != '%') {
            str++;
            count += my_printf_parser(&str, &arg, count);
        } else if (*str == '%' && str[1] == '%') {
            my_putstr("%");
            str += 2;
            count += 2;
        } else {
            my_putchar(*str++);
            count++;
        }
    }
    va_end(arg);
    return (count);
}
