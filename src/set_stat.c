/*
** EPITECH PROJECT, 2022
** ste stat.c
** File description:
** set_stat
*/

#include "rpg.h"

void set_stat(game_t *game)
{
    game->statis.life = 0;
    game->statis.strength = 0;
    game->statis.speed = 0;
    game->statis.upgrade_point = 0;
    set_obj(&game->statis.stat, "sprite/stat.png", (sfVector2f){0, 540}, (sfIntRect){0});
    set_obj(&game->statis.logo, "sprite/crosssword.png", (sfVector2f){73, 850}, (sfIntRect){0});
    set_obj(&game->statis.plus_life, "sprite/plus.png", (sfVector2f){195, 697}, (sfIntRect){0});
    set_collider(&game->statis.plus_life, 30, 30);
    set_obj(&game->statis.plus_strenght, "sprite/plus.png", (sfVector2f){195, 747}, (sfIntRect){0});
    set_collider(&game->statis.plus_strenght, 30, 30);
    set_obj(&game->statis.plus_speed, "sprite/plus.png", (sfVector2f){195, 797}, (sfIntRect){0});
    set_collider(&game->statis.plus_speed, 30, 30);
    set_text(&game->statis.point_spend, 20, (sfVector2f){20, 610}, "You have\n\npoint to spend");
    set_text(&game->statis.point_spend_var, 20, (sfVector2f){20, 635}, my_itoa(game->statis.upgrade_point));
    set_text(&game->statis.life_text, 20, (sfVector2f){20, 700}, "Armor :");
    set_text(&game->statis.life_point, 20, (sfVector2f){89, 700}, my_itoa(game->statis.life));
    set_text(&game->statis.strenght_text, 20, (sfVector2f){20, 750}, "Strenght :");
    set_text(&game->statis.strenght_point, 20, (sfVector2f){115, 750}, my_itoa(game->statis.strength));
    set_text(&game->statis.speed_text, 20, (sfVector2f){20, 800}, "Speed :");
    set_text(&game->statis.speed_point, 20, (sfVector2f){86, 800}, my_itoa(game->statis.speed));
}