/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** create_maps.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void create_3d_map(map_t *maps, sfVector2i size)
{
    int **res = malloc(sizeof(int *) * (size.x + 1));

    for (int i = 0; i < size.x; ++i) {
        res[i] = malloc(sizeof(int) * size.y + 1);
        for (int j = 0; j < size.y; ++j) {
            if (i == 0 || j == 0 || i == size.x - 1 || j == size.y - 1)
                res[i][j] = -100;
            else
                res[i][j] = my_rand(MIN, MAX);
        }
    }
    maps->map_3d = res;
}

int **malloc_int_array(map_t *maps)
{
    int **res = malloc(sizeof(int *) * (maps->size.x + 1));
    int i_alloc = 0;

    for (; i_alloc < maps->size.x; ++i_alloc)
        res[i_alloc] = malloc(sizeof(int) * maps->size.y);
    res[i_alloc] = NULL;
    return (res);
}
