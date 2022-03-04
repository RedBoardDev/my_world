/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons_gui_world.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_arrow_down(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    maps->pos.y += 10;
}

void button_arrow_left(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    maps->pos.x -= 10;
}

void button_arrow_right(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    maps->pos.x += 10;
}

void button_arrow_up(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    maps->pos.y -= 10;
}

void button_painter(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->guiworld.painter = (begin->guiworld.painter == true) ? false : true;
    maps->painter = (maps->painter == true) ? false : true;
}

void button_home(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->screen.world = false;
    begin->screen.main_menu = true;
}

void button_rotate_360(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->guiworld.rotate_360 = (begin->guiworld.rotate_360 == true) ? false : true;
}

void button_save(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    save_file("maps/oui.myw", maps);
}

void button_toggle_move(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->guiworld.toggle_move = (begin->guiworld.toggle_move == true) ? false : true;
    begin->guiworld.toggle_rotate = false;
}

void button_toggle_rotate(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->guiworld.toggle_rotate = (begin->guiworld.toggle_rotate == true) ? false : true;
    begin->guiworld.toggle_move = false;
}

void button_rotate_left(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    maps->angle.x -= 5;
}

void button_rotate_right(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    maps->angle.x += 5;
}
