/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** get_color_with_z.c
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