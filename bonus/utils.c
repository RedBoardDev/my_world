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
    sfClock_destroy(begin->fps.clock);
    free(begin->framebuffer);
    sfRenderWindow_destroy(begin->window);
}

int my_rand(int min, int max)
{
    return (min + rand() % (max - min));
}

bool check_mouse_on_one_button(sfVector2i pos, sfFloatRect collision)
{
    if (pos.x > collision.left &&
    pos.x < collision.left + collision.width &&
    pos.y > collision.top &&
    pos.y < collision.top + collision.height)
        return (true);
    else
        return (false);
}
