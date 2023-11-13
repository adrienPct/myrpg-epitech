/*
** EPITECH PROJECT, 2022
** set_shop.c
** File description:
** set_shop
*/

#include "rpg.h"

void set_shop(game_t *game)
{
    game->shop.shop_open = false;
    game->shop.can_open = false;
    game->shop.price = 5;
    set_text(&game->shop.talk, 30, (sfVector2f){530, 450}, "Press [E] to speak");
    set_text(&game->shop.title, 60, (sfVector2f){900, 285}, "Shop");
    set_obj(&game->shop.slimeball, "sprite/slimeball.png", (sfVector2f){820, 400}, (sfIntRect){0});
    set_obj(&game->shop.arrow, "sprite/arrow_shop.png", (sfVector2f){920, 400}, (sfIntRect){0});
    set_obj(&game->shop.potion, "sprite/potion.png", (sfVector2f){1020, 380}, (sfIntRect){0});
    set_obj(&game->shop.button, "sprite/but_buy.png", (sfVector2f){845, 550}, (sfIntRect){0});
    set_obj(&game->shop.quit, "sprite/quit.png", (sfVector2f){1150, 285}, (sfIntRect){0});
    set_collider(&game->shop.quit, 35, 35);
    set_text(&game->shop.price_txt, 30, (sfVector2f){920, 500}, "Price : 5");
    set_text(&game->shop.buy, 50, (sfVector2f){920, 560}, "Buy !");
    set_collider(&game->shop.button, 80, 250);
    sfText_setColor(game->shop.buy.text, sfBlack);
    sfText_setColor(game->shop.price_txt.text, sfBlack);
    sfSprite_setScale(game->shop.potion.sprite, (sfVector2f){1.3, 1.3});
    sfText_setColor(game->shop.title.text, sfBlack);
    set_obj(&game->shop.bk, "sprite/shop_bk.png", (sfVector2f){700, 250}, (sfIntRect){0});
    set_obj(&game->shop.png, "sprite/seller.png", (sfVector2f){600, 500}, (sfIntRect){0, 0, 100, 100});
    set_collider(&game->shop.png, 100, 100);
    game->shop.anim_p.clock = sfClock_create();
}