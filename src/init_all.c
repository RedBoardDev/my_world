/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void init_all(beginning_t *begin, map_t *maps, spritesheet_t *spritesheet,
bool init_map)
{
    if (init_map) {
        create_3d_map(maps, maps->size);
        maps->map_2d = malloc(sizeof(point_t *) * maps->size.x);
        for (int i = 0; i < maps->size.x; ++i)
            maps->map_2d[i] = malloc(sizeof(point_t) * maps->size.y);

        maps->backup_2d = malloc(sizeof(point_t *) * maps->size.x);
        for (int i = 0; i < maps->size.x; ++i)
            maps->backup_2d[i] = malloc(sizeof(point_t) * maps->size.y);

        maps->backup_3d = int_array_dup(maps->map_3d, maps->size);
        create_2d_map(maps, maps->size);
    }
    init_spritesheets(spritesheet, begin);
    spritesheet[S_CREATE_MAP].active = init_map ? false : true;
    spritesheet[S_LOAD_MAP].active = init_map ? false : true;
    spritesheet[S_EXIT].active = init_map ? false : true;
    spritesheet[S_SHUTDOWN].active = init_map ? false : true;
    begin->init_map = false;
    begin->load_map = false;
    begin->get_file = false;
    begin->screen.largeur = false;
    begin->screen.hauteur = false;

    begin->screen.main_menu = init_map ? false : true;
    begin->screen.world = init_map ? true : false;
    begin->screen.load_menu = false;
    begin->screen.create_menu = false;
    begin->screen.hauteur = false;

    init_csfml(begin);
}

events_t init_all_events(void)
{
    return ((events_t){.left = false, .right = false, .up = false,
    .down = false, .page_up = false, .page_down = false, .z = false, .s = false,
    .q = false, .d = false, .p = false, .m = false, .escape = false,
    .space = false, .ctrl = false, .tab = false, .enter = false, .mouse =
    {.left = false, .left_released = false, .right = false, .move_x = 0,
    .move_y = 0, .pos = {0, 0}}, .mouse_wheel = {.up = false, .down = false,
    .click = false}, .largeur = "", .hauteur = ""});
}

map_t init_maps_begin(sfVector2i size)
{
    return ((map_t){.map_2d = NULL, .backup_2d = NULL, .map_3d = NULL, .backup_3d = NULL,
    .size = size, .angle = {0, 0}, .pos = {POS_X, POS_Y},
    .zoom = ZOOM, .radius = 50});
}
