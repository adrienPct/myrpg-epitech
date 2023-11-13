/*
** EPITECH PROJECT, 2022
** show_current_quest.c
** File description:
** show_current_quest
*/

#include "rpg.h"

void show_current_quest(game_t *game)
{
    sfRenderWindow_drawText(game->win.window, game->quest.current_quest.text, NULL);
    if (game->quest.can_destroy == false && game->quest.mission_finish_rock == false)
        sfRenderWindow_drawText(game->win.window, game->quest.first_quest.text, NULL);
    if (game->quest.can_destroy == true && game->quest.destroy == false)
        sfRenderWindow_drawText(game->win.window, game->quest.destroy_quest.text, NULL);
    if (game->quest.can_destroy == true && game->quest.destroy == true)
        sfRenderWindow_drawText(game->win.window, game->quest.go_house.text, NULL);
    if (game->quest.mission_finish_rock == true && game->quest.kill_slime == false)
        sfRenderWindow_drawText(game->win.window, game->quest.slime_quest.text, NULL);
    if (game->quest.mission_finish_rock == true && game->quest.kill_slime == true)
        sfRenderWindow_drawText(game->win.window, game->quest.go_house.text, NULL);
}