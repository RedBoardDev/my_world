/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_mouse_on_buttons.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

bool check_mouse_on_one_button(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet, int i)
{
    sfFloatRect collision;

    if (spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(spritesheet[i].sprite);
        if (all_events->mouse.pos.x > collision.left &&
        all_events->mouse.pos.x < collision.left + collision.width &&
        all_events->mouse.pos.y > collision.top &&
        all_events->mouse.pos.y < collision.top + collision.height) {
            spritesheet[i].rect.top = 541;
            return (true);
        } else
            spritesheet[i].rect.top = 0;
    }
    return (false);
}

void check_mouse_on_buttons(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet)
{
    for (int i = 1; i < NBR_SPRITE; ++i)
        check_mouse_on_one_button(begin, all_events, spritesheet, i);
    if (begin->screen.largeur)
        spritesheet[S_LARGEUR].rect.top = 541;
    if (begin->screen.hauteur)
        spritesheet[S_HAUTEUR].rect.top = 541;

}
