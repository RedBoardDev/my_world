/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** utils.c
*/

#include "../include/myworld.h"

sfUint8 *my_framebuffer_create(void)
{
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    return (framebuffer);
}

void init_csfml(beginning_t *begin)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    begin->window = sfRenderWindow_create(mode, "My world",
    sfClose | sfFullscreen, NULL);
    begin->framebuffer = my_framebuffer_create();
    begin->texture = sfTexture_create(WIDTH, HEIGHT);
    begin->sprite = sfSprite_create();
}

void destroy_all(beginning_t *begin)
{
    free(begin->framebuffer);
    sfRenderWindow_destroy(begin->window);
}

int my_rand(int min, int max)
{
    return (min + rand() % (max - min));
}
