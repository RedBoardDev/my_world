/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** button.c
*/

int check_button(game_object_t obj, sfEvent event)
{
    if(event.mouseButton.x > obj.pos.x &&
        event.mouseButton.x < obj.pos.x + obj.rect.width &&
        event.mouseButton.y > obj.pos.y &&
        event.mouseButton.y < obj.pos.y + obj.rect.height)
        return (1);
    return (0);
}
