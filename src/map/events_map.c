/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_zoom_and_selector_map(events_t *all_events, map_t *maps)
{
    if (all_events->page_down && maps->zoom > 0)
        --maps->zoom;
    if (all_events->page_up)
        ++maps->zoom;
    if (all_events->ctrl && all_events->mouse_wheel.up)
        ++maps->zoom;
    if (all_events->ctrl && all_events->mouse_wheel.down && maps->zoom > 0)
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

void events_modify_points_map(events_t *all_events, map_t *maps,
beginning_t *begin)
{
    bool incidence = true;
    sfFloatRect collision_top = {0, 0, 470, 105};
    sfFloatRect collision_bottom = {1670, 908, 1920, 1080};

    if (all_events->mouse.left &&
    !check_mouse_on_one_button(all_events->mouse.pos, collision_top) &&
    ((begin->guiworld.toggle_move || begin->guiworld.toggle_rotate) ?
    !check_mouse_on_one_button(all_events->mouse.pos, collision_bottom) : 1))
        if (maps->painter)
            increase_decrease_points_zero(maps, all_events->mouse.pos, true);
        else
            increase_decrease_points_mouse(maps, all_events->mouse.pos, true);
    if (all_events->mouse.right)
        if (maps->painter)
            increase_decrease_points_zero(maps, all_events->mouse.pos, false);
        else
            increase_decrease_points_mouse(maps, all_events->mouse.pos, false);
    while (incidence)
        incidence = check_incidence(maps, all_events);
}

void events_translate_map(events_t *all_events, map_t *maps)
{
    events_t backup_events = *all_events;
    check_limit_translation_map(maps, &backup_events);

    if (!backup_events.ctrl && backup_events.z)
        maps->pos.y -= 5;
    if (!backup_events.ctrl && backup_events.s)
        maps->pos.y += 5;
    if (!backup_events.ctrl && backup_events.q)
        maps->pos.x -= 5;
    if (!backup_events.ctrl && backup_events.d)
        maps->pos.x += 5;
    if (!backup_events.ctrl && backup_events.mouse.move_x &&
    backup_events.mouse_wheel.click)
        maps->pos.x -= backup_events.mouse.move_x;
    if (!backup_events.ctrl && backup_events.mouse.move_y &&
    backup_events.mouse_wheel.click)
        maps->pos.y -= backup_events.mouse.move_y;
}

void exec_events_map(events_t *all_events, map_t *maps, beginning_t *begin)
{
    if (!begin->save_file) {
        if (all_events->ctrl && all_events->s)
            begin->save_file = true;
        if (all_events->space) {
            free_int_array(maps->map_3d, maps->size.x);
            maps->map_3d = int_array_dup(maps->backup_3d, maps->size);
        }
        events_rotate_map(all_events, maps);
        events_zoom_and_selector_map(all_events, maps);
        events_modify_points_map(all_events, maps, begin);
        events_translate_map(all_events, maps);
    }
}
