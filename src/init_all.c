/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void init_all(beginning_t *begin, map_t *maps, spritesheet_t *spritesheet)
{
    init_spritesheets(spritesheet, begin);
    spritesheet[S_CREATE_MAP].active = true;
    spritesheet[S_LOAD_MAP].active = true;
    spritesheet[S_EXIT].active = true;
    spritesheet[S_SHUTDOWN].active = true;
    begin->init_map = false;
    begin->screen.largeur = false;
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
    return ((map_t){.map_2d = NULL, .map_3d = NULL, .backup = NULL,
    .size = size, .angle = {0, 0}, .pos = {POS_X, POS_Y},
    .zoom = ZOOM, .radius = 50});
}
