/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <math.h>

enum size_window {
    WIDTH = 1920,
    HEIGHT = 1080
};

typedef struct screen_s {
    bool main_menu;
    bool create_menu;
    bool load_menu;
    bool world;
    bool hauteur;
    bool largeur;
} screen_t;

typedef struct beginning_s {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    screen_t screen;
    bool init_map;
    bool load_map;
    bool get_file;
} beginning_t;

typedef struct mouse_s {
    bool left;
    bool left_released;
    bool right;
    int move_x;
    int move_y;
    sfVector2i pos;
} mouse_t;

typedef struct mouse_wheel_s {
    bool up;
    bool down;
    bool click;
} mouse_wheel_t;

typedef struct events_s {
    bool left;
    bool right;
    bool up;
    bool down;
    bool page_up;
    bool page_down;
    bool z;
    bool s;
    bool q;
    bool d;
    bool p;
    bool m;
    bool escape;
    bool space;
    bool ctrl;
    bool tab;
    bool enter;
    mouse_t mouse;
    mouse_wheel_t mouse_wheel;
    char *hauteur;
    char *largeur;
} events_t;

typedef struct vector_3i_s {
    int x;
    int y;
    int z;
} vector_3i_t;

typedef struct point_s {
    sfVector2f iso;
    vector_3i_t coords;
} point_t;

typedef struct map_s {
    point_t **map_2d;
    point_t **backup_2d;
    int **map_3d;
    int **backup_3d;
    sfVector2i size;
    sfVector2i angle;
    sfVector2i pos;
    int zoom;
    int radius;
} map_t;

typedef struct my_quad_s {
    point_t a;
    point_t b;
    point_t c;
    point_t d;
} my_quad_t;

typedef struct spritesheet_s {
    bool active;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
} spritesheet_t;

typedef struct load_button_s {
    bool active;
    char *name_file;
    int count;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
} load_button_t;

typedef struct init_sprite_s {
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
} init_sprite_t;

typedef struct world_s {
    map_t maps;
    beginning_t begin;
    events_t all_events;
    spritesheet_t *spritesheet;
    load_button_t *load_button;
} world_t;

#endif
