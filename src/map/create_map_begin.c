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

// sfVector2i get_size(char *file, map_t *maps)
// {
//     sfVector2i size = {0, 0};

//     for (int i = 0; file[i] != '\n'; ++i)
//         ++size.y;
//     for (int i = 0; file[i] != '\0'; ++i)
//         if (file[i] == '\n')
//             ++size.x;
//     ++size.x;
//     return (size);
// }

// void open_map(map_t *maps, char *filepath)
// {
//     struct stat stat_buff;
//     int s = stat(filepath, &stat_buff);
//     char *buff = malloc(sizeof(char) * stat_buff.st_size);
//     int fd = open(filepath, O_RDONLY);
//     int r = read(fd, buff, stat_buff.st_size);
//     int **res;

//     buff[stat_buff.st_size - 1] = '\0';
//     maps->size = get_size(buff, maps);
//     res = malloc_int_array(maps);
//     for (int i = 0, ind = 0, j = 0; buff[ind] != '\0' && i < maps->size.x;) {
//         if (buff[ind] == '\n') {
//             ++i;
//             j = 0;
//             ++ind;
//         } else
//             res[i][j++] = buff[ind++] - 48;
//     }
//     maps->map_3d = res;
//     close(fd);
// }
