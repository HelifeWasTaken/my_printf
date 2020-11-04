/*
** EPITECH PROJECT, 2020
** my_printf_header_file
** File description:
** structure_and_functions
*/

#ifndef __MY_PRINTF__H__
#define __MY_PRINTF__H__
int my_printf(char const *str, ...);
int my_vn_putchar(void *data);
int my_vn_putstr(void *data);
int my_vn_putnbr(void *data);
int my_vn_putstr(void *data);
int my_vn_puthex_lower(void *data);
int my_vn_puthex_higher(void *data);
int my_vn_putbin(void *data);
int my_vn_putoctal(void *data);
int my_vn_putpointer(void *data);
int my_vn_showstr_oct(void *data);
int my_vn_putnbr_unsigned(void *data);
int my_vn_get_send_to_stdio(void *data, int count_char);
int my_vn_putfloat_precision_6(void *data);

typedef struct my_printf_struct {
    char *flag;
    int (*flag_function)(void *data);
} my_printf_flags;
#endif
