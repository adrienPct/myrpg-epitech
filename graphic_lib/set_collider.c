/*
** EPITECH PROJECT, 2022
** set_collider.c
** File description:
** set collider
*/

#include "graphic_lib.h"

void set_collider(obj_t *object, float height, float width)
{
    object->collider.height = height;
    object->collider.width = width;
    object->collider.top = object->pos.y;
    object->collider.bot = object->pos.y + height;
    object->collider.right = object->pos.x + width;
    object->collider.left = object->pos.x;
    object->collider.middle.x = object->pos.x + (width / 2);
    object->collider.middle.y = object->pos.y + (height / 2);
}