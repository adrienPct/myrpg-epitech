/*
** EPITECH PROJECT, 2022
** campfire_gestion.c
** File description:
** campfire_gestion
*/

#include "rpg.h"

void campfire_gestion(game_t *game)
{
    game->play.fire_clock.time = sfClock_getElapsedTime(game->play.fire_clock.clock);
    game->play.fire_clock.sec = sfTime_asSeconds(game->play.fire_clock.time);
    if (game->play.fire_clock.sec >= 0.2) {
        if (game->play.campfire.rect.left <= 300)
            game->play.campfire.rect.left += 150;
        else 
            game->play.campfire.rect.left = 0;
        sfClock_restart(game->play.fire_clock.clock);
    }
}