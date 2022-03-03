/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** draw_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

// void create_v_array_sides(beginning_t *begin, int angle)
// {
//     sfColor color = {135, 81, 23, 255};
//     sfVertexArray *vertex_array = sfVertexArray_create();
//     sfVertex vertex1 = {.position = quad.a.iso, .color = color};
//     sfVertex vertex2 = {.position = quad.b.iso, .color = color};
//     sfVertex vertex3 = {.position = quad.c.iso, .color = color};
//     sfVertex vertex4 = {.position = quad.d.iso, .color = color};

//     sfVertexArray_append(vertex_array, vertex1);
//     sfVertexArray_append(vertex_array, vertex2);
//     sfVertexArray_append(vertex_array, vertex4);
//     sfVertexArray_append(vertex_array, vertex3);

//     if ((angle % 360 >= 315 && angle % 360 <= 360) ||
//     (angle % 360 >= 0 && angle % 360 < 45))
//         vertex_array = append_array1(color, quad);
//     if (angle % 360 >= 45 && angle % 360 < 135)
//         vertex_array = append_array2(color, quad);
//     if (angle % 360 >= 135 && angle % 360 < 225)
//         vertex_array = append_array3(color, quad);
//     if (angle % 360 >= 225 && angle % 360 < 315)
//         vertex_array = append_array4(color, quad);
//     sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
//     sfRenderWindow_drawVertexArray(begin->window, vertex_array, NULL);
//     sfVertexArray_destroy(vertex_array);
// }

void draw_2d_map_1(beginning_t *begin, map_t *maps)
{
    my_quad_t quad;
    point_t buff;

    quad.a = maps->map_2d[0][0];
    quad.b = maps->map_2d[maps->size.x - 1][0];
    quad.c = maps->map_2d[0][maps->size.y - 1];
    quad.d = maps->map_2d[maps->size.x - 1][maps->size.y - 1];
    create_quad(begin, quad, maps->angle.x);
    for (int i = 0; i < maps->size.x; ++i)
        for (int j = 0; j < maps->size.y; ++j) {
            quad.a = (j < maps->size.y - 1) ? maps->map_2d[i][j] : buff;
            quad.b = (j < maps->size.y - 1) ? maps->map_2d[i][j + 1] : buff;
            quad.c = (i < maps->size.x - 1) ? maps->map_2d[i + 1][j] : buff;
            quad.d = (i < maps->size.x - 1 && j < maps->size.y - 1) ?
            maps->map_2d[i + 1][j + 1] : buff;
            (i < maps->size.x - 1 && j < maps->size.y - 1) ?
            create_quad(begin, quad, maps->angle.x) : 0;
        }
}

void draw_2d_map_2(beginning_t *begin, map_t *maps)
{
    my_quad_t quad;
    point_t buff;

    quad.b = maps->map_2d[0][0];
    quad.a = maps->map_2d[maps->size.x - 1][0];
    quad.d = maps->map_2d[0][maps->size.y - 1];
    quad.c = maps->map_2d[maps->size.x - 1][maps->size.y - 1];
    create_quad(begin, quad, maps->angle.x);
    for (int i = 0; i < maps->size.x; ++i)
        for (int j = maps->size.y - 1; j >= 0; --j) {
            quad.a = (j > 0) ? maps->map_2d[i][j] : buff;
            quad.b = (j > 0) ? maps->map_2d[i][j - 1] : buff;
            quad.c = (i < maps->size.x - 1) ? maps->map_2d[i + 1][j] : buff;
            quad.d = (i < maps->size.x - 1 && j > 0) ?
            maps->map_2d[i + 1][j - 1] : buff;
            (i < maps->size.x - 1 && j > 0) ?
            create_quad(begin, quad, maps->angle.x) : 0;
        }
}

void draw_2d_map_3(beginning_t *begin, map_t *maps)
{
    my_quad_t quad;
    point_t buff;

    quad.b = maps->map_2d[0][0];
    quad.d = maps->map_2d[maps->size.x - 1][0];
    quad.a = maps->map_2d[0][maps->size.y - 1];
    quad.c = maps->map_2d[maps->size.x - 1][maps->size.y - 1];
    create_quad(begin, quad, maps->angle.x);
    for (int i = maps->size.x - 1; i >= 0; --i)
        for (int j = maps->size.y - 1; j >= 0; --j) {
            quad.a = (j > 0) ? maps->map_2d[i][j] : buff;
            quad.b = (j > 0) ? maps->map_2d[i][j - 1] : buff;
            quad.c = (i > 0) ? maps->map_2d[i - 1][j] : buff;
            quad.d = (i > 0 && j > 0) ? maps->map_2d[i - 1][j - 1] : buff;
            (i > 0 && j > 0) ? create_quad(begin, quad, maps->angle.x) : 0;
        }
}

void draw_2d_map_4(beginning_t *begin, map_t *maps)
{
    my_quad_t quad;
    point_t buff;

    quad.b = maps->map_2d[0][0];
    quad.a = maps->map_2d[maps->size.x - 1][0];
    quad.d = maps->map_2d[0][maps->size.y - 1];
    quad.c = maps->map_2d[maps->size.x - 1][maps->size.y - 1];
    create_quad(begin, quad, maps->angle.x);
    for (int i = maps->size.x - 1; i >= 0; --i)
        for (int j = 0; j < maps->size.y; ++j) {
            quad.a = (j < maps->size.y - 1) ? maps->map_2d[i][j] : buff;
            quad.b = (j < maps->size.y - 1) ? maps->map_2d[i][j + 1] : buff;
            quad.c = (i > 0) ? maps->map_2d[i - 1][j] : buff;
            quad.d = (i > 0 && j < maps->size.y - 1) ?
            maps->map_2d[i - 1][j + 1] : buff;
            (i > 0 && j < maps->size.y - 1) ?
            create_quad(begin, quad, maps->angle.x) : 0;
        }
}

void draw_2d_map(beginning_t *begin, map_t *maps)
{
    if (maps->angle.x < 0)
        maps->angle.x = 360;
    if ((maps->angle.x % 360 >= 315 && maps->angle.x % 360 <= 360) ||
    (maps->angle.x % 360 >= 0 && maps->angle.x % 360 < 45))
        draw_2d_map_1(begin, maps);
    if (maps->angle.x % 360 >= 45 && maps->angle.x % 360 < 135)
        draw_2d_map_2(begin, maps);
    if (maps->angle.x % 360 >= 135 && maps->angle.x % 360 < 225)
        draw_2d_map_3(begin, maps);
    if (maps->angle.x % 360 >= 225 && maps->angle.x % 360 < 315)
        draw_2d_map_4(begin, maps);
}
