/*
** EPITECH PROJECT, 2022
** png_text_val.c
** File description:
** png_text_val
*/

#include "rpg.h"

void val_png_text(game_t *game)
{
    if (game->quest.destroy == true && game->quest.first_time_talk == false) {
        game->dial.i = 5;
        sfText_setString(game->dial.quest_text.text, "Congratulations, you have\nsuccessfully completed your \nfirst mission !");
        game->quest.first_time_talk = true;
    }
    if (game->quest.kill_slime == true && game->quest.sec_time_talk == false) {
        game->dial.i = 8;
        sfText_setString(game->dial.quest_text.text, "Congratulations, you save the \nvillage !");
        game->quest.sec_time_talk = true;
    }
}