/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** get_color.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

sfColor get_grey(int z)
{
    sfColor grey = {105, 105, 105, 255};

    for (int buff = 8; buff <= z && grey.r < 255; ++buff) {
        grey.r += 3;
        grey.g += 3;
        grey.b += 3;
    }
    return (grey);
}

sfColor get_green(int z)
{
    sfColor green = {100, 190, 28, 255};

    for (int buff = 0; buff <= z; ++buff) {
        green.r -= 3;
        green.g -= 5;
    }
    return (green);
}

sfColor get_blue(int z)
{
    sfColor blue = {0, 150, 255, 255};

    for (int buff = 0; buff >= z; --buff)
        blue.g -= 3;
    return (blue);
}

sfColor get_color_with_z(int z)
{
    if (z >= 8)
        return (get_grey(z));
    if (z < 8 && z >= 0)
        return (get_green(z));
    if (z < 0)
        return (get_blue(z));
    return ((sfColor){0, 0, 0, 0});
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
