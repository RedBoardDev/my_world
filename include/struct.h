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

    #define WIDTH 1920
    #define HEIGHT 1080

typedef struct beginning_s {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
} beginning_t;

typedef struct mouse_s {
    bool left;
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
    mouse_t mouse;
    mouse_wheel_t mouse_wheel;
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
    int **map_3d;
    int **backup;
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

#endif
