/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** put_menu.c
*/

#include "../../../include/my.h"
#include "../../../include/struct.h"
#include "../../../include/myworld.h"

void draw_one_sprite(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfSprite_setTextureRect(spritesheet->sprite, spritesheet->rect);
    sfSprite_setPosition(spritesheet->sprite, spritesheet->pos);
    sfRenderWindow_drawSprite(begin->window, spritesheet->sprite, NULL);
}

void draw_buttons(beginning_t *begin, spritesheet_t *spritesheet)
{
    for (int i = 0; i < NBR_SPRITE; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, &spritesheet[i]);
}

void main_menu(beginning_t *begin, spritesheet_t *spritesheet)
{
    for (int i = 0; i < NBR_SPRITE; ++i)
        spritesheet[i].active = false;
    spritesheet[S_SHUTDOWN].active = true;
    if (begin->screen.main_menu) {
        spritesheet[S_BACKGROUND].active = true;
        spritesheet[S_CREATE_MAP].active = true;
        spritesheet[S_LOAD_MAP].active = true;
        spritesheet[S_EXIT].active = true;
    }
    if (begin->screen.create_menu) {
        spritesheet[S_BACKGROUND].active = true;
        spritesheet[S_CREATE_MAP].active = true;
        spritesheet[S_HAUTEUR].active = true;
        spritesheet[S_LARGEUR].active = true;
        spritesheet[S_BACK_MENU].active = true;
    }
    if (begin->screen.load_menu) {
        spritesheet[S_BACKGROUND].active = true;
        spritesheet[S_LOAD_MAP].active = true;
        spritesheet[S_BACK_MENU].active = true;
    }
    draw_buttons(begin, spritesheet);
}
