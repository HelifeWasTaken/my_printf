/*
** EPITECH PROJECT, 2020
** prints_following_spaces
** File description:
** prints_the_following
*/

#include <unistd.h>

void prints_the_following_spaces(int potential_following_space)
{
    for (int i = 0; i < potential_following_space; i++)
        write(1, " ", 1);
}
