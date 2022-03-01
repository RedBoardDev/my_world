/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

bool check_mouse_on_one_button(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet, int i)
{
    sfFloatRect collision;

    if (spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(spritesheet[i].sprite);
        if (all_events->mouse.pos.x > collision.left &&
        all_events->mouse.pos.x < collision.left + collision.width &&
        all_events->mouse.pos.y > collision.top &&
        all_events->mouse.pos.y < collision.top + collision.height) {
            spritesheet[i].rect.top = 541;
            return (true);
        } else
            spritesheet[i].rect.top = 0;
    }
    return (false);
}

void check_mouse_on_buttons(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet)
{
    for (int i = 1; i < NBR_SPRITE; ++i)
        if (check_mouse_on_one_button(begin, all_events, spritesheet, i))
            return;
}

void big_loop(beginning_t *begin, events_t *all_events, map_t *maps,
spritesheet_t *spritesheet)
{
    clean_window(begin, sfBlack);
    my_events(begin, all_events);
    if (begin->screen.world) {
        exec_events_map(all_events, maps);
        create_2d_map(maps, maps->size);
        draw_2d_map(begin, maps);
        my_draw_circle(begin->framebuffer, all_events->mouse.pos, maps->radius,
        (sfColor){0, 0, 0, 100});
    }
    check_mouse_on_buttons(begin, all_events, spritesheet);
    check_click_buttons(begin, all_events, spritesheet);
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

void init_all(beginning_t *begin, map_t *maps, spritesheet_t *spritesheet)
{
    maps->map_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->map_2d[i] = malloc(sizeof(point_t) * maps->size.y);
    maps->backup = int_array_dup(maps->map_3d, maps->size);
    init_spritesheets(spritesheet, begin);
    spritesheet[S_CREATE_MAP].active = true;
    spritesheet[S_LOAD_MAP].active = true;
    spritesheet[S_EXIT].active = true;
    init_csfml(begin);
}

void my_world(bool map, sfVector2i size, char *filepath)
{
    beginning_t begin;
    spritesheet_t *spritesheet = malloc(sizeof(spritesheet_t) * NBR_SPRITE);
    events_t all_events = {.left = false, .right = false, .up = false, .down = false, .page_up = false, .page_down = false, .z = false, .s = false, .q = false, .d = false, .p = false, .m = false, .escape = false, .space = false, .ctrl = false, .mouse = {.left = false, .right = false, .move_x = 0, .move_y = 0, .pos = {0, 0}}, .mouse_wheel = {.up = false, .down = false, .click = false}, .largeur = "", .hauteur = ""};
    map_t maps = {.map_2d = NULL, .map_3d = NULL, .backup = NULL, .size = size, .angle = {0, 0}, .pos = {POS_X, POS_Y}, .zoom = ZOOM, .radius = 50};

    map ? open_map(&maps, filepath) : create_3d_map(&maps, size);
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
    free_int_array(maps.map_3d);
}
