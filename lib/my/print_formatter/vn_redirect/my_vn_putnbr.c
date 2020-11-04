/*
** EPITECH PROJECT, 2020
** my_vn_putnbr
** File description:
** putnbr_redirection
*/

void my_put_nbr(int nb);

int get_nb_size(long nb, int base);

int my_vn_putnbr(void *data)
{
    int new_data = (long)data;

    my_put_nbr(new_data);
    return (get_nb_size(new_data, 10));
}
