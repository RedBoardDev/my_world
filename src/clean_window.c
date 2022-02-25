/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** draw.c
*/

#include "../include/struct.h"
#include "../include/myworld.h"

void my_draw_rectangle(sfUint8 *framebuffer, unsigned int x, unsigned int y,
sfColor color)
{
    for (unsigned int i = 0; x > i; ++i)
        for (unsigned int j = 0; y > j; ++j)
            *(sfColor *)(4 * (j * WIDTH + i) + framebuffer) = color;
}

void my_clear_framebuffer(sfUint8 *framebuffer, sfColor color)
{
    my_draw_rectangle(framebuffer, WIDTH, HEIGHT, sfTransparent);
}

void clean_window(beginning_t *begin, sfColor color)
{
    sfRenderWindow_clear(begin->window, color);
    my_clear_framebuffer(begin->framebuffer, color);
}
