/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** int_array_utils.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

int *int_dup(int *tabl, int size)
{
    int *new_tabl = malloc(sizeof(int) * size);
    int i = 0;

    for (; i < size; ++i)
        new_tabl[i] = tabl[i];
    return (new_tabl);
}

int **int_array_dup(int **arr, sfVector2i size)
{
    int **new_arr = malloc(sizeof(int *) * (size.x + 1));
    int i = 0;

    for (; i < size.x; ++i)
        new_arr[i] = int_dup(arr[i], size.y);
    new_arr[i] = NULL;
    return (new_arr);
}

// point_t **point_t_array_dup(point_t **arr, sfVector2i size)
// {
//     point_t **new_arr = malloc(sizeof(point_t *) * size.x);
//     int i = 0;

//     for (; i < size.x; ++i)
//         new_arr[i] = int_dup(arr[i], size.y);
//     new_arr[i] = NULL;
//     return (new_arr);
// }

void print_int_array(int **arr, sfVector2i size)
{
    for (int i = 0; i < size.x; ++i) {
        for (int j = 0; j < size.y; ++j) {
            my_put_nbr(arr[i][j]);
        }
        my_putchar('\n');
    }
}

void free_int_array(int **arr, int size)
{
    for (int i = 0; i < size; ++i)
        free(arr[i]);
    free(arr);
}
