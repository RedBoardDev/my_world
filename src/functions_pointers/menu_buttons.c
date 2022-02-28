/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** menu_buttons.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void button_create_map(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->screen.main_menu) {
        begin->screen.main_menu = false;
        begin->screen.create_menu = true;
        for (int i = 0; i < NBR_SPRITE; ++i)
            spritesheet[i].active = false;
        spritesheet[S_CREATE_MAP].active = true;
        spritesheet[S_HAUTEUR].active = true;
        spritesheet[S_LARGEUR].active = true;
        spritesheet[S_BACK_TO_MENU].active = true;
        return;
    } else if (begin->screen.create_menu) {
        begin->screen.create_menu = false;
        begin->screen.world = true;
        for (int i = 0; i < NBR_SPRITE; ++i)
            spritesheet[i].active = false;
    }
}

void button_load_map(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->screen.main_menu) {
        begin->screen.main_menu = false;
        begin->screen.load_menu = true;
        for (int i = 0; i < NBR_SPRITE; ++i)
            spritesheet[i].active = false;
        spritesheet[S_LOAD_MAP].active = true;
        spritesheet[S_BACK_TO_MENU].active = true;
    } else if (begin->screen.load_menu) {
        begin->screen.load_menu = false;
        begin->screen.world = true;
        for (int i = 0; i < NBR_SPRITE; ++i)
            spritesheet[i].active = false;
    }
}

void button_exit(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfRenderWindow_close(begin->window);
}

void button_back_to_menu(beginning_t *begin, spritesheet_t *spritesheet)
{
    begin->screen.create_menu = false;
    begin->screen.load_menu = false;
    begin->screen.world = false;
    begin->screen.main_menu = true;
    for (int i = 0; i < NBR_SPRITE; ++i)
        spritesheet[i].active = false;
    spritesheet[S_CREATE_MAP].active = true;
    spritesheet[S_LOAD_MAP].active = true;
    spritesheet[S_EXIT].active = true;
}

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
    // printf("EE");
    begin->screen.hauteur = true;
}

void button_largeur(beginning_t *begin, spritesheet_t *spritesheet)
{
    // printf("ZZ");
    begin->screen.largeur = true;
}
