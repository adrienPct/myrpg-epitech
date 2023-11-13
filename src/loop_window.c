/*
** EPITECH PROJECT, 2022
** loop_window.c
** File description:
** loop_window
*/

#include "rpg.h"

int loop_window(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win.window)) {
        manage_event(game);
        scene_manager(game);
        if (PAUSE == false) {
            cycle_day_night(game);
            rotate_flower(game);
        }
        game->fps.time = sfClock_getElapsedTime(game->fps.clock);
        game->fps.sec = sfTime_asSeconds(game->fps.time);
        if (game->fps.sec >= 0.016) {
            if (PAUSE == false)
                anim_player(game);
            if (VIEW == MENU) {
                manage_menu_bk(game);
            }
            if (VIEW == HOME && PAUSE == false) {
                manage_house(game);
            }
            if (VIEW == FORESTV && PAUSE == false) {
                anim_slime(game);
                move_slime(game);
            }
            if (VIEW == SPAWNV && PAUSE == false)
                campfire_gestion(game);
            if (VIEW == SPAWNV || VIEW == FORESTV || VIEW == HOME && PAUSE == false)
                experience_quest(game);
            if ((VIEW == SPAWNV || VIEW == FORESTV || VIEW == HOME && PAUSE == false)
                && game->dial.player_can_move == true)
                move_player(game);
            cant_go(game);
            display(game);
            val_png_text(game);
            how_many_slime(game);
        }
    }
    return 0;
}