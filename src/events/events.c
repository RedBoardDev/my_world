/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_key_global(sfEvent event, beginning_t *begin, events_t *all_events)
{
    switch (event.type) {
        case sfEvtKeyPressed:
            events_key_pressed(begin, event, all_events);
            break;
        case sfEvtKeyReleased:
            events_key_released(event, all_events);
            break;
        case sfEvtTextEntered:
            if (begin->screen.create_menu && begin->screen.largeur)
                events_write_largeur(begin, event, all_events);
            break;
        default:
            break;
    }
}

void events_mouse_global(sfEvent event, beginning_t *begin,
events_t *all_events)
{
    switch (event.type) {
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

void my_events(beginning_t *begin, events_t *all_events)
{
    sfEvent event;

    all_events->mouse_wheel.up = false;
    all_events->mouse_wheel.down = false;
    all_events->mouse.move_x = 0;
    all_events->mouse.move_y = 0;
    while (sfRenderWindow_pollEvent(begin->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(begin->window);
        if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased ||
        event.type == sfEvtTextEntered)
            events_key_global(event, begin, all_events);
        if (event.type == sfEvtMouseButtonPressed || event.type ==
        sfEvtMouseButtonReleased || event.type == sfEvtMouseWheelScrolled ||
        event.type == sfEvtMouseMoved)
            events_mouse_global(event, begin, all_events);
    }
    all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
}
