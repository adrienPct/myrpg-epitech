/*
** EPITECH PROJECT, 2022
** manage menu
** File description:
** manage_menu
*/

#include "rpg.h"

void manage_menu(game_t *game)
{
    animation_solo_buts(game->win.window, game->menu.bt_play, game->pos_mouse);
    animation_solo_buts(game->win.window, game->menu.quit, game->pos_mouse);
    if (sfMouse_isButtonPressed(sfMouseLeft) && object_is_col_vector(game->menu.bt_play, game->pos_mouse)) {
        VIEW = SPAWNV;
        game->env.hours = 6;
        game->env.is_day = true;
        sfSound_play(game->sound.button);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && object_is_col_vector(game->menu.quit, game->pos_mouse)) {
        sfRenderWindow_close(game->win.window);
    }
}