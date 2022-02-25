/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** modify_maps.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

sfVector3f rotation(map_t *maps, sfVector3f point_3d)
{
    float backup_x = point_3d.x;
    float backup_y = point_3d.y;
    float backup_z = point_3d.z;

    point_3d.x = point_3d.x * cos(RADIAN(maps->angle.x)) - point_3d.y * sin(RADIAN(maps->angle.x));
    point_3d.y = point_3d.y * cos(RADIAN(maps->angle.x)) + backup_x * sin(RADIAN(maps->angle.x));

    backup_x = point_3d.x;
    backup_y = point_3d.y;
    backup_z = point_3d.z;

    point_3d.x = point_3d.x * cos(RADIAN(maps->angle.y)) - point_3d.z * sin(RADIAN(maps->angle.y));
    point_3d.z = point_3d.z * cos(RADIAN(maps->angle.y)) + backup_x * sin(RADIAN(maps->angle.y));

    backup_x = point_3d.x;
    backup_y = point_3d.y;
    backup_z = point_3d.z;

    point_3d.y = point_3d.y * cos(RADIAN(maps->angle.y)) - point_3d.z * sin(RADIAN(maps->angle.y));
    point_3d.z = point_3d.z * cos(RADIAN(maps->angle.y)) + backup_y * sin(RADIAN(maps->angle.y));

// formule drunk
    // point_3d.x = point_3d.x * cos(RADIAN(maps->angle.y)) - point_3d.z * sin(RADIAN(maps->angle.y));
    // point_3d.y = point_3d.y * cos(RADIAN(maps->angle.y)) - point_3d.z * sin(RADIAN(maps->angle.y));
    // point_3d.z = point_3d.z * cos(RADIAN(maps->angle.y)) + (backup_x * backup_y / 2) * sin(RADIAN(maps->angle.y));
    return (point_3d);
}

point_t project_iso_point(int x, int y, int z, map_t *maps)
{
    point_t point;
    sfVector3f point_3d = {x - (maps->size.x / 2), y - (maps->size.x / 2), z};
    float angle_x = RADIAN(45);
    float angle_y = RADIAN(25);

    point_3d = rotation(maps, point_3d);
    point.iso.x = cos(angle_x) * point_3d.x - cos(angle_x) * point_3d.y;
    point.iso.y = sin(angle_y) * point_3d.y + sin(angle_y) * point_3d.x - point_3d.z;
    point.coords.x = x;
    point.coords.y = y;
    point.coords.z = z;
    return (point);
}

void create_2d_map(map_t *maps, sfVector2i size)
{
    for (int i = 0; i < size.x; ++i) {
        for (int j = 0; j < size.y; ++j) {
            maps->map_2d[i][j] = project_iso_point(i, j, maps->map_3d[i][j], maps);
            maps->map_2d[i][j].iso.x *= maps->zoom;
            maps->map_2d[i][j].iso.y *= maps->zoom;
            maps->map_2d[i][j].iso.x += maps->pos.x;
            maps->map_2d[i][j].iso.y += maps->pos.y;
        }
    }
}
