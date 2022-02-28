/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void exec_events_map(events_t *all_events, map_t *maps)
{
    bool while_incidence = true;

// rotate
    if (all_events->left)
        --maps->angle.x;
    if (all_events->right)
        ++maps->angle.x;
    if (all_events->down)
        --maps->angle.y;
    if (all_events->up)
        ++maps->angle.y;

// zoom
    if (all_events->page_down && maps->zoom > 0)
        --maps->zoom;
    if (all_events->page_up)
        ++maps->zoom;

// translate
    if (all_events->z)
        maps->pos.y -= 5;
    if (all_events->s)
        maps->pos.y += 5;
    if (all_events->q)
        maps->pos.x -= 5;
    if (all_events->d)
        maps->pos.x += 5;

    if (all_events->p)
        ++maps->radius;
    if (all_events->m)
        --maps->radius;

// wheel
    if (all_events->ctrl && all_events->mouse_wheel.up)
        ++maps->zoom;
    else if (all_events->mouse_wheel.up)
        maps->radius += 8;
    if (all_events->ctrl && all_events->mouse_wheel.down)
        --maps->zoom;
    else if (all_events->mouse_wheel.down)
        maps->radius -= 8;

    if (all_events->ctrl && all_events->mouse.move_x && all_events->mouse_wheel.click)
        maps->pos.x -= all_events->mouse.move_x;
    if (all_events->ctrl && all_events->mouse.move_y && all_events->mouse_wheel.click)
        maps->pos.y -= all_events->mouse.move_y;
    if (!all_events->ctrl && all_events->mouse.move_x && all_events->mouse_wheel.click)
        maps->angle.x += all_events->mouse.move_x / 2;

    if (all_events->space) {
        free_int_array(maps->map_3d);
        maps->map_3d = int_array_dup(maps->backup, maps->size);
    }

// modify
    if (all_events->mouse.left) {
        parse_to_get_point(maps, all_events->mouse.pos, true);
    }
    if (all_events->mouse.right) {
        parse_to_get_point(maps, all_events->mouse.pos, false);
    }

    while (while_incidence)
        while_incidence = check_incidence(maps, all_events);

}