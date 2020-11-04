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
*/

static const my_printf_flags array_flags[14] = {
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
    //  { "e", &my_vn_putexp_lower },
    //  { "E", &my_vn_putexp_higher },
    { "f", &my_vn_putfloat_precision_6 },
    { "n", 0 },
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
*/

static int my_printf_parser(char const **str, void *data, int count_char)
{
    char *temp_flag = NULL;
    char *last_flag = NULL;
    int (*flag_func)(void *data);
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
            return (my_vn_get_send_to_stdio(data, count_char));
        (*str) += my_strlen(last_flag);
        return (flag_func(data));
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
** send it to the my_printf parser
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

    while (*str) {
        if (*str == '%' && str[1] != '%') {
            str++;
            count += my_printf_parser(&str, va_arg(arg, void *), count);
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
