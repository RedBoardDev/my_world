/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** save.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_save_window(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    begin->save_file = false;
    save_file("maps/map.myw", maps);
}

void button_cancel_window(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    begin->save_file = false;
}
