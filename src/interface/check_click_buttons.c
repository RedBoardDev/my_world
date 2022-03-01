/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_click_button.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void check_click_button(beginning_t *begin, events_t *all_events, spritesheet_t *spritesheet)
{
    sfFloatRect collision;
    static const void (*switch_flags[])(beginning_t *, spritesheet_t *) = {nothing, button_back_to_menu, button_exit, button_create_map, button_load_map, button_hauteur, button_largeur, button_shutdown};

    for (int i = 1; all_events->mouse.left && i < NBR_SPRITE; ++i) {
        if (spritesheet[i].active) {
            collision = sfSprite_getGlobalBounds(spritesheet[i].sprite);
            if (all_events->mouse.pos.x > collision.left && all_events->mouse.pos.x < collision.left + collision.width
            && all_events->mouse.pos.y > collision.top && all_events->mouse.pos.y < collision.top + collision.height) {
                (*switch_flags[i])(begin, spritesheet);
                all_events->mouse.left = false;
                return;
            }
        }
    }
}
