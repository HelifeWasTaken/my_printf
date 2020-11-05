/*
** EPITECH PROJECT, 2020
** my_printf_header_file
** File description:
** structure_and_functions
*/

#ifndef __MY_PRINTF__H__
#define __MY_PRINTF__H__
#include <stdarg.h>
int my_printf(char const *str, ...);
int my_vn_putchar(va_list *arg);
int my_vn_putstr(va_list *argdata);
int my_vn_putnbr(va_list *arg);
int my_vn_putstr(va_list *arg);
int my_vn_puthex_lower(va_list *arg);
int my_vn_puthex_higher(va_list *arg);
int my_vn_putbin(va_list *arg);
int my_vn_putoctal(va_list *arg);
int my_vn_putpointer(va_list *arg);
int my_vn_showstr_oct(va_list *arg);
int my_vn_putnbr_unsigned(va_list *arg);
int my_vn_get_send_to_stdio(va_list *arg, int count_char);
int my_vn_putfloat_precision_6(va_list *arg);
int my_vn_putnbr_long(va_list *arg);
int my_vn_putoctal_long(va_list *arg);
int my_vn_putnbr_unsigned_long(va_list *arg);
int my_vn_puthex_lower_long(va_list *arg);
int my_vn_puthex_higher_long(va_list *arg);
int my_vn_putnbr_long_long(va_list *arg);
int my_vn_putoctal_long_long(va_list *arg);
int my_vn_putnbr_unsigned_long_long(va_list *arg);
int my_vn_puthex_lower_long_long(va_list *arg);
int my_vn_puthex_higher_long_long(va_list *arg);
int my_vn_cast_int_to_unsigned_char(va_list *arg);
int my_vn_cast_oct_to_unsigned_char(va_list *arg);
int my_vn_cast_unsigned_to_unsigned_char(va_list *arg);
int my_vn_cast_hex_low_to_unsigned_char(va_list *arg);
int my_vn_cast_hex_high_to_unsigned_char(va_list *arg);
int my_vn_cast_int_to_short_int(va_list *arg);
int my_vn_cast_oct_to_short_int(va_list *arg);
int my_vn_cast_unsigned_to_short_int(va_list *arg);
int my_vn_cast_hex_low_to_short_int(va_list *arg);
int my_vn_cast_hex_high_to_short_int(va_list *arg);

typedef struct my_printf_struct {
    char *flag;
    int (*flag_function)(va_list *arg);
} my_printf_flags_t;
#endif
