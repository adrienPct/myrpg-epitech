/*
** EPITECH PROJECT, 2022
** manage pause 
** File description:
** manage_pause
*/

#include "rpg.h"

void manage_pause(game_t *game)
{
    animation_solo_buts(game->win.window, game->play.button_resume, game->pos_mouse);
    animation_solo_buts(game->win.window, game->play.button_quit, game->pos_mouse);
    if (sfMouse_isButtonPressed(sfMouseLeft) && object_is_col_vector(game->play.button_quit, game->pos_mouse)) {
        sfSound_play(game->sound.button);
        sfRenderWindow_close(game->win.window);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && object_is_col_vector(game->play.button_resume, game->pos_mouse)) {
        sfSound_play(game->sound.button);
        PAUSE = false;
        game->dial.player_can_move = true;
    }
}