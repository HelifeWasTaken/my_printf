# my_printf

## Deprecated

This printf is old was not optimised enough a better one (and documented) can be found on : `https://github.com/Heliferepo/LibErty`

## Unix System Programming

The goal of this project was to recreate printf in accordance to the C99 standard in two weeks

The project went well as you can see :

<center>
<img src="https://raw.githubusercontent.com/Heliferepo/my_printf/main/Capture.PNG?token=AO6YYCLWTAOUB25D2NBCTPC72ZFE2"> 
</center>

Unfortunately some percentages were lost because of a little mistake on specials formats...

The mistake has been resolved on this branch if you want to see the original one go to the "main" one

I decided to rewrite completely my_print and to rename it lprintf..

I wasn't satisfied with myy old printf because of a WAY too long array of function pointers that was a pain to see

I was considering `lld` and `d` as independant flag

But now the structure does contain only : `c d f s p x X o` flags and the `ll l h hh z Z t q j` are parsed independently

> Float are not implemented in the new version but might be implemented soon enough

A little look at the old structure :

```c
static const my_printf_flags_t array_flags[75] = {
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
    { "lls", &my_vn_putstr },
    { "llo", &my_vn_putoctal },
    { "llu", &my_vn_putnbr_unsigned },
    { "llx", &my_vn_puthex_lower },
    { "llX", &my_vn_puthex_upper },
    { "qd", &my_vn_putnbr }
```
And the parser was not so readable : 
```c
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
```

And so on for 75 flags...

Now the code structure is much more comprehensible and readable : 
```c
#include <lodeus/stdio.h>
#include <stdarg.h>
#include <lodeus/lvprintf/flag_modif.h>
#include <lodeus/lvprintf/lvdprint_local.h>

static const lvdprintf_flag_t lvdprintf_flag[10] = {
    {'c', &lvdprintf_local_char},
    {'s', &lvdprintf_local_str},
    {'d', &lvdprintf_local_int},
    {'i', &lvdprintf_local_int},
    {'f', &lvdprintf_local_float},
    {'u', &lvdprintf_local_uint},
    {'o', &lvdprintf_local_oct},
    {'x', &lvdprintf_local_hexmin},
    {'X', &lvdprintf_local_hexmax},
    {'p', &lvdprintf_local_pointer},
};

size_t parser_lvdprintf(int fd, char const **format, va_list *ap)
{
    fl_modif_t modif = get_lprintf_flag_character(format);

    for (size_t i = 0; i < 10; i++) {
        if (*(*format + modif.offset) == lvdprintf_flag[i].flag) {
            *format += modif.offset + 1;
            return ((*lvdprintf_flag[i].ptrf)(fd, ap, modif));
        }
    }
    *format += modif.offset;
    return (-1);
}

// // // // // // // // OTHER FILE // // // // // // // //

#include <lodeus/lvprintf/flag_modif.h>
#include <lodeus/string.h>

void lprintf_lenght_modifiers(fl_modif_t *modif, char const **format)
{
    char know_flag[9][2] = {"hh", "h", "ll", "l", "q", "j", "z", "Z", "t"};
    unsigned char len_flags[9] = {2, 1, 2, 1, 1, 1, 1, 1, 1};
    unsigned char state_flag[9] = {LPRINTF_MOD_CHAR, LPRINTF_MOD_SHORT,
        LPRINTF_MOD_LONG_LONG, LPRINTF_MOD_LONG, LPRINTF_MOD_LONG_LONG,
        LPRINTF_MOD_INT_MAX, LPRINTF_MOD_SIZE_T, LPRINTF_MOD_SIZE_T,
        LPRINTF_MOD_PTRDIFF};

    for (unsigned char i = 0; i < 8; i++) {
        if (!lstrncmp(know_flag[i], (*format) + modif->offset, len_flags[i])) {
            modif->lenmodifier = state_flag[i];
            modif->offset += len_flags[i];
            return;
        }
    }
    modif->lenmodifier = LPRINTF_MOD_NONE;
}
```

As you can see the parsing is much more readble and the type casting was much more easy : 
```c
long long parse_type(va_list *ap, struct flag_modifiers *modif)
{
    switch (modif->lenmodifier) {
        case LPRINTF_MOD_CHAR: return ((char)va_arg(*ap, int));
        case LPRINTF_MOD_SHORT: return ((short int)va_arg(*ap, int));
        case LPRINTF_MOD_LONG: return ((long)va_arg(*ap, long));
        case LPRINTF_MOD_LONG_LONG: return ((long long)va_arg(*ap, long long));
        case LPRINTF_MOD_INT_MAX: return ((intmax_t)va_arg(*ap, intmax_t));
        case LPRINTF_MOD_SIZE_T: return ((size_t)va_arg(*ap, size_t));
        case LPRINTF_MOD_PTRDIFF: return ((ptrdiff_t)va_arg(*ap, ptrdiff_t));
        default: return ((int)va_arg(*ap, int));
    }
}

// and more ...
```

What can be noticed that is my printf is directly an implentation of dprintf..

In fact is was really easy if you prepare at first you whole library to that so my_printf is basically just an alias to : 
````c
vdprintf(1, format, args); // called lvdprintf(); in my library

// If you go in my files you will see that I'm starting to prepare 
// also a sprintf and asprintf that might come in the next few weeks
