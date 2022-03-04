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
    sfVector2i size = {my_atoi(all_events->hauteur) + 3,
    my_atoi(all_events->largeur) + 3};

    maps->angle.x = 0;
    maps->angle.y = 0;
    maps->zoom = ZOOM;
    maps->pos.x = POS_X;
    maps->pos.y = POS_Y;
    maps->radius = 50;
    maps->size = size;
    create_3d_map(maps, maps->size);
    maps->map_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->map_2d[i] = malloc(sizeof(point_t) * maps->size.y);
    maps->backup_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->backup_2d[i] = malloc(sizeof(point_t) * maps->size.y);

    maps->backup_3d = int_array_dup(maps->map_3d, maps->size);
    create_2d_map(maps, maps->size);
}

void load_map_loop(char *filepath, events_t *all_events, map_t *maps)
{
    load_file(filepath, maps);
    maps->map_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->map_2d[i] = malloc(sizeof(point_t) * maps->size.y);
    maps->backup_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->backup_2d[i] = malloc(sizeof(point_t) * maps->size.y);
    maps->backup_3d = int_array_dup(maps->map_3d, maps->size);
    create_2d_map(maps, maps->size);
}

void draw_map_all(beginning_t *begin, events_t *all_events, map_t *maps)
{
    if (begin->guiworld.rotate_360)
        ++maps->angle.x;
    exec_events_map(all_events, maps);
    create_2d_map(maps, maps->size);
    // maps->map_2d[maps->size.x - 2][0].iso.x = WIDTH;
    draw_2d_map(begin, maps);
    my_draw_circle(begin->framebuffer, all_events->mouse.pos, maps->radius,
    (sfColor){0, 0, 0, 100});
}

void big_loop(world_t *world)
{
    if (world->begin.init_map) {
        init_map(&world->all_events, &world->maps);
        world->begin.init_map = false;
    }
    clean_window(&world->begin, sfBlack);
    my_events(&world->begin, &world->all_events);
    if (world->begin.screen.world)
        draw_map_all(&world->begin, &world->all_events, &world->maps);
    check_click_buttons(world);
    if (world->begin.get_file) {
        free(world->load_button);
        world->load_button = init_load_file(&world->begin);
        world->begin.get_file = false;
        world->maps.angle.x = 0;
        world->maps.angle.y = 0;
        world->maps.zoom = ZOOM;
        world->maps.pos.x = POS_X;
        world->maps.pos.y = POS_Y;
        world->maps.radius = 50;
    }
    check_mouse_on_buttons(&world->begin, &world->all_events, world->spritesheet, world->load_button);
    if (world->begin.screen.world)
        my_draw_rectangle(world->begin.framebuffer, 740, 105, (sfColor){150, 150, 150, 150});
    sfSprite_setTexture(world->begin.sprite, world->begin.texture, sfFalse);
    sfTexture_updateFromPixels(world->begin.texture,
    world->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(world->begin.window,
    world->begin.sprite, NULL);
    main_menu(&world->begin, world->spritesheet, world->load_button);
    put_text(&world->begin, &world->all_events);
    sfRenderWindow_display(world->begin.window);
}

void my_world(bool map, sfVector2i size, char *filepath)
{
    world_t world;
    spritesheet_t *spritesheet = malloc(sizeof(spritesheet_t) * NBR_SPRITE);
    events_t all_events = init_all_events();

    world.load_button = NULL;
    world.maps = init_maps_begin(size);
    world.all_events = all_events;
    world.spritesheet = spritesheet;
    init_all(&world.begin, &world.maps, spritesheet, (size.x == -1 && size.y == -1) ? false : true);
    if (!world.begin.window || !world.begin.framebuffer)
        exit(84);
    sfWindow_setFramerateLimit((sfWindow *)world.begin.window, 60);
    // world.begin.screen.world = false;
    while (sfRenderWindow_isOpen(world.begin.window)) {
        big_loop(&world);
    }
    destroy_all(&world.begin);
    for (int i = 0; i < world.maps.size.x; ++i)
        free(world.maps.map_2d[i]);
    free(world.maps.map_2d);
    free_int_array(world.maps.map_3d, world.maps.size.x);
}
