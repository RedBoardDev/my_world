/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void draw_2d_map(beginning_t *begin, map_t *maps)
{
    my_quad_t quad;
    point_t buff;

    if (maps->angle.x < 0)
        maps->angle.x = 360;
    if (maps->angle.x % 360 >= 315 && maps->angle.x % 360 <= 360 || maps->angle.x % 360 >= 0 && maps->angle.x % 360 < 45)
        for (int i = 0; i < maps->size.x; ++i) {
            for (int j = 0; j < maps->size.y; ++j) {
                quad.a = (j < maps->size.y - 1) ? maps->map_2d[i][j] : buff;
                quad.b = (j < maps->size.y - 1) ? maps->map_2d[i][j + 1] : buff;
                quad.c = (i < maps->size.x - 1) ? maps->map_2d[i + 1][j] : buff;
                quad.d = (i < maps->size.x - 1 && j < maps->size.y - 1) ? maps->map_2d[i + 1][j + 1] : buff;
                (i < maps->size.x - 1 && j < maps->size.y - 1) ? create_quad(begin, quad, maps->angle.x) : 0;
            }
        }
    else if (maps->angle.x % 360 >= 45 && maps->angle.x % 360 < 135)
        for (int i = 0; i < maps->size.x; ++i) {
            for (int j = maps->size.y - 1; j >= 0; --j) {
                quad.a = (j > 0) ? maps->map_2d[i][j] : buff;
                quad.b = (j > 0) ? maps->map_2d[i][j - 1] : buff;
                quad.c = (i < maps->size.x - 1) ? maps->map_2d[i + 1][j] : buff;
                quad.d = (i < maps->size.x - 1 && j > 0) ? maps->map_2d[i + 1][j - 1] : buff;
                (i < maps->size.x - 1 && j > 0) ? create_quad(begin, quad, maps->angle.x) : 0;
            }
        }
    else if (maps->angle.x % 360 >= 135 && maps->angle.x % 360 < 225)
        for (int i = maps->size.x - 1; i >= 0; --i) {
            for (int j = maps->size.y - 1; j >= 0; --j) {
                quad.a = (j > 0) ? maps->map_2d[i][j] : buff;
                quad.b = (j > 0) ? maps->map_2d[i][j - 1] : buff;
                quad.c = (i > 0) ? maps->map_2d[i - 1][j] : buff;
                quad.d = (i > 0 && j > 0) ? maps->map_2d[i - 1][j - 1] : buff;
                (i > 0 && j > 0) ? create_quad(begin, quad, maps->angle.x) : 0;
            }
        }
    else if (maps->angle.x % 360 >= 225 && maps->angle.x % 360 < 315)
        for (int i = maps->size.x - 1; i >= 0; --i) {
            for (int j = 0; j < maps->size.y; ++j) {
                quad.a = (j < maps->size.y - 1) ? maps->map_2d[i][j] : buff;
                quad.b = (j < maps->size.y - 1) ? maps->map_2d[i][j + 1] : buff;
                quad.c = (i > 0) ? maps->map_2d[i - 1][j] : buff;
                quad.d = (i > 0 && j < maps->size.y - 1) ? maps->map_2d[i - 1][j + 1] : buff;
                (i > 0 && j < maps->size.y - 1) ? create_quad(begin, quad, maps->angle.x) : 0;
            }
        }

    // printf("angle = %d [%d]\n", maps->angle.x, maps->angle.x % 360);
}

bool check_incidence(map_t *maps, events_t *all_events)
{
    bool check = false;

    for (int i = 0; i < maps->size.x; ++i) {
        for (int j = 0; j < maps->size.y; ++j) {
            if (all_events->mouse.left) {
                if (i > 0 && maps->map_3d[i - 1][j] < maps->map_3d[i][j] - 4) {
                    ++maps->map_3d[i - 1][j];
                    check = true;
                }
                if (i < maps->size.x - 1 && maps->map_3d[i + 1][j] < maps->map_3d[i][j] - 4) {
                    ++maps->map_3d[i + 1][j];
                    check = true;
                }
                if (j > 0 && maps->map_3d[i][j - 1] < maps->map_3d[i][j] - 4) {
                    ++maps->map_3d[i][j - 1];
                    check = true;
                }
                if (j < maps->size.y - 1 && maps->map_3d[i][j + 1] < maps->map_3d[i][j] - 4) {
                    ++maps->map_3d[i][j + 1];
                    check = true;
                }
            }

            else if (all_events->mouse.right) {
                if (i > 0 && maps->map_3d[i - 1][j] > maps->map_3d[i][j] + 4) {
                    --maps->map_3d[i - 1][j];
                    check = true;
                }
                if (i < maps->size.x - 1 && maps->map_3d[i + 1][j] > maps->map_3d[i][j] + 4) {
                    --maps->map_3d[i + 1][j];
                    check = true;
                }
                if (j > 0 && maps->map_3d[i][j - 1] > maps->map_3d[i][j] + 4) {
                    --maps->map_3d[i][j - 1];
                    check = true;
                }
                if (j < maps->size.y - 1 && maps->map_3d[i][j + 1] > maps->map_3d[i][j] + 4) {
                    --maps->map_3d[i][j + 1];
                    check = true;
                }
            }
        }
    }
    return (check);
}

