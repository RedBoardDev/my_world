/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** arrows.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_arrow_down(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->pos.y += 10;
}

void button_arrow_left(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->pos.x -= 10;
}

void button_arrow_right(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->pos.x += 10;
}

void button_arrow_up(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->pos.y -= 10;
}
