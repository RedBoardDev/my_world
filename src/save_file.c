/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** save_file.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void save_file(char *filepath, map_t *maps)
{
    FILE *fp;
    size_t blocSize;
    int separator = -1000;

    fp = fopen (filepath, "w");
    fwrite(&maps->size.x, sizeof(int), 1, fp);
    fwrite(&maps->size.y, sizeof(int), 1, fp);
    for (int i = 0; i < maps->size.x; ++i) {
        fwrite(maps->map_3d[i], sizeof(int), maps->size.y, fp);
        fwrite(&separator, sizeof(int), 1, fp);
    }
    fclose(fp);
}
