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
    spritesheet->pos = init_sprite.pos;
    spritesheet->rect = init_sprite.rect;
    spritesheet->sprite = sfSprite_create();
    spritesheet->texture = sfTexture_createFromFile(filename, NULL);

    sfSprite_setScale(spritesheet->sprite, init_sprite.scale);
    sfSprite_setTexture(spritesheet->sprite, spritesheet->texture, sfFalse);
    sfSprite_setTextureRect(spritesheet->sprite, spritesheet->rect);
    sfSprite_setPosition(spritesheet->sprite, spritesheet->pos);
    sfSprite_setOrigin(spritesheet->sprite, (sfVector2f){init_sprite.rect.width
    / 2, init_sprite.rect.height / 2});
}

void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_sprite("assets/img/background.png", &spritesheet[S_BACKGROUND], begin,
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080}});
    set_sprite("assets/img/back_to_menu.png", &spritesheet[S_BACK_MENU], begin,
    (init_sprite_t){{1400, (HEIGHT / 4) * 3}, {0.2, 0.2}, {0, 0, 1170, 541}});
    set_sprite("assets/img/exit.png", &spritesheet[S_EXIT], begin,
    (init_sprite_t){{1400, (HEIGHT / 4) * 3}, {0.2, 0.2}, {0, 0, 1170, 541}});
    set_sprite("assets/img/create_map.png", &spritesheet[S_CREATE_MAP], begin,
    (init_sprite_t){{1400, HEIGHT / 4}, {0.2, 0.2}, {0, 0, 1783, 541}});
    set_sprite("assets/img/load_map.png", &spritesheet[S_LOAD_MAP], begin,
    (init_sprite_t){{1400, HEIGHT / 2}, {0.2, 0.2}, {0, 0, 1783, 541}});
    set_sprite("assets/img/hauteur.png", &spritesheet[S_HAUTEUR], begin,
(init_sprite_t){{1400, (HEIGHT / 4) * 2.3}, {0.2, 0.2}, {0, 0, 2000, 541}});
    set_sprite("assets/img/largeur.png", &spritesheet[S_LARGEUR], begin,
    (init_sprite_t){{1400, (HEIGHT / 4) * 1.7}, {0.2, 0.2}, {0, 0, 2000, 541}});
    set_sprite("assets/img/shutdown.png", &spritesheet[S_SHUTDOWN], begin,
    (init_sprite_t){{WIDTH - 40, 40}, {0.5, 0.5}, {0, 0, 88, 88}});
}
