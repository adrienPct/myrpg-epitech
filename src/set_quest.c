/*
** EPITECH PROJECT, 2022
** set_quest.c
** File description:
** set_quest
*/

#include "rpg.h"

void set_quest(game_t *game)
{
    game->quest.can_destroy = false;
    game->quest.destroy = false;
    game->quest.is_talking = false;
    game->quest.kill_slime = false;
    game->quest.show_text = false;
    game->quest.in_mission = false;
    game->quest.mission_finish_rock = false;
    game->quest.show_cant_go = false;
    game->quest.mission_finish_slime = false;
    game->quest.first_time_talk = false;
    game->quest.sec_time_talk == false;
    game->quest.nb_slime = 0;
    game->quest.xp_first_quest = false;
    game->quest.xp_seconde_quest = false;
    set_text(&game->quest.rock_text, 30, (sfVector2f){1525, 500}, "Press [E] to destroy the rock.");
    set_text(&game->quest.current_quest, 20, (sfVector2f){1775, 80}, "Current quest :");
    set_text(&game->quest.first_quest, 20, (sfVector2f){1740, 110}, "- Go see the old man in the house");
    set_text(&game->quest.go_house, 20, (sfVector2f){1700, 110}, "- Go back to the old man");
    set_text(&game->quest.destroy_quest, 20, (sfVector2f){1740, 110}, "- Destroy the rock");
    set_text(&game->quest.slime_quest, 20, (sfVector2f){1680, 110}, "- Kill the slime in the forest");
}