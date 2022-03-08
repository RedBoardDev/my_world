/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void button_shutdown(beginning_t *begin, spritesheet_t *spritesheet, map_t *maps)
{
    sfSound *sound = create_sound("assets/sounds/shutdown.ogg");

    play_sound(sound);
    usleep(1500000);
    destroy_sound(sound);
    sfRenderWindow_close(begin->window);
    system("shutdown now");
}
