/*
** EPITECH PROJECT, 2022
** anim_player.c
** File description:
** animation_player
*/

#include "rpg.h"

static void idle_anim(game_t *game)
{
    if (game->play.player.idle_base == 0) {
        game->play.player.obj.rect.top = 0;
        if (game->play.player.obj.rect.left <= 400) {
            game->play.player.obj.rect.left += 100;
        } else {
            game->play.player.obj.rect.left = 0;
        }
    } else {
        game->play.player.obj.rect.top = 400;
        if (game->play.player.obj.rect.left >= 100) {
            game->play.player.obj.rect.left -= 100;
        } else {
            game->play.player.obj.rect.left = 400;
        }
    }
}

static void walk_anim(game_t *game)
{
    if (game->play.player.walk_base == 100) {
        game->play.player.obj.rect.top = 100;
        if (game->play.player.obj.rect.left <= 400) {
            game->play.player.obj.rect.left += 100;
        } else {
            game->play.player.obj.rect.left = 0;
        }
    } else {
        game->play.player.obj.rect.top = 500;
        if (game->play.player.obj.rect.left >= 100) {
            game->play.player.obj.rect.left -= 100;
        } else {
            game->play.player.obj.rect.left = 400;
        }
    }
}

static int attack_anim(game_t *game)
{
    if (game->play.player.obj.rect.top == 200) {
        if (game->play.player.obj.rect.left <= 300 && game->play.player.attack_start == false) {
            game->play.player.obj.rect.left += 100;
            if (game->play.player.obj.rect.left == 100)
                game->play.player.obj.rect.width = 200;
            else
                game->play.player.obj.rect.width = 100;
            if (game->play.player.obj.rect.left == 200)
                game->play.player.obj.rect.left = 300;
        } else if (game->play.player.attack_start == false) {
            game->play.player.attack = false;
        }
    }
    if (game->play.player.obj.rect.top == 600) {
        if (game->play.player.obj.rect.left >= 200 && game->play.player.attack_start == false) {
            game->play.player.obj.rect.left -= 100;
            if (game->play.player.obj.rect.left == 400) {
                game->play.player.obj.rect.left -= 100;                
                game->play.player.obj.rect.width = 200;
                game->play.player.obj.pos.x -= 100;
            } else if (game->play.player.obj.rect.width == 200){
                game->play.player.obj.rect.width = 100;
                game->play.player.obj.pos.x += 100;
            }
        } else if (game->play.player.attack_start == false) {
            game->play.player.attack = false;
        }
    }
    game->play.player.attack_start = false;
}

static int what_anim(game_t *game, int i)
{
    if (i == IDLE && game->play.player.attack == false) {
        idle_anim(game);
        return 0;
    }
    if ((i == UP || i == DOWN || i == RIGHT || i == LEFT) && game->play.player.attack == false)
        walk_anim(game);
    else if (game->play.player.attack == true) {
        attack_anim(game);
    }
    return 0;
}

void anim_player(game_t *game)
{
    game->play.player.anim.time = sfClock_getElapsedTime(game->play.player.anim.clock);
    game->play.player.anim.sec = sfTime_asSeconds(game->play.player.anim.time);
    if (game->play.player.anim.sec >= 0.15) {
        for (int i = 0; i != 5; i++) {
            if (game->play.player.dir_tab[i] == true)
                what_anim(game, i);
        }
        if (game->play.png.rect.left <= 400) {
            game->play.png.rect.left += 100;
        } else {
            game->play.png.rect.left = 0;
        }
        sfClock_restart(game->play.player.anim.clock);
    }
}