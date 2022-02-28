/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** create_quad.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

sfColor get_color_with_z(int z)
{
    sfColor blue = {0, 150, 255, 255};
    sfColor green = {100, 190, 28, 255};
    sfColor grey = {105, 105, 105, 255};
    sfColor white = {255, 255, 255, 255};
    sfColor color;

    if (z >= 8) {
        color = grey;
        for (int buff = 8; buff <= z && color.r < 255; ++buff) {
            color.r += 3;
            color.g += 3;
            color.b += 3;
        }
        return (color);
    } else if (z < 8 && z >= 0) {
        color = green;
        for (int buff = 0; buff <= z; ++buff) {
            color.r -= 3;
            color.g -= 5;
        }
        return (color);
    } else if (z < 0) {
        color = blue;
        for (int buff = 0; buff >= z; --buff) {
            color.g -= 3;
        }
        return (color);
    }
}

sfColor get_color(my_quad_t quad, int angle)
{
    sfColor color;

    if (angle % 360 >= 315 && angle % 360 <= 360 || angle % 360 >= 0 && angle % 360 < 45) {
        color = get_color_with_z(quad.a.coords.z);
        color.a = (quad.a.coords.x % 2 == 0 && quad.a.coords.y % 2 == 0) ? color.a - 6 : (quad.a.coords.x % 2 == 1 && quad.a.coords.y % 2 == 1) ? color.a - 3 : color.a;
    } else if (angle % 360 >= 45 && angle % 360 < 135) {
        color = get_color_with_z(quad.b.coords.z);
        color.a = (quad.b.coords.x % 2 == 0 && quad.b.coords.y % 2 == 0) ? color.a - 6 : (quad.b.coords.x % 2 == 1 && quad.b.coords.y % 2 == 1) ? color.a - 3 : color.a;
    } else if (angle % 360 >= 135 && angle % 360 < 225) {
        color = get_color_with_z(quad.d.coords.z);
        color.a = (quad.d.coords.x % 2 == 0 && quad.d.coords.y % 2 == 0) ? color.a - 6 : (quad.d.coords.x % 2 == 1 && quad.d.coords.y % 2 == 1) ? color.a - 3 : color.a;
    } else if (angle % 360 >= 225 && angle % 360 < 315) {
        color = get_color_with_z(quad.c.coords.z);
        color.a = (quad.c.coords.x % 2 == 0 && quad.c.coords.y % 2 == 0) ? color.a - 6 : (quad.c.coords.x % 2 == 1 && quad.c.coords.y % 2 == 1) ? color.a - 3 : color.a;
    }
    return (color);
}

void create_quad(beginning_t *begin, my_quad_t quad, int angle)
{
    sfColor color = get_color(quad, angle);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = quad.a.iso, .color = color};
    sfVertex vertex2 = {.position = quad.b.iso, .color = color};
    sfVertex vertex3 = {.position = quad.c.iso, .color = color};
    sfVertex vertex4 = {.position = quad.d.iso, .color = color};
    if (angle % 360 >= 315 && angle % 360 <= 360 || angle % 360 >= 0 && angle % 360 < 45) {
        sfVertexArray_append(vertex_array, vertex1);
        sfVertexArray_append(vertex_array, vertex2);
        sfVertexArray_append(vertex_array, vertex4);
        sfVertexArray_append(vertex_array, vertex3);
    } else if (angle % 360 >= 45 && angle % 360 < 135) {
        sfVertexArray_append(vertex_array, vertex3);
        sfVertexArray_append(vertex_array, vertex1);
        sfVertexArray_append(vertex_array, vertex2);
        sfVertexArray_append(vertex_array, vertex4);
    } else if (angle % 360 >= 135 && angle % 360 < 225) {
        sfVertexArray_append(vertex_array, vertex4);
        sfVertexArray_append(vertex_array, vertex3);
        sfVertexArray_append(vertex_array, vertex1);
        sfVertexArray_append(vertex_array, vertex2);
    } else if (angle % 360 >= 225 && angle % 360 < 315) {
        sfVertexArray_append(vertex_array, vertex3);
        sfVertexArray_append(vertex_array, vertex1);
        sfVertexArray_append(vertex_array, vertex2);
        sfVertexArray_append(vertex_array, vertex4);
    }
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(begin->window, vertex_array, NULL);
}
