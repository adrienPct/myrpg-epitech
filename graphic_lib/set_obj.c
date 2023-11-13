/*
** EPITECH PROJECT, 2022
** set_obj.c
** File description:
** set an object
*/

#include "graphic_lib.h"

void set_obj(obj_t *object, char *text_path, sfVector2f pos, sfIntRect rect)
{
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(text_path, NULL);
    object->pos = pos;
    object->start_pos = pos;
    object->rect = rect;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setPosition(object->sprite, object->pos);
}
