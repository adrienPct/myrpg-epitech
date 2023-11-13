/*
** EPITECH PROJECT, 2022
** object_is_col_vector.c
** File description:
** this function return 1 if the object is cliked
*/

#include "graphic_lib.h"

int object_is_col_vector(obj_t object, sfVector2i pos_mouse)
{
    if ((pos_mouse.x >= object.collider.left) 
    && (pos_mouse.x <= object.collider.right) 
    && (pos_mouse.y >= object.collider.top) 
    &&  (pos_mouse.y <= object.collider.bot)) {
        return 1;
    }
    return 0;
}