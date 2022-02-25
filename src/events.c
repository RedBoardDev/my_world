/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

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

void events_mouse_pressed(beginning_t *begin, sfEvent event, events_t *all_events)
{
    if (sfMouseLeft == event.key.code) {
        all_events->mouse.left = true;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
    }
    if (sfMouseRight == event.key.code) {
        all_events->mouse.right = true;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
    }
    if (sfMouseMiddle == event.key.code)
        all_events->mouse_wheel.click = true;
}

void events_mouse_released(beginning_t *begin, sfEvent event, events_t *all_events)
{
    if (sfMouseLeft == event.key.code) {
        all_events->mouse.left = false;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
    }
    if (sfMouseRight == event.key.code) {
        all_events->mouse.right = false;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
    }
    if (sfMouseMiddle == event.key.code)
        all_events->mouse_wheel.click = false;
}

void events_scroll_wheel(sfEvent event, events_t *all_events)
{
    if (event.mouseWheelScroll.delta > 0)
        all_events->mouse_wheel.up = true;
    else
        all_events->mouse_wheel.up = false;

    if (event.mouseWheelScroll.delta < 0)
        all_events->mouse_wheel.down = true;
    else
        all_events->mouse_wheel.down = false;
}

void event_mouse_moved(sfEvent event, events_t *all_events)
{
    if (all_events->mouse.pos.x != event.mouseMove.x)
        all_events->mouse.move_x = all_events->mouse.pos.x - event.mouseMove.x;
    if (all_events->mouse.pos.y != event.mouseMove.y)
        all_events->mouse.move_y = all_events->mouse.pos.y - event.mouseMove.y;
}

void my_events(beginning_t *begin, events_t *all_events)
{
    sfEvent event;

    all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);

    all_events->mouse_wheel.up = false;
    all_events->mouse_wheel.down = false;

    all_events->mouse.move_x = 0;
    all_events->mouse.move_y = 0;

    while (sfRenderWindow_pollEvent(begin->window, &event))
        switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(begin->window);
                break;
            case sfEvtKeyPressed:
                events_key_pressed(begin, event, all_events);
                break;
            case sfEvtKeyReleased:
                events_key_released(event, all_events);
                break;
            case sfEvtMouseButtonPressed:
                events_mouse_pressed(begin, event, all_events);
                break;
            case sfEvtMouseButtonReleased:
                events_mouse_released(begin, event, all_events);
                break;
            case sfEvtMouseWheelScrolled:
                events_scroll_wheel(event, all_events);
                break;
            case sfEvtMouseMoved:
                event_mouse_moved(event, all_events);
                break;
            default:
                break;
        }
}
