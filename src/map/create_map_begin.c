/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** create_maps.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

// void create_3d_map(map_t *maps, sfVector2i size)
// {
//     int **res = malloc(sizeof(int *) * (size.x + 1));
//     int i = 0;
//     int j = 0;

//     for (; i < size.x; ++i) {
//         res[i] = malloc(sizeof(int) * size.y);
//         for (; j < size.y; ++j) {
//             res[i][j] = 0;
//         }
//     }
//     res[i] = NULL;
//     maps->map_3d = res;
// }

void create_3d_map(map_t *maps, sfVector2i size)
{
    int **res = malloc(sizeof(int *) * size.x);

    for (int i = 0; i < size.x; ++i) {
        res[i] = malloc(sizeof(int) * size.y);
        for (int j = 0; j < size.y; ++j) {
            res[i][j] = my_rand(MIN, MAX);
        }
    }
    maps->map_3d = res;
}

sfVector2i get_size(char *file, map_t *maps)
{
    sfVector2i size = {0, 0};

    for (int i = 0; file[i] != '\n'; ++i)
        ++size.y;
    for (int i = 0; file[i] != '\0'; ++i)
        if (file[i] == '\n')
            ++size.x;
    ++size.x;
    return (size);
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

void open_map(map_t *maps, char *filepath)
{
    struct stat stat_buff;
    int s = stat(filepath, &stat_buff);
    char *buff = malloc(sizeof(char) * stat_buff.st_size);
    int fd = open(filepath, O_RDONLY);
    int r = read(fd, buff, stat_buff.st_size);
    int **res;

    buff[stat_buff.st_size - 1] = '\0';
    maps->size = get_size(buff, maps);
    res = malloc_int_array(maps);
    for (int i = 0, index = 0, j = 0; buff[index] != '\0' && i < maps->size.x;) {
        if (buff[index] == '\n') {
            ++i;
            j = 0;
            ++index;
        } else
            res[i][j++] = buff[index++] - 48;
    }
    maps->map_3d = res;
    close(fd);
}
