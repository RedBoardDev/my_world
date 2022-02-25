/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** put_menu.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void draw_sprite(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfSprite_setTextureRect(spritesheet->sprite, spritesheet->rect);
    sfSprite_setPosition(spritesheet->sprite, spritesheet->pos);
    sfRenderWindow_drawSprite(begin->window, spritesheet->sprite, NULL);
}


void main_menu(beginning_t *begin, spritesheet_t *spritesheet)
{
    draw_sprite(begin, &spritesheet[S_BACKGROUND]);
    draw_sprite(begin, &spritesheet[S_BACK_TO_MENU]);
    draw_sprite(begin, &spritesheet[S_EXIT]);
    draw_sprite(begin, &spritesheet[S_CREATE_MAP]);
    draw_sprite(begin, &spritesheet[S_LOAD_MAP]);
    draw_sprite(begin, &spritesheet[S_HAUTEUR_LARGEUR]);
    draw_sprite(begin, &spritesheet[S_DENSITY]);
    // draw_sprite(begin, &spritesheet[6]);
    // if (begin->screen.main_menu) {

    // }
}