void parse_to_get_point(map_t *maps, sfVector2i pos, bool up)
{
    int radius = maps->radius;

    for (int i = 0; i < maps->size.x; ++i) {
        for (int j = 0; j < maps->size.y; ++j) {
            if (((int)maps->map_2d[i][j].iso.x > pos.x - radius && (int)maps->map_2d[i][j].iso.x < pos.x + radius)
            && ((int)maps->map_2d[i][j].iso.y > pos.y - radius && (int)maps->map_2d[i][j].iso.y < pos.y + radius))
                if (up)
                    ++maps->map_3d[i][j];
                else
                    maps->map_3d[i][j] > -49 ? --maps->map_3d[i][j] : 0;
        }
    }
}

void move_map(events_t *all_events, map_t *maps)
{
// rotate
    if (all_events->left)
        --maps->angle.x;
    if (all_events->right)
        ++maps->angle.x;
    if (all_events->down)
        --maps->angle.y;
    if (all_events->up)
        ++maps->angle.y;

// zoom
    if (all_events->page_down && maps->zoom > 0)
        --maps->zoom;
    if (all_events->page_up)
        ++maps->zoom;

// translate
    if (all_events->z)
        maps->pos.y -= 5;
    if (all_events->s)
        maps->pos.y += 5;
    if (all_events->q)
        maps->pos.x -= 5;
    if (all_events->d)
        maps->pos.x += 5;

    if (all_events->p)
        ++maps->radius;
    if (all_events->m)
        --maps->radius;

// wheel
    if (all_events->ctrl && all_events->mouse_wheel.up)
        ++maps->zoom;
    else if (all_events->mouse_wheel.up)
        maps->radius += 8;
    if (all_events->ctrl && all_events->mouse_wheel.down)
        --maps->zoom;
    else if (all_events->mouse_wheel.down)
        maps->radius -= 8;

    if (all_events->ctrl && all_events->mouse.move_x && all_events->mouse_wheel.click)
        maps->pos.x -= all_events->mouse.move_x;
    if (all_events->ctrl && all_events->mouse.move_y && all_events->mouse_wheel.click)
        maps->pos.y -= all_events->mouse.move_y;
    if (!all_events->ctrl && all_events->mouse.move_x && all_events->mouse_wheel.click)
        maps->angle.x += all_events->mouse.move_x / 2;

    if (all_events->space) {
        // print_int_array(maps->map_3d, maps->size);
        free_int_array(maps->map_3d);
        maps->map_3d = int_array_dup(maps->backup, maps->size);
    }

// modify
    if (all_events->mouse.left) {
        parse_to_get_point(maps, all_events->mouse.pos, true);
    }
    if (all_events->mouse.right) {
        parse_to_get_point(maps, all_events->mouse.pos, false);
    }

    bool check = true;
    while (check)
        check = check_incidence(maps, all_events);

}

void check_click_button(events_t *all_events, spritesheet_t *spritesheet)
{
    sfFloatRect collision;

    for (int i = 0; all_events->mouse.left && i < NBR_SPRITE; ++i) {
        if (spritesheet[i].active) {
            collision = sfSprite_getGlobalBounds(spritesheet[i].sprite);
            if (all_events->mouse.pos.x > collision.left && all_events->mouse.pos.x < collision.left + collision.width
            && all_events->mouse.pos.y > collision.top && all_events->mouse.pos.y < collision.top + collision.height)
                printf("oui\n"); // FAIRE POINTEUR SUR FONCTION
        }
    }
}

void big_loop(beginning_t *begin, events_t *all_events, map_t *maps,
spritesheet_t *spritesheet)
{
    sfColor color = sfBlack;

    color.a = 100;
    clean_window(begin, sfBlack);
    my_events(begin, all_events);

    if (begin->screen.world) {
        move_map(all_events, maps);
        create_2d_map(maps, maps->size);
        draw_2d_map(begin, maps);
        my_draw_circle(begin->framebuffer, all_events->mouse.pos, maps->radius, color);
    } else
        check_click_button(all_events, spritesheet);


    sfSprite_setTexture(begin->sprite, begin->texture, sfFalse);
    sfTexture_updateFromPixels(begin->texture,
        begin->framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(begin->window,
        begin->sprite, NULL);

    if (!begin->screen.world) {
        main_menu(begin, spritesheet);
    }

    sfRenderWindow_display(begin->window);
}

void my_world(bool map, sfVector2i size, char *filepath)
{
    beginning_t begin;
    spritesheet_t *spritesheet = malloc(sizeof(spritesheet_t) * NBR_SPRITE);
    events_t all_events = {.left = false, .right = false, .up = false, .down = false, .page_up = false, .page_down = false, .z = false, .s = false, .q = false, .d = false, .p = false, .m = false, .escape = false, .space = false, .ctrl = false, .mouse = {.left = false, .right = false, .move_x = 0, .move_y = 0, .pos = {0, 0}}, .mouse_wheel = {.up = false, .down = false, .click = false}};
    map_t maps = {.map_2d = NULL, .map_3d = NULL, .backup = NULL, .size = size, .angle = {0, 0}, .pos = {POS_X, POS_Y}, .zoom = ZOOM, .radius = 50};

    map ? open_map(&maps, filepath) : create_3d_map(&maps, size);
    maps.map_2d = malloc(sizeof(point_t *) * maps.size.x);
    for (int i = 0; i < maps.size.x; ++i)
        maps.map_2d[i] = malloc(sizeof(point_t) * maps.size.y);

    maps.backup = int_array_dup(maps.map_3d, maps.size);

    all_beginning(&begin);
    inits_obj(spritesheet, &begin);
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
