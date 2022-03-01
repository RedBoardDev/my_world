/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** move_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

bool check_incidence_left(map_t *maps, events_t *all_events, int i, int j)
{
    bool check = false;
    if (all_events->mouse.left) {
        if (i > 0 && maps->map_3d[i - 1][j] < maps->map_3d[i][j] - 4) {
            ++maps->map_3d[i - 1][j];
            check = true;
        }
        if (i < maps->size.x - 1 && maps->map_3d[i + 1][j] < maps->map_3d[i][j] - 4) {
            ++maps->map_3d[i + 1][j];
            check = true;
        }
        if (j > 0 && maps->map_3d[i][j - 1] < maps->map_3d[i][j] - 4) {
            ++maps->map_3d[i][j - 1];
            check = true;
        }
        if (j < maps->size.y - 1 && maps->map_3d[i][j + 1] < maps->map_3d[i][j] - 4) {
            ++maps->map_3d[i][j + 1];
            check = true;
        }
    }
    return (check);
}

bool check_incidence_right(map_t *maps, events_t *all_events, int i, int j)
{
    bool check = false;
    if (all_events->mouse.right) {
        if (i > 0 && maps->map_3d[i - 1][j] > maps->map_3d[i][j] + 4) {
            --maps->map_3d[i - 1][j];
            check = true;
        }
        if (i < maps->size.x - 1 && maps->map_3d[i + 1][j] > maps->map_3d[i][j] + 4) {
            --maps->map_3d[i + 1][j];
            check = true;
        }
        if (j > 0 && maps->map_3d[i][j - 1] > maps->map_3d[i][j] + 4) {
            --maps->map_3d[i][j - 1];
            check = true;
        }
        if (j < maps->size.y - 1 && maps->map_3d[i][j + 1] > maps->map_3d[i][j] + 4) {
            --maps->map_3d[i][j + 1];
            check = true;
        }
    }
    return (check);
}

bool check_incidence(map_t *maps, events_t *all_events)
{
    bool check = false;

    for (int i = 0; i < maps->size.x; ++i) {
        for (int j = 0; j < maps->size.y; ++j) {
            check_incidence_left(maps, all_events, i, j);
            check_incidence_right(maps, all_events, i, j);
        }
    }
    return (check);
}

void check_one_point(map_t *maps, sfVector2i pos_mouse, bool up, sfVector2i index)
{
    int i = index.x;
    int j = index.y;

    if (((int)maps->map_2d[i][j].iso.x > pos_mouse.x - maps->radius && (int)maps->map_2d[i][j].iso.x < pos_mouse.x + maps->radius)
    && ((int)maps->map_2d[i][j].iso.y > pos_mouse.y - maps->radius && (int)maps->map_2d[i][j].iso.y < pos_mouse.y + maps->radius))
        if (up)
            ++maps->map_3d[i][j];
        else
            maps->map_3d[i][j] > -49 ? --maps->map_3d[i][j] : 0;
}

void parse_points_up_or_down(map_t *maps, sfVector2i pos_mouse, bool up)
{
    for (int i = 0; i < maps->size.x; ++i) {
        for (int j = 0; j < maps->size.y; ++j) {
            check_one_point(maps, pos_mouse, up, (sfVector2i){i, j});
        }
    }
}

