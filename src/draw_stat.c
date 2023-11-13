/*
** EPITECH PROJECT, 2022
** darw_stat.c
** File description:
** draw_stat
*/

#include "rpg.h"

void draw_stat(game_t *game)
{
    if (game->play.inventory.show_invent == true) {
        sfRenderWindow_drawSprite(game->win.window, game->statis.stat.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->statis.logo.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->statis.plus_life.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->statis.plus_strenght.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->statis.plus_speed.sprite, NULL);
        sfRenderWindow_drawText(game->win.window, game->statis.point_spend.text, NULL);
        sfText_setColor(game->statis.point_spend.text, sfBlack);
        sfRenderWindow_drawText(game->win.window, game->statis.point_spend_var.text, NULL);
        sfText_setColor(game->statis.point_spend_var.text, sfBlack);
        sfRenderWindow_drawText(game->win.window, game->statis.life_text.text, NULL);
        sfText_setColor(game->statis.life_text.text, sfBlack);
        sfRenderWindow_drawText(game->win.window, game->statis.life_point.text, NULL);
        sfText_setColor(game->statis.life_point.text, sfBlack);
        sfRenderWindow_drawText(game->win.window, game->statis.strenght_text.text, NULL);
        sfText_setColor(game->statis.strenght_text.text, sfBlack);
        sfRenderWindow_drawText(game->win.window, game->statis.strenght_point.text, NULL);
        sfText_setColor(game->statis.strenght_point.text, sfBlack);
        sfRenderWindow_drawText(game->win.window, game->statis.speed_text.text, NULL);
        sfText_setColor(game->statis.speed_text.text, sfBlack);
        sfRenderWindow_drawText(game->win.window, game->statis.speed_point.text, NULL);
        sfText_setColor(game->statis.speed_point.text, sfBlack);
    }
}