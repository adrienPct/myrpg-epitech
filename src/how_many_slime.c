/*
** EPITECH PROJECT, 2022
** how_many_slime.c
** File description:
** how_many_slime
*/

#include "rpg.h"

void how_many_slime(game_t *game)
{
    if (game->quest.nb_slime == 10) {
        game->quest.kill_slime = true;
    }
}