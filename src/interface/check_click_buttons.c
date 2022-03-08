/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_click_button.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

bool check_click_one_button(world_t *world, int i)
{
    static const void (*functions[])(beginning_t *, spritesheet_t *, map_t *) =
    {nothing, nothing, button_back_to_menu, button_exit, button_create_map,
    button_load_map, button_hauteur, button_largeur, button_shutdown,
    button_arrow_down, button_arrow_left, button_arrow_right, button_arrow_up,
    button_painter, button_home, button_rotate_360, button_save,
    button_toggle_move, button_toggle_rotate, button_rotate_left,
    button_rotate_right, button_rotate_down, button_rotate_up, nothing,
    button_cancel_window, button_save_window};
    sfFloatRect collision;
    if (world->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(world->spritesheet[i].sprite);
        if (check_mouse_on_one_button(world->all_events.mouse.pos, collision)) {
            world->begin.text.largeur_b = false;
            world->begin.text.hauteur_b = false;
            (*functions[i])(&world->begin, world->spritesheet, &world->maps);
            world->all_events.mouse.left = false;
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
    if (check_mouse_on_one_button(world->all_events.mouse.pos, collision)) {
        path = my_strcat(path, world->load_button[i].name_file);
        load_map_runtime(path, &world->all_events, &world->maps);
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
    for (int i = 2; i < NBR_SPRITE; ++i)
        if (check_click_one_button(world, i))
            return;
    if (!world->begin.screen.load_menu)
        return;
    for (int i = 0; i < world->load_button[0].count; ++i)
        if (check_click_load_buttons(world, i))
            return;
}
