/*
** EPITECH PROJECT, 2020
** my_printf_header_file
** File description:
** structure_and_functions
*/

#ifndef __MY_PRINTF__H__
#define __MY_PRINTF__H__

#include <stdarg.h>
#include <stdbool.h>

typedef struct my_printf_flag_modification_struct {
    char *last_flag;
    bool hashtag;
    bool plus;
    bool minus;
    bool zero;
    bool found_precision;
    int count_spaces;
    int space_padding;
    int precision;
    int offset;
    int already_printed;
} flag_modifiers_t;

typedef struct my_printf_function_redirect {
    char *flag;
    int (*flag_function)(va_list *arg, flag_modifiers_t modification_flag);
} my_printf_flags_t;

int my_printf(char const *str, ...);
int my_printf_parser(char const **str, va_list *arg, int count_char);

int my_printf_exception(char const **str, va_list *arg,
                        flag_modifiers_t flag_modificater, int count_char);
void get_modification_flag(char const **str,
                           flag_modifiers_t *flag_modificater);

void prints_the_following_spaces(int potential_following_space);
void prepare_print_str(flag_modifiers_t *flag_modificater, int to_be_printed,
                       int *potential_following_space);
void prepare_print_int(flag_modifiers_t *modification_flag, int to_be_printed,
                       int *potential_following_space, long long nb);
void prepare_print_hex(flag_modifiers_t *modification_flag,
                       int *potential_following_space, int to_be_printed,
                       bool is_upper);

int my_vn_get_send_to_stdio(va_list *arg, int count_char);
int my_vn_putchar(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putstr(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putnbr(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putstr(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_puthex_lower(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_puthex_higher(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putbin(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putoctal(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putpointer(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_showstr_oct(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putnbr_unsigned(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putfloat_precision_6(va_list *arg,
                               flag_modifiers_t modification_flag);
int my_vn_putnbr_long(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putoctal_long(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putnbr_unsigned_long(va_list *arg,
                               flag_modifiers_t modification_flag);
int my_vn_puthex_lower_long(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_puthex_higher_long(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putnbr_long_long(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putoctal_long_long(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putnbr_unsigned_long_long(va_list *arg,
                                    flag_modifiers_t modification_flag);
int my_vn_puthex_lower_long_long(va_list *arg,
                                 flag_modifiers_t modification_flag);
int my_vn_puthex_higher_long_long(va_list *arg,
                                  flag_modifiers_t modification_flag);
int my_vn_cast_int_to_unsigned_char(va_list *arg,
                                    flag_modifiers_t modification_flag);
int my_vn_cast_oct_to_unsigned_char(va_list *arg,
                                    flag_modifiers_t modification_flag);
int my_vn_cast_unsigned_to_unsigned_char(va_list *arg,
                                         flag_modifiers_t modification_flag);
int my_vn_cast_hex_low_to_unsigned_char(va_list *arg,
                                        flag_modifiers_t modification_flag);
int my_vn_cast_hex_high_to_unsigned_char(va_list *arg,
                                         flag_modifiers_t modification_flag);
int my_vn_cast_int_to_unsigned_short_int(va_list *arg,
                                         flag_modifiers_t modification_flag);
int my_vn_cast_oct_to_unsigned_short_int(va_list *arg,
                                         flag_modifiers_t modification_flag);
int my_vn_cast_unsigned_to_unsigned_short_int(
        va_list *arg, flag_modifiers_t modification_flag);
int my_vn_cast_hex_low_to_unsigned_short_int(
        va_list *arg, flag_modifiers_t modification_flag);
int my_vn_cast_hex_high_to_unsigned_short_int(
        va_list *arg, flag_modifiers_t modification_flag);
#endif
