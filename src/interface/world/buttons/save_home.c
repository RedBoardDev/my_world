/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons_gui_world.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_home(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->screen.world = false;
    begin->screen.main_menu = true;
}

void button_save(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    save_file("maps/map.myw", maps);
}
