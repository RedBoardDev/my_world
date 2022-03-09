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
    begin->text.hauteur_b = true;
}

void button_largeur(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    begin->text.largeur_b = true;
}

void button_sound(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    if (begin->screen.soundbox)
        begin->screen.soundbox = false;
    else
        begin->screen.soundbox = true;
}