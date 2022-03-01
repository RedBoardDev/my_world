/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons2.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void nothing(beginning_t *begin, spritesheet_t *spritesheet)
{
    return;
}

void button_shutdown(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfRenderWindow_close(begin->window);
    free(spritesheet);
    system("shutdown now");
}

void button_hauteur(beginning_t *begin, spritesheet_t *spritesheet)
{
    begin->screen.hauteur = true;
}

void button_largeur(beginning_t *begin, spritesheet_t *spritesheet)
{
    begin->screen.largeur = true;
}
