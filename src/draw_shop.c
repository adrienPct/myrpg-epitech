/*
** EPITECH PROJECT, 2022
** draw_shop.c
** File description:
** draw_shop
*/

#include "rpg.h"

void draw_shop(game_t *game)
{   
    if (PAUSE == false) {
        game->shop.anim_p.time = sfClock_getElapsedTime(game->shop.anim_p.clock);
        game->shop.anim_p.sec = sfTime_asSeconds(game->shop.anim_p.time);
        if (game->shop.anim_p.sec > 0.2) {
            if (game->shop.png.rect.left == 0)
                game->shop.png.rect.left = 100;
            else
                game->shop.png.rect.left = 0;
            sfClock_restart(game->shop.anim_p.clock);
        }
    }
    if (on_collision(PLAYER.obj, game->shop.png) && game->shop.shop_open == false) {
        sfRenderWindow_drawText(game->win.window, game->shop.talk.text, NULL);
        game->shop.can_open = true;
    } else {
        game->shop.can_open = false;
    }
    if (game->shop.shop_open == true) {
        sfRenderWindow_drawSprite(game->win.window, game->shop.bk.sprite, NULL);
        sfRenderWindow_drawText(game->win.window, game->shop.title.text, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->shop.slimeball.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->shop.arrow.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->shop.potion.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->shop.button.sprite, NULL);
        sfRenderWindow_drawText(game->win.window, game->shop.buy.text, NULL);
        sfRenderWindow_drawText(game->win.window, game->shop.price_txt.text, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->shop.quit.sprite, NULL);
    }
}