/*
** EPITECH PROJECT, 2022
** manage_menu_bk.c
** File description:
** manage_menu_bk
*/

#include "rpg.h"

static void idle_anim(game_t *game)
{
    game->menu.player.rect.top = 0;
    if (game->menu.player.rect.left <= 400) {
        game->menu.player.rect.left += 100;
    } else {
        game->menu.player.rect.left = 0;
    }
}

static void walk_anim(game_t *game)
{
    game->menu.player.rect.top = 100;
    if (game->menu.player.rect.left <= 400) {
        game->menu.player.rect.left += 100;
    } else {
        game->menu.player.rect.left = 0;
    }
}

void manage_menu_bk(game_t *game)
{   
    if (game->menu.bk.rect.left < 3840) {
        game->menu.bk_c.time = sfClock_getElapsedTime(game->menu.bk_c.clock);
        game->menu.bk_c.sec = sfTime_asMilliseconds(game->menu.bk_c.time);
        if (game->menu.bk_c.sec >= 5) {
            game->menu.bk.rect.left++;
            game->menu.campfire.pos.x--;
            sfClock_restart(game->menu.bk_c.clock);
        }
    }
    game->menu.pl_c.time = sfClock_getElapsedTime(game->menu.pl_c.clock);
    game->menu.pl_c.sec = sfTime_asSeconds(game->menu.pl_c.time);
    if (game->menu.pl_c.sec >= 0.2) {
        if (game->menu.bk.rect.left < 3840)
            walk_anim(game);
        else
            idle_anim(game);
        if (game->menu.campfire.rect.left == 600 && game->menu.campfire.rect.left >= 3840)
            game->menu.campfire.rect.left = 0;
        if (game->menu.bk.rect.left >= 3840) {
            if (game->menu.campfire.rect.left <= 300)
                game->menu.campfire.rect.left += 150;
            else 
                game->menu.campfire.rect.left = 0;
        }
        sfClock_restart(game->menu.pl_c.clock);
    }
}