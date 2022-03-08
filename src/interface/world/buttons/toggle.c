/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** toggle.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_toggle_move(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    begin->guiworld.toggle_move = (begin->guiworld.toggle_move) ? false : true;
    begin->guiworld.toggle_rotate = false;
}

void button_toggle_rotate(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    begin->guiworld.toggle_rotate = (begin->guiworld.toggle_rotate) ?
    false : true;
    begin->guiworld.toggle_move = false;
}

void button_painter(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->guiworld.painter = (begin->guiworld.painter) ? false : true;
    maps->painter = (maps->painter) ? false : true;
}

void button_rotate_360(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    begin->guiworld.rotate_360 = (begin->guiworld.rotate_360) ? false : true;
}
