/*
** EPITECH PROJECT, 2022
** check_col64.c
** File description:
** check_col64
*/

#include "rpg.h"

int check_col64(obj_t *obj, map_col_t *colliders)
{
    for (int i = 0; i != colliders->size; i++) {
        if (obj->collider.right >= colliders->colliders[i].x
         && obj->collider.left <= colliders->colliders[i].x + 64
         && obj->collider.top <= colliders->colliders[i].y + 64
         && obj->collider.bot >= colliders->colliders[i].y)
            return 1;
    }
    return 0;
}