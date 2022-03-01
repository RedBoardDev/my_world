/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_rotate_map(events_t *all_events, map_t *maps)
{
    if (all_events->left)
        --maps->angle.x;
    if (all_events->right)
        ++maps->angle.x;
    if (all_events->down)
        --maps->angle.y;
    if (all_events->up)
        ++maps->angle.y;
    if (all_events->ctrl && all_events->mouse.move_x &&
    all_events->mouse_wheel.click)
        maps->angle.x += all_events->mouse.move_x / 2;
}

void events_zoom_and_selector_map(events_t *all_events, map_t *maps)
{
    if (all_events->page_down && maps->zoom > 0)
        --maps->zoom;
    if (all_events->page_up)
        ++maps->zoom;
    if (all_events->ctrl && all_events->mouse_wheel.up)
        ++maps->zoom;
    if (all_events->ctrl && all_events->mouse_wheel.down)
        --maps->zoom;
    if (all_events->p)
        ++maps->radius;
    if (all_events->m)
        --maps->radius;
    if (!all_events->ctrl && all_events->mouse_wheel.down)
        maps->radius -= 8;
    if (!all_events->ctrl && all_events->mouse_wheel.up)
        maps->radius += 8;
}

void events_translate_map(events_t *all_events, map_t *maps)
{
    if (all_events->z)
        maps->pos.y -= 5;
    if (all_events->s)
        maps->pos.y += 5;
    if (all_events->q)
        maps->pos.x -= 5;
    if (all_events->d)
        maps->pos.x += 5;
    if (!all_events->ctrl && all_events->mouse.move_x &&
    all_events->mouse_wheel.click)
        maps->pos.x -= all_events->mouse.move_x;
    if (!all_events->ctrl && all_events->mouse.move_y &&
    all_events->mouse_wheel.click)
        maps->pos.y -= all_events->mouse.move_y;
}

void events_modify_points_map(events_t *all_events, map_t *maps)
{
    bool incidence = true;

    if (all_events->mouse.left)
        parse_points_up_or_down(maps, all_events->mouse.pos, true);
    if (all_events->mouse.right)
        parse_points_up_or_down(maps, all_events->mouse.pos, false);
    while (incidence)
        incidence = check_incidence(maps, all_events);
}

void exec_events_map(events_t *all_events, map_t *maps)
{

    events_rotate_map(all_events, maps);
    events_zoom_and_selector_map(all_events, maps);
    events_translate_map(all_events, maps);
    events_modify_points_map(all_events, maps);
    if (all_events->space) {
        free_int_array(maps->map_3d);
        maps->map_3d = int_array_dup(maps->backup, maps->size);
    }
}