/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** move_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

bool check_incidence(map_t *maps, events_t *all_events)
{
    bool check = false;

    for (int i = 0; i < maps->size.x; ++i) {
        for (int j = 0; j < maps->size.y; ++j) {
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

            else if (all_events->mouse.right) {
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
        }
    }
    return (check);
}

void parse_to_get_point(map_t *maps, sfVector2i pos, bool up)
{
    int radius = maps->radius;

    for (int i = 0; i < maps->size.x; ++i) {
        for (int j = 0; j < maps->size.y; ++j) {
            if (((int)maps->map_2d[i][j].iso.x > pos.x - radius && (int)maps->map_2d[i][j].iso.x < pos.x + radius)
            && ((int)maps->map_2d[i][j].iso.y > pos.y - radius && (int)maps->map_2d[i][j].iso.y < pos.y + radius))
                if (up)
                    ++maps->map_3d[i][j];
                else
                    maps->map_3d[i][j] > -49 ? --maps->map_3d[i][j] : 0;
        }
    }
}

