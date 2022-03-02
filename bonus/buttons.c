/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void button_shutdown(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfRenderWindow_close(begin->window);
    free(spritesheet);
    // system("shutdown now");
}
