/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** text.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_write_largeur(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (event.text.unicode >= 48 && event.text.unicode <= 57)
        all_events->largeur = my_strcat(all_events->largeur,
        my_itoa(event.text.unicode - 48));
}
