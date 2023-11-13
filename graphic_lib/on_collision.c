/*
** EPITECH PROJECT, 2022
** on_collision.c
** File description:
** return 1 if 2 object are in collision
*/

#include "graphic_lib.h"

int on_collision(obj_t object1, obj_t object2)
{
    if (object1.collider.right >= object2.collider.left 
    && object1.collider.left <= object2.collider.right 
    && object1.collider.top <= object2.collider.bot 
    && object1.collider.bot >= object2.collider.top)
        return 1;
    return 0;
}