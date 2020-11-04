/*
** EPITECH PROJECT, 2020
** get_send_to_stdio
** File description:
** transferring_value_for_percentage_n_flag
*/

int my_vn_get_send_to_stdio(void *data, int count_char)
{
    int *new_data = (int *)data;

    *new_data = count_char;
    return (0);
}
