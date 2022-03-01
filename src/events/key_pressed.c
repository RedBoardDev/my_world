/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** key.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_key_pressed_arrows(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfKeyRight == event.key.code)
        all_events->right = true;
    if (sfKeyLeft == event.key.code)
        all_events->left = true;
    if (sfKeyUp == event.key.code)
        all_events->up = true;
    if (sfKeyDown == event.key.code)
        all_events->down = true;
    if (sfKeyPageUp == event.key.code)
        all_events->page_up = true;
    if (sfKeyPageDown == event.key.code)
        all_events->page_down = true;
}

void events_key_pressed_letters(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfKeyZ == event.key.code)
        all_events->z = true;
    if (sfKeyS == event.key.code)
        all_events->s = true;
    if (sfKeyQ == event.key.code)
        all_events->q = true;
    if (sfKeyD == event.key.code)
        all_events->d = true;
    if (sfKeyP == event.key.code)
        all_events->p = true;
    if (sfKeyM == event.key.code)
        all_events->m = true;
}

void events_key_pressed(beginning_t *begin, sfEvent event, events_t *all_events)
{
    if (sfKeyEscape == event.key.code)
        sfRenderWindow_close(begin->window);
    if (sfKeySpace == event.key.code)
        all_events->space = true;
    if (sfKeyLControl == event.key.code || sfKeyRControl == event.key.code)
        all_events->ctrl = true;
    if (sfKeyBackspace == event.key.code) {
        if (begin->screen.hauteur)
            all_events->hauteur[my_strlen(all_events->hauteur) - 1] = '\0';
        if (begin->screen.largeur)
            all_events->largeur[my_strlen(all_events->largeur) - 1] = '\0';
    }
    events_key_pressed_arrows(begin, event, all_events);
    events_key_pressed_letters(begin, event, all_events);
}