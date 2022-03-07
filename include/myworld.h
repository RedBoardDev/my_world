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
    #define RADIAN(x) x * 3.14159265359 / 180
    #define POS_X WIDTH / 2
    #define POS_Y HEIGHT / 2

enum params {
    MIN = 0,
    MAX = 1,
    ZOOM = 10,
    SIZE = 100
};

enum sprites {
    S_BACKGROUND,
    S_BACK_MENU,
    S_EXIT,
    S_CREATE_MAP,
    S_LOAD_MAP,
    S_HAUTEUR,
    S_LARGEUR,
    S_SHUTDOWN,
    S_ARROW_DOWN,
    S_ARROW_LEFT,
    S_ARROW_RIGHT,
    S_ARROW_UP,
    S_CHANGE_PAINTER,
    S_HOME,
    S_ROTATE_360,
    S_SAVE,
    S_TOGGLE_MOVE,
    S_TOGGLE_ROTATE,
    S_ROTATE_LEFT,
    S_ROTATE_RIGHT,
    S_ROTATE_DOWN,
    S_ROTATE_UP,
    NBR_SPRITE
};

// EVENTS
void my_events(beginning_t *begin, events_t *all_events);
void events_key_pressed(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_key_released(sfEvent event, events_t *all_events);
void events_mouse_pressed(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_mouse_released(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_scroll_wheel(sfEvent event, events_t *all_events);
void event_mouse_moved(sfEvent event, events_t *all_events);
void events_write_largeur(beginning_t *begin, sfEvent event,
events_t *all_events);

// INTERFACE
// functions pointers
void button_create_map(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_load_map(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_exit(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_back_to_menu(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void nothing(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_shutdown(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_hauteur(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_largeur(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_arrow_down(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_arrow_left(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_arrow_right(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_arrow_up(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_painter(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_home(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_rotate_360(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_save(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_toggle_move(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_toggle_rotate(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_rotate_left(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_rotate_right(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps);
void button_rotate_up(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps);
void button_rotate_down(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps);
// put menu
void put_all_spritesheets(beginning_t *begin, spritesheet_t *spritesheet,
load_button_t *load_button);
// check click button
void check_click_buttons(world_t *world);
void check_mouse_on_all_buttons(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet, load_button_t *load_button);
// init spritesheets
void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin);
// utils spritesheets
void set_one_sprite(char *filename, spritesheet_t *spritesheet, beginning_t *begin,
init_sprite_t init_sprite);

// MAP
// create map begin
void create_3d_map(map_t *maps, sfVector2i size);
void open_map(map_t *maps, char *filepath);
int **malloc_int_array(map_t *maps);
void load_map_runtime(char *filepath, events_t *all_events, map_t *maps);
void check_limit_translation_map(map_t *maps, events_t *all_events);
// create quad
void create_quad(beginning_t *begin, my_quad_t quad, int angle);
// draw map
void draw_2d_map(beginning_t *begin, map_t *maps);
// events map
void exec_events_map(events_t *all_events, map_t *maps);
// get color
sfColor get_color(my_quad_t quad, int angle);
sfColor get_color_with_z(int z);
// re create map
void create_2d_map(map_t *maps, sfVector2i size);
// transform map
bool check_incidence(map_t *maps, events_t *all_events);
void increase_decrease_points_mouse(map_t *maps, sfVector2i pos, bool up);
void increase_decrease_points_zero(map_t *maps, sfVector2i pos_mouse, bool up);
int get_highest_point(int a, int b, int c, int d);
void init_empty_map_with_size(events_t *all_events, map_t *maps);
void init_display_folder_with_maps(world_t *world);

// draw simple
void my_draw_circle(sfUint8 *framebuffer, sfVector2i center, int radius,
sfColor color);
void my_draw_rectangle(sfUint8 *framebuffer, sfIntRect rect, sfColor color);
void my_draw_line(sfUint8 *framebuffer, sfVector2i point_a, sfVector2i point_b,
sfColor color);
void my_draw_square(sfUint8 *framebuffer, unsigned int size, sfColor color);
void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color);

// init all
void init_all(beginning_t *begin, map_t *maps, spritesheet_t *spritesheet,
bool init_map);
events_t init_all_events(void);
map_t init_maps_begin(sfVector2i size);

// int array utils
int **int_array_dup(int **arr, sfVector2i size);
void print_int_array(int **arr, sfVector2i size);
void free_int_array(int **arr, int size);

// load / save file
void save_file(char *filepath, map_t *maps);
void load_file(char *filepath, map_t *maps);

// myworld
void my_world(bool map, sfVector2i size, char *filepath);
void init_map(events_t *all_events, map_t *maps);

// utils
void clean_window(beginning_t *begin, sfColor color);
void init_csfml(beginning_t *beginning);
void destroy_all(beginning_t *begin);
int my_rand(int min, int max);
bool check_mouse_on_one_button(sfVector2i pos, sfFloatRect collision);
void draw_one_sprite(beginning_t *begin, sfSprite *sprite, sfIntRect rect,
sfVector2f pos);

void put_text_imput(beginning_t *begin, events_t *all_events);
void write_text(beginning_t *begin, text_t struct_text);
void events_write_hauteur(beginning_t *begin, sfEvent event,
events_t *all_events);
load_button_t *init_open_folder_maps(beginning_t *begin);

#endif
