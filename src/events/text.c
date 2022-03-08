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
    if (event.text.unicode >= 48 && event.text.unicode <= 57 &&
    my_strlen(begin->text.largeur) < 4)
        begin->text.largeur = my_strcat(begin->text.largeur,
        my_itoa(event.text.unicode - 48));
}

void events_write_hauteur(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (event.text.unicode >= 48 && event.text.unicode <= 57 &&
    my_strlen(begin->text.hauteur) < 4)
        begin->text.hauteur = my_strcat(begin->text.hauteur,
        my_itoa(event.text.unicode - 48));
}
