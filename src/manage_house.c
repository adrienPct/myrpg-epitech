/*
** EPITECH PROJECT, 2022
** manage_house.c
** File description:
** manage_house
*/

#include "rpg.h"

void manage_house(game_t *game)
{
    if (game->quest.is_talking == true) {
        game->play.bubble_int.rect.top = 0;
    } else if (game->quest.destroy == true && game->quest.mission_finish_rock == false 
        || game->quest.kill_slime == true && game->quest.mission_finish_slime == false) {
        game->play.bubble_int.rect.top = 64;
        game->play.bubble_int.rect.left = 0;
    } else {
        game->play.bubble_int.rect.top = 64;
        game->play.bubble_int.rect.left = 64;
    }
}