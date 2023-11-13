/*
** EPITECH PROJECT, 2022
** draw_inventory.c
** File description:
** draw_inventory
*/

#include "rpg.h"

void draw_inventory(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.window, game->play.inventory.inv_font.sprite, NULL);
    for (int i = 5; i != 11; i++) {
        if (INVENTORY.is_empty[i] == false)
            sfRenderWindow_drawSprite(game->win.window, INVENTORY.slots[i].sprite, NULL);
    }
}