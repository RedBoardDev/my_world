/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** load_file.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

sfVector2i get_size_int_array(int *file)
{
    return ((sfVector2i){file[0], file[1]});
}

void load_file(char *filepath, map_t *maps)
{
    struct stat stat_buff;
    int s = stat(filepath, &stat_buff);
    int *buff = malloc(sizeof(int) * stat_buff.st_size);
    int fd = open(filepath, O_RDONLY);
    int r = read(fd, buff, stat_buff.st_size);
    int **res;

    maps->size = get_size_int_array(buff);
    res = malloc_int_array(maps);
    for (int i = 0, ind = 2, j = 0; ind < stat_buff.st_size && i < maps->size.x;) {
        if (buff[ind] == -1000) {
            ++i;
            ++ind;
            j = 0;
        } else
            res[i][j++] = buff[ind++];
    }
    maps->map_3d = res;
    close(fd);
}
