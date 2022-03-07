/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** rotate.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_rotate_left(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->angle.x += 5;
}

void button_rotate_right(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->angle.x -= 5;
}

void button_rotate_down(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->angle.y -= 5;
}

void button_rotate_up(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    maps->angle.y += 5;
}
