/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** menu_buttons.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_create_map(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->screen.main_menu) {
        begin->screen.main_menu = false;
        begin->screen.create_menu = true;
        return;
    } else if (begin->screen.create_menu) {
        begin->screen.create_menu = false;
        begin->screen.world = true;
        begin->init_map = true;
    }
}

void button_load_map(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->screen.main_menu) {
        begin->screen.main_menu = false;
        begin->screen.load_menu = true;
    } else if (begin->screen.load_menu) {
        begin->screen.load_menu = false;
        begin->screen.world = true;
        begin->load_map = true;
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
}
