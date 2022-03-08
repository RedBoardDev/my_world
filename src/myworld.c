/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void draw_map_all(beginning_t *begin, events_t *all_events, map_t *maps)
{
    if (begin->guiworld.rotate_360) {
        ++maps->angle.x;
    } else {
        play_sound(begin->sound.gngngn);
    }
    exec_events_map(all_events, maps, begin);
    create_2d_map(maps, maps->size);
    draw_2d_map(begin, maps);
    my_draw_circle(begin->framebuffer, all_events->mouse.pos, maps->radius,
    (sfColor){0, 0, 0, 100});
}

void draw_all(world_t *world)
{
    if (world->begin.screen.world) {
        my_draw_rectangle(world->begin.framebuffer, (sfIntRect){0, 0, 470, 105},
        (sfColor){150, 150, 150, 150});
        if (world->begin.guiworld.toggle_move ||
        world->begin.guiworld.toggle_rotate)
            my_draw_rectangle(world->begin.framebuffer,
            (sfIntRect){1670, 908, 1920, 1080}, (sfColor){150, 150, 150, 150});
    }
    sfSprite_setTexture(world->begin.sprite, world->begin.texture, sfFalse);
    sfTexture_updateFromPixels(world->begin.texture,
    world->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(world->begin.window,
    world->begin.sprite, NULL);
    put_all_spritesheets(&world->begin, world->spritesheet, world->load_button);
    put_text_imput(&world->begin, &world->all_events);
    sfRenderWindow_display(world->begin.window);
}

void big_loop(world_t *world)
{
    if (world->begin.init_map) {
        play_sound(world->begin.sound.launch_maps);
        init_empty_map_with_size(&world->all_events, &world->maps);
        world->begin.init_map = false;
    }
    clean_window(&world->begin, sfBlack);
    my_events(&world->begin, &world->all_events);
    if (world->begin.screen.world)
        draw_map_all(&world->begin, &world->all_events, &world->maps);
    check_click_buttons(world);
    if (world->begin.get_file)
        init_display_folder_with_maps(world);
    check_mouse_on_all_buttons(&world->begin, &world->all_events,
    world->spritesheet, world->load_button);
    draw_all(world);
}

void my_world(bool map, sfVector2i size, char *filepath)
{
    world_t world = {init_maps_begin(size), .all_events = init_all_events(),
    .spritesheet = malloc(sizeof(spritesheet_t) * NBR_SPRITE),
    .load_button = NULL};

    init_all(&world.begin, &world.maps, world.spritesheet,
    (size.x == -1 && size.y == -1) ? false : true);
    if (!world.begin.window || !world.begin.framebuffer)
        exit(84);
    sfWindow_setFramerateLimit((sfWindow *)world.begin.window, 60);
    while (sfRenderWindow_isOpen(world.begin.window))
        big_loop(&world);
    destroy_all(&world.begin);
    for (int i = 0; i < world.maps.size.x; ++i)
        free(world.maps.map_2d[i]);
    free(world.maps.map_2d);
    free_int_array(world.maps.map_3d, world.maps.size.x);
}
