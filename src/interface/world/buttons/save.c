/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** save.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_write_filename(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    begin->text.filename_save_b = begin->text.filename_save_b ? false : true;
}

void button_save_window(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    char *filename = my_strcat(my_strcat("maps/", begin->text.filename_save),
    ".myw");
    begin->text.filename_save_b = false;
    begin->save_file = false;
    save_file(filename, maps);
}

void button_cancel_window(beginning_t *begin, spritesheet_t *spritesheet,
map_t *maps)
{
    begin->text.filename_save_b = false;
    begin->save_file = false;
}
