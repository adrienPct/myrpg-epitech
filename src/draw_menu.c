/*
** EPITECH PROJECT, 2022
** draw_menu
** File description:
** draw_menu
*/

#include "rpg.h"

void draw_menu(game_t *game)
{
    sfSprite_setTextureRect(game->menu.bk.sprite, game->menu.bk.rect);
    sfRenderWindow_drawSprite(game->win.window, game->menu.bk.sprite, NULL);
    sfRenderWindow_drawSprite(game->win.window, game->menu.player.sprite, NULL);
    sfSprite_setTextureRect(game->menu.player.sprite, game->menu.player.rect);
    sfRenderWindow_drawSprite(game->win.window, game->menu.bt_play.sprite, NULL);
    sfSprite_setPosition(game->menu.campfire.sprite, game->menu.campfire.pos);
    sfSprite_setTextureRect(game->menu.campfire.sprite, game->menu.campfire.rect);
    sfRenderWindow_drawSprite(game->win.window, game->menu.campfire.sprite, NULL);
    sfRenderWindow_drawSprite(game->win.window, game->menu.quit.sprite, NULL);
    sfRenderWindow_drawText(game->win.window, game->menu.title.text, NULL);
}