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

void check_limit_translation_map(map_t *maps, events_t *all_events)
{
    if ((maps->angle.x % 360 >= 315 && maps->angle.x % 360 <= 360) ||
    (maps->angle.x % 360 >= 0 && maps->angle.x % 360 < 45)) {
        if (maps->backup_2d[0][maps->size.y - 1].iso.x < 0 && maps->backup_2d[maps->size.x - 1][0].iso.x > WIDTH)
            return;
        if ((maps->backup_2d[0][maps->size.y - 1].iso.x < 0))
            all_events->q = false;
        if ((maps->backup_2d[maps->size.x - 1][0].iso.x > WIDTH))
            all_events->d = false;
    }

    if (maps->angle.x % 360 >= 45 && maps->angle.x % 360 < 135) {
        if (maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x < 0 && maps->backup_2d[0][0].iso.x > WIDTH)
            return;
        if ((maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x < 0))
            all_events->q = false;
        if ((maps->backup_2d[0][0].iso.x > WIDTH))
            all_events->d = false;
    }

    if (maps->angle.x % 360 >= 135 && maps->angle.x % 360 < 225) {
        if (maps->backup_2d[maps->size.x - 1][0].iso.x < 0 && maps->backup_2d[0][maps->size.y - 1].iso.x > WIDTH)
            return;
        if ((maps->backup_2d[maps->size.x - 1][0].iso.x < 0))
            all_events->q = false;
        if ((maps->backup_2d[0][maps->size.y - 1].iso.x > WIDTH))
            all_events->d = false;
    }

    if (maps->angle.x % 360 >= 225 && maps->angle.x % 360 < 315) {
        if (maps->backup_2d[0][0].iso.x < 0 && maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x > WIDTH)
            return;
        if ((maps->backup_2d[0][0].iso.x < 0))
            all_events->q = false;
        if ((maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x > WIDTH))
            all_events->d = false;
    }
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

void check_one_point_other(map_t *maps, sfVector2i pos_mouse, bool up,
sfVector2i index)
{
    int i = index.x;
    int j = index.y;

    if (((int)maps->backup_2d[i][j].iso.x > pos_mouse.x - maps->radius &&
    (int)maps->backup_2d[i][j].iso.x < pos_mouse.x + maps->radius) &&
    ((int)maps->backup_2d[i][j].iso.y > pos_mouse.y - maps->radius &&
    (int)maps->backup_2d[i][j].iso.y < pos_mouse.y + maps->radius)) {
        if (up)
            maps->map_3d[i][j] != -100 ? ++maps->map_3d[i][j] : 0;
        else
            maps->map_3d[i][j] > -49 ? --maps->map_3d[i][j] : 0;
    }
}

void test_modify_by_zero(map_t *maps, sfVector2i pos_mouse, bool up)
{
    if ((maps->angle.x % 360 >= 315 && maps->angle.x % 360 <= 360) ||
    (maps->angle.x % 360 >= 0 && maps->angle.x % 360 < 45))
        for (int i = 0; i < maps->size.x; ++i)
            for (int j = 0; j < maps->size.y; ++j)
                check_one_point_other(maps, pos_mouse, up, (sfVector2i){i, j});

    if (maps->angle.x % 360 >= 45 && maps->angle.x % 360 < 135)
        for (int i = 0; i < maps->size.x; ++i)
            for (int j = maps->size.y - 1; j >= 0; --j)
                check_one_point_other(maps, pos_mouse, up, (sfVector2i){i, j});

    if (maps->angle.x % 360 >= 135 && maps->angle.x % 360 < 225)
        for (int i = maps->size.x - 1; i >= 0; --i)
            for (int j = maps->size.y - 1; j >= 0; --j)
                check_one_point_other(maps, pos_mouse, up, (sfVector2i){i, j});

    if (maps->angle.x % 360 >= 225 && maps->angle.x % 360 < 315)
        for (int i = maps->size.x - 1; i >= 0; --i)
            for (int j = 0; j < maps->size.y; ++j)
                check_one_point_other(maps, pos_mouse, up, (sfVector2i){i, j});
}

void events_modify_points_map(events_t *all_events, map_t *maps)
{
    bool incidence = true;

    if (all_events->mouse.left)
        if (maps->painter)
            test_modify_by_zero(maps, all_events->mouse.pos, true);
        else
            parse_points_up_or_down(maps, all_events->mouse.pos, true);
    if (all_events->mouse.right)
        if (maps->painter)
            test_modify_by_zero(maps, all_events->mouse.pos, false);
        else
            parse_points_up_or_down(maps, all_events->mouse.pos, false);
    while (incidence)
        incidence = check_incidence(maps, all_events);
}

void exec_events_map(events_t *all_events, map_t *maps)
{
    if (all_events->ctrl && all_events->s)
        save_file("maps/map.myw", maps);
    if (all_events->space) {
        free_int_array(maps->map_3d, maps->size.x);
        maps->map_3d = int_array_dup(maps->backup_3d, maps->size);
    }

    events_rotate_map(all_events, maps);
    events_zoom_and_selector_map(all_events, maps);
    events_modify_points_map(all_events, maps);
    events_translate_map(all_events, maps);
}
