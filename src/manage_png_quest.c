/*
** EPITECH PROJECT, 2022
** manage_png_quest.c
** File description:
** manage
*/

#include "rpg.h"

void interact(game_t *game)
{
    game->play.bubble_c.time = sfClock_getElapsedTime(game->play.bubble_c.clock);
    game->play.bubble_c.sec = sfTime_asSeconds(game->play.bubble_c.time);
    if (game->play.bubble_c.sec >= 0.5) {
        if (game->play.bubble_int.pos.y == 480)
            game->play.bubble_int.pos.y += 2;
        else
            game->play.bubble_int.pos.y -= 2;
        if (game->play.bubble_int.rect.top == 0) {
            if (game->play.bubble_int.rect.left <= 128)
                game->play.bubble_int.rect.left += 64;
            else
                game->play.bubble_int.rect.left = 0;
        }
        if (game->home.arrow.rect.left == 0)
            game->home.arrow.rect.left = 16;
        else
            game->home.arrow.rect.left = 0;
        sfSprite_setPosition(game->play.bubble_int.sprite, game->play.bubble_int.pos);
        sfClock_restart(game->play.bubble_c.clock);
    }
}