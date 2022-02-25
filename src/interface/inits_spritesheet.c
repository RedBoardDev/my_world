/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** inits_spritesheet.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void set_sprite(char *filename, spritesheet_t *spritesheet, beginning_t *begin,
init_sprite_t init_sprite)
{
    spritesheet->active = false;
    spritesheet->pos.x = init_sprite.pos.x;
    spritesheet->pos.y = init_sprite.pos.y;
    spritesheet->rect.top = init_sprite.rect.top;
    spritesheet->rect.left = init_sprite.rect.left;
    spritesheet->rect.width = init_sprite.rect.width;
    spritesheet->rect.height = init_sprite.rect.height;
    spritesheet->sprite = sfSprite_create();
    sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(spritesheet->sprite, spritesheet->texture, sfFalse);
    sfSprite_setTextureRect(spritesheet->sprite, spritesheet->rect);
}

void inits_obj(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_sprite("ressources/img/back_to_menu.png", &spritesheet[0], begin,(init_sprite_t){{0, 0}, {0, 0, 1170, 541}});
    set_sprite("ressources/img/exit.png", &spritesheet[1], begin, (init_sprite_t){{0, 0}, {0, 0, 1170, 541}});
    set_sprite("ressources/img/create_map.png", &spritesheet[2], begin, (init_sprite_t){{0, 0}, {0, 0, 1783, 541}});
    set_sprite("ressources/img/load_map.png", &spritesheet[3], begin, (init_sprite_t){{0, 0}, {0, 0, 1783, 541}});
    set_sprite("ressources/img/hauteur_largeur.png", &spritesheet[4], begin, (init_sprite_t){{0, 0}, {0, 0, 2000, 541}});
    set_sprite("ressources/img/density.png", &spritesheet[5], begin, (init_sprite_t){{0, 0}, {0, 0, 2000, 541}});
    set_sprite("ressources/img/background.png", &spritesheet[6], begin, (init_sprite_t){{0, 0}, {0, 0, 1920, 1080}});
    set_sprite("ressources/img/density.png", &spritesheet[7], begin, (init_sprite_t){{0, 0}, {0, 0, 1920, 1080}});
}
