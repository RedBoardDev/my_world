/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** key.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_key_pressed(beginning_t *begin, sfEvent event, events_t *all_events)
{
    if (sfKeyEscape == event.key.code)
        sfRenderWindow_close(begin->window);

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

    if (sfKeySpace == event.key.code)
        all_events->space = true;

    // if (sfKeyAdd == event.key.code)
    //     all_events->add = true;
    // if (sfKeySubtract == event.key.code)
    //     all_events->substract = true;

    // if (sfKeyMultiply == event.key.code)
    //     all_events->multiply = true;
    // if (sfKeyDivide == event.key.code)
    //     all_events->divide = true;

    if (sfKeyLControl == event.key.code || sfKeyRControl == event.key.code)
        all_events->ctrl = true;
}

void events_key_released(sfEvent event, events_t *all_events)
{
    if (sfKeyRight == event.key.code)
        all_events->right = false;
    if (sfKeyLeft == event.key.code)
        all_events->left = false;

    if (sfKeyUp == event.key.code)
        all_events->up = false;
    if (sfKeyDown == event.key.code)
        all_events->down = false;

    if (sfKeyPageUp == event.key.code)
        all_events->page_up = false;
    if (sfKeyPageDown == event.key.code)
        all_events->page_down = false;

    if (sfKeyZ == event.key.code)
        all_events->z = false;
    if (sfKeyS == event.key.code)
        all_events->s = false;
    if (sfKeyQ == event.key.code)
        all_events->q = false;
    if (sfKeyD == event.key.code)
        all_events->d = false;

    if (sfKeyP == event.key.code)
        all_events->p = false;
    if (sfKeyM == event.key.code)
        all_events->m = false;

    if (sfKeySpace == event.key.code)
        all_events->space = false;

    // if (sfKeyAdd == event.key.code)
    //     all_events->add = false;
    // if (sfKeySubtract == event.key.code)
    //     all_events->substract = false;

    // if (sfKeyMultiply == event.key.code)
    //     all_events->multiply = false;
    // if (sfKeyDivide == event.key.code)
    //     all_events->divide = false;

    if (sfKeyLControl == event.key.code || sfKeyRControl == event.key.code)
        all_events->ctrl = false;
}