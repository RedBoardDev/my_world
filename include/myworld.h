/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** myworld.h
*/

#ifndef MY_WORLD_H
    #define MY_WORLD_H

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/PrimitiveType.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <math.h>
    #include "struct.h"
    #define PI 3.14159265359
    #define RADIAN(x) x * PI / 180
    #define SIZE 100
    #define MIN 0
    #define MAX 1
    #define POS_X WIDTH / 2
    #define POS_Y HEIGHT / 2
    #define ZOOM 10

enum a {
    S_BACKGROUND,
    S_BACK_TO_MENU,
    S_EXIT,
    S_CREATE_MAP,
    S_LOAD_MAP,
    S_HAUTEUR,
    S_LARGEUR,
    S_SHUTDOWN,
    NBR_SPRITE
};

// EVENTS
void my_events(beginning_t *begin, events_t *all_events);
void events_key_pressed(beginning_t *begin, sfEvent event, events_t *all_events);
void events_key_released(sfEvent event, events_t *all_events);
void events_mouse_pressed(beginning_t *begin, sfEvent event, events_t *all_events);
void events_mouse_released(beginning_t *begin, sfEvent event, events_t *all_events);
void events_scroll_wheel(sfEvent event, events_t *all_events);
void event_mouse_moved(sfEvent event, events_t *all_events);
void events_write_largeur(beginning_t *begin, sfEvent event, events_t *all_events);

// INTERFACE
// functions pointers
void button_create_map(beginning_t *begin, spritesheet_t *spritesheet);
void button_load_map(beginning_t *begin, spritesheet_t *spritesheet);
void button_exit(beginning_t *begin, spritesheet_t *spritesheet);
void button_back_to_menu(beginning_t *begin, spritesheet_t *spritesheet);
void nothing(beginning_t *begin, spritesheet_t *spritesheet);
void button_shutdown(beginning_t *begin, spritesheet_t *spritesheet);
void button_hauteur(beginning_t *begin, spritesheet_t *spritesheet);
void button_largeur(beginning_t *begin, spritesheet_t *spritesheet);
// put menu
void main_menu(beginning_t *begin, spritesheet_t *spritesheet);
// check click button
void check_click_button(beginning_t *begin, events_t *all_events, spritesheet_t *spritesheet);
// init spritesheets
void inits_obj(spritesheet_t *spritesheet, beginning_t *begin);

// MAP
// create map begin
void create_3d_map(map_t *maps, sfVector2i size);
void open_map(map_t *maps, char *filepath);
// create quad
void create_quad(beginning_t *begin, my_quad_t quad, int angle);
// draw map
void draw_2d_map(beginning_t *begin, map_t *maps);
// events map
void exec_events_map(events_t *all_events, map_t *maps);
// re create map
void create_2d_map(map_t *maps, sfVector2i size);
// transform map
bool check_incidence(map_t *maps, events_t *all_events);
void parse_to_get_point(map_t *maps, sfVector2i pos, bool up);

// draw simple
void my_draw_circle(sfUint8 *framebuffer, sfVector2i center, int radius,
sfColor color);
void my_draw_rectangle(sfUint8 *framebuffer, unsigned int x, unsigned int y,
sfColor color);
void my_draw_line(sfUint8 *framebuffer, sfVector2i point_a, sfVector2i point_b,
sfColor color);
void my_draw_square(sfUint8 *framebuffer, unsigned int size, sfColor color);
void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color);

// int array utils
int **int_array_dup(int **arr, sfVector2i size);
void print_int_array(int **arr, sfVector2i size);
void free_int_array(int **arr);

// myworld
void my_world(bool map, sfVector2i size, char *filepath);

// utils
void clean_window(beginning_t *begin, sfColor color);
void all_beginning(beginning_t *beginning);
void destroy_all(beginning_t *begin);
int my_rand(int min, int max);

#endif
