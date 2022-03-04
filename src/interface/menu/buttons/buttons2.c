/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons2.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void nothing(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    return;
}

void button_hauteur(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->screen.hauteur = true;
}

void button_largeur(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->screen.largeur = true;
}
