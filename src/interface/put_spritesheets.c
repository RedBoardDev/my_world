/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** put_menu.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void draw_buttons_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    for (int i = 0; i < NBR_SPRITE; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, spritesheet[i].sprite, spritesheet[i].rect,
            spritesheet[i].pos);
}

void draw_buttons_load(beginning_t *begin, load_button_t *load_button)
{
    sfVector2f pos;

    for (int i = 0; i < load_button[0].count; ++i) {
        draw_one_sprite(begin, load_button[i].sprite, load_button[i].rect,
            load_button[i].pos);
        pos.x = load_button[i].pos.x - 200;
        pos.y = load_button[i].pos.y - 18;
        write_text(begin, (text_t){load_button[i].name_file, 30, pos,
        (load_button[i].mouse_on ? sfBlack : sfWhite)});
    }
}

void toggle_spritesheets_menu(beginning_t *begin, spritesheet_t *spritesheet)
{
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
        spritesheet[S_BACK_MENU].active = true;
    }
}

void toggle_spritesheets_world(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->screen.world) {
        if (begin->guiworld.toggle_move) {
            spritesheet[S_ARROW_DOWN].active = true;
            spritesheet[S_ARROW_LEFT].active = true;
            spritesheet[S_ARROW_RIGHT].active = true;
            spritesheet[S_ARROW_UP].active = true;
        }
        if (begin->guiworld.toggle_rotate) {
            spritesheet[S_ROTATE_LEFT].active = true;
            spritesheet[S_ROTATE_RIGHT].active = true;
            spritesheet[S_ROTATE_DOWN].active = true;
            spritesheet[S_ROTATE_UP].active = true;
        }
        spritesheet[S_CHANGE_PAINTER].active = true;
        spritesheet[S_HOME].active = true;
        spritesheet[S_ROTATE_360].active = true;
        spritesheet[S_SAVE].active = true;
        spritesheet[S_TOGGLE_MOVE].active = true;
        spritesheet[S_TOGGLE_ROTATE].active = true;
        if (begin->save_file) {
            spritesheet[S_WINDOW_SAVE].active = true;
            spritesheet[S_SAVE_TEXT_BUTTON].active = true;
            spritesheet[S_SAVE_CANCEL].active = true;
            spritesheet[S_SAVE_SAVE].active = true;
        }
    }
    spritesheet[S_SOUND].active = true;
    if (begin->screen.soundbox)
        spritesheet[S_SOUND_POTENTIO].active = true;
}

void put_all_spritesheets(beginning_t *begin, spritesheet_t *spritesheet,
load_button_t *load_button)
{
    for (int i = 0; i < NBR_SPRITE; ++i)
        spritesheet[i].active = false;
    toggle_spritesheets_menu(begin, spritesheet);
    toggle_spritesheets_world(begin, spritesheet);
    spritesheet[S_SHUTDOWN].active = true;
    draw_buttons_spritesheets(begin, spritesheet);
    if (begin->screen.load_menu)
        draw_buttons_load(begin, load_button);
}
