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
    spritesheet[S_CREATE_MAP].active ? draw_sprite(begin, &spritesheet[S_CREATE_MAP]) : 0;
    spritesheet[S_LOAD_MAP].active ? draw_sprite(begin, &spritesheet[S_LOAD_MAP]) : 0;
    spritesheet[S_EXIT].active ? draw_sprite(begin, &spritesheet[S_EXIT]) : 0;
    spritesheet[S_LOAD_MAP].active ? draw_sprite(begin, &spritesheet[S_LOAD_MAP]) : 0;
    spritesheet[S_BACK_TO_MENU].active ? draw_sprite(begin, &spritesheet[S_BACK_TO_MENU]) : 0;
    spritesheet[S_CREATE_MAP].active ? draw_sprite(begin, &spritesheet[S_CREATE_MAP]) : 0;
    spritesheet[S_HAUTEUR].active ? draw_sprite(begin, &spritesheet[S_HAUTEUR]) : 0;
    spritesheet[S_LARGEUR].active ? draw_sprite(begin, &spritesheet[S_LARGEUR]) : 0;
    spritesheet[S_BACK_TO_MENU].active ? draw_sprite(begin, &spritesheet[S_BACK_TO_MENU]) : 0;
    spritesheet[S_SHUTDOWN].active ? draw_sprite(begin, &spritesheet[S_SHUTDOWN]) : 0;
}
