/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void init_map(events_t *all_events, map_t *maps)
{
    sfVector2i size = {my_atoi(all_events->hauteur) + 1,
    my_atoi(all_events->largeur) + 1};

    maps->size = size;
    create_3d_map(maps, maps->size);
    maps->map_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->map_2d[i] = malloc(sizeof(point_t) * maps->size.y);
    maps->backup = int_array_dup(maps->map_3d, maps->size);
    create_2d_map(maps, maps->size);
}

void draw_map_all(beginning_t *begin, events_t *all_events, map_t *maps)
{
    exec_events_map(all_events, maps);
    create_2d_map(maps, maps->size);
    draw_2d_map(begin, maps);
    my_draw_circle(begin->framebuffer, all_events->mouse.pos, maps->radius,
    (sfColor){0, 0, 0, 100});
}

void big_loop(beginning_t *begin, events_t *all_events, map_t *maps,
spritesheet_t *spritesheet)
{
    if (begin->init_map) {
        init_map(all_events, maps);
        begin->init_map = false;
    }
    clean_window(begin, sfBlack);
    my_events(begin, all_events);
    if (begin->screen.world)
        draw_map_all(begin, all_events, maps);
    check_click_buttons(begin, all_events, spritesheet);
    check_mouse_on_buttons(begin, all_events, spritesheet);
    sfSprite_setTexture(begin->sprite, begin->texture, sfFalse);
    sfTexture_updateFromPixels(begin->texture,
    begin->framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(begin->window,
    begin->sprite, NULL);
    if (!begin->screen.world)
        main_menu(begin, spritesheet);
    put_text(begin, all_events);
    sfRenderWindow_display(begin->window);
}

void my_world(bool map, sfVector2i size, char *filepath)
{
    beginning_t begin;
    spritesheet_t *spritesheet = malloc(sizeof(spritesheet_t) * NBR_SPRITE);
    events_t all_events = init_all_events();
    map_t maps = init_maps_begin(size);

    init_all(&begin, &maps, spritesheet);
    if (!begin.window || !begin.framebuffer)
        exit(84);
    sfWindow_setFramerateLimit((sfWindow *)begin.window, 60);
    while (sfRenderWindow_isOpen(begin.window))
        big_loop(&begin, &all_events, &maps, spritesheet);
    destroy_all(&begin);
    for (int i = 0; i < maps.size.x; ++i)
        free(maps.map_2d[i]);
    free(maps.map_2d);
    free_int_array(maps.map_3d, maps.size.x);
}
