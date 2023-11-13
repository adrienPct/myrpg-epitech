/*
** EPITECH PROJECT, 2022
** on_middle_collision.c
** File description:
** check midle colision
*/

#include "graphic_lib.h"

int on_middle_collision(obj_t object1, obj_t object2)
{
    if (object1.collider.middle.x == object2.collider.middle.x 
    && object1.collider.middle.y == object2.collider.middle.y)
        return 1;
    return 0;
}