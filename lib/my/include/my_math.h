/*
** EPITECH PROJECT, 2020
** my_math_libmy
** File description:
** libmy_for_the_epitech_curriculum
*/

#ifndef _MY_MATH_H_
#define _MY_MATH_H_
#include <stdbool.h>
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
bool my_is_prime(int nb);
void my_put_nbr(long long nb);
void my_put_nbr_unsigned(long long nb);
void my_putnbr_base(long long nb, char const *base);
void my_putnbr_base_unsigned(unsigned long long nb, char const *base);
int get_nb_size(long long nb, int base);
int get_nb_size_unsigned(unsigned long long nb, int base)
#endif
