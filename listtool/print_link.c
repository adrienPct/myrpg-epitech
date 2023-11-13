/*
** EPITECH PROJECT, 2022
** print_link.c
** File description:
** print_link
*/
#include "rpg.h"

void print_link(link_t *link, game_t *game)
{
    if (link->data.rect.height != 0)
        sfSprite_setTextureRect(link->data.sprite, link->data.rect);
    else
        sfSprite_setTexture(link->data.sprite, link->data.texture, sfTrue);
    sfSprite_setPosition(link->data.sprite, link->data.pos);
    sfRenderWindow_drawSprite(game->win.window, link->data.sprite, NULL);
}