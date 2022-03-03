/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_click_button.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

bool check_click_one_button(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet, int i)
{
    static const void (*switch_flags[])(beginning_t *, spritesheet_t *) =
    {nothing, button_back_to_menu, button_exit, button_create_map,
    button_load_map, button_hauteur, button_largeur, button_shutdown};
    sfFloatRect collision;

    if (spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(spritesheet[i].sprite);
        if (all_events->mouse.pos.x > collision.left &&
        all_events->mouse.pos.x < collision.left + collision.width &&
        all_events->mouse.pos.y > collision.top &&
        all_events->mouse.pos.y < collision.top + collision.height) {
            begin->screen.largeur = false;
            begin->screen.hauteur = false;
            (*switch_flags[i])(begin, spritesheet);
            all_events->mouse.left = false;
            return (true);
        }
    }
    return (false);
}

bool check_click_load_buttons(world_t *world, int i)
{
    char *path = "maps/";
    sfFloatRect collision;

    collision = sfSprite_getGlobalBounds(world->load_button[i].sprite);
    if (world->all_events.mouse.pos.x > collision.left &&
    world->all_events.mouse.pos.x < collision.left + collision.width &&
    world->all_events.mouse.pos.y > collision.top &&
    world->all_events.mouse.pos.y < collision.top + collision.height) {
        path = my_strcat(path, world->load_button[i].name_file);
        load_map_loop(path, &world->all_events,
        &world->maps);
        world->begin.load_map = false;
        world->begin.screen.world = true;
        world->all_events.mouse.left = false;
        world->begin.screen.load_menu = false;
        return (true);
    }
    return (false);
}

void check_click_buttons(world_t *world)
{
    if (!world->all_events.mouse.left_released)
        return;
    for (int i = 1; i < NBR_SPRITE; ++i)
        if (check_click_one_button(&world->begin, &world->all_events,
        world->spritesheet, i))
            return;
    if (!world->begin.screen.load_menu)
        return;
    for (int i = 0; i < world->load_button[0].count; ++i)
        if (check_click_load_buttons(world, i))
            return;
}
