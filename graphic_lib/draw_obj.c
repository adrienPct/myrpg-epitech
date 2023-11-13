/*
** EPITECH PROJECT, 2022
** draw_obj.c
** File description:
** draw_obj
*/

#include "graphic_lib.h"

void draw_obj(sfRenderWindow *window, obj_tab_t objects)
{
    for (int i = 0; i != objects.size; i++) {
        sfSprite_setTexture(objects.tab[i].sprite, objects.tab[i].texture, sfTrue);
        if (objects.tab[i].rect.height != 0)
            sfSprite_setTextureRect(objects.tab[i].sprite, objects.tab[i].rect);
        sfSprite_setPosition(objects.tab[i].sprite, objects.tab[i].pos);
        sfRenderWindow_drawSprite(window, objects.tab[i].sprite, NULL);
    }
}