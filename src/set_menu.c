/*
** EPITECH PROJECT, 2022
** set_menu.c
** File description:
** set_menu
*/

#include "rpg.h"

void set_menu(game_t *game)
{
    set_obj(&game->menu.bt_play, "sprite/play_bt.png", (sfVector2f){675, 800}, (sfIntRect){0});
    set_collider(&game->menu.bt_play, 100, 360);
    set_obj(&game->menu.quit, "sprite/quit_menu.png",(sfVector2f){1100, 800}, (sfIntRect){0});
    set_collider(&game->menu.quit, 100, 100);
    set_obj(&game->menu.bk, "sprite/menu_bk.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    game->menu.bk_c.clock = sfClock_create();
    set_obj(&game->menu.player, "sprite/player.png", (sfVector2f){500, 500}, (sfIntRect){0, 0, 100, 100});
    game->menu.pl_c.clock = sfClock_create();
    set_obj(&game->menu.campfire, "sprite/campfire.png", (sfVector2f){4500, 480}, (sfIntRect){600, 0, 150, 126});
    set_text(&game->menu.title, 100, (sfVector2f){625, 50}, "The slime forest");
}