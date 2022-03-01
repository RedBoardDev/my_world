/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_click_button.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

bool check_click_one_button(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet, int i)
{
    static const void (*switch_flags[])(beginning_t *, spritesheet_t *) =
    {nothing, button_back_to_menu, button_exit, button_create_map,
    button_load_map, button_hauteur, button_largeur, button_shutdown};
    sfFloatRect collision;

    if (spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(spritesheet[i].sprite);
        if (all_events->mouse.pos.x > collision.left &&
        all_events->mouse.pos.x < collision.left + collision.width &&
        all_events->mouse.pos.y > collision.top &&
        all_events->mouse.pos.y < collision.top + collision.height) {
            begin->screen.largeur = false;
            begin->screen.hauteur = false;
            (*switch_flags[i])(begin, spritesheet);
            all_events->mouse.left = false;
            return (true);
        }
    }
    return (false);
}

void check_click_buttons(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet)
{
    for (int i = 1; all_events->mouse.left && i < NBR_SPRITE; ++i)
        if (check_click_one_button(begin, all_events, spritesheet, i))
            return;
}
