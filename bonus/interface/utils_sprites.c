/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** utils_sprites.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void set_one_sprite(char *filename, spritesheet_t *spritesheet,
beginning_t *begin, init_sprite_t init_sprite)
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

void write_text(beginning_t *begin, text_t struct_text)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("../assets/fonts/droid-sans-bold.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, struct_text.size);
    sfText_setPosition(text, struct_text.pos);
    sfText_setColor(text, struct_text.color);
    sfText_setString(text, struct_text.str);
    sfRenderWindow_drawText(begin->window, text, NULL);
}

void draw_one_sprite(beginning_t *begin, sfSprite *sprite, sfIntRect rect,
sfVector2f pos)
{
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(begin->window, sprite, NULL);
}
