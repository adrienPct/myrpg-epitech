/*
** EPITECH PROJECT, 2022
** set_house.c
** File description:
** set_house
*/

#include "rpg.h"

void set_house(game_t *game)
{
    game->dial.i = 0;

    set_text(&game->home.text_png, 50, (sfVector2f){775, 820}, "Press [E] to interact");
    set_text(&game->dial.quest_text, 35, (sfVector2f){120, 850}, "Hello adventurer, as you could\n see outside here is a big rock in\nthe middle of the path which...");
    // set_text(&game->dial.second_quest_text, 35, (sfVector2f){120, 850}, "condemns the forest. Because\nof this rock no one can go to the\nforest, it is invaded by slime.");
    // set_text(&game->dial.second_quest_text, 35, (sfVector2f){120, 850}, "We need someone strong to kill them and free the forest.");
    sfText_setColor(game->dial.quest_text.text, sfBlack);
    // sfText_setColor(game->dial.second_quest_text.text, sfBlack);
    // sfText_setColor(game->dial.third_quest_text.text, sfBlack);
    set_obj(&game->home.build, "sprite/in_house.png", (sfVector2f){0, 0}, (sfIntRect){0});
    set_obj(&game->home.box_text, "sprite/box_text.png", (sfVector2f){0, 725}, (sfIntRect){0});
    set_obj(&game->home.arrow, "sprite/continue.png", (sfVector2f){615, 960}, (sfIntRect){0, 0, 16, 26});
    set_collider(&game->home.arrow, 100, 100);
    game->home.col_map = create_map_col("map/house.txt");
    game->play.bubble_c.clock = sfClock_create();
}