/*
** EPITECH PROJECT, 2022
** manage_shop.c
** File description:
** manage_shop
*/

#include "rpg.h"

static int increment_inventory(game_t *game)
{
    for (int i = 0; i != 11; i++) {
        if (INVENTORY.is_empty[i] == true) {
            INVENTORY.slots[i] = set_slot(game, INVENTORY.pos_slot[i], "sprite/potion.png", i, POTION);
            INVENTORY.is_empty[i] = false;
            INVENTORY.what_item[i] = POTION;
            return 1;
        }
    }
    return 0;
}

void manage_shop(game_t *game)
{
    animation_shop(game->win.window, game->shop.button, game->pos_mouse, game->shop.buy);
    if (sfKeyboard_isKeyPressed(sfKeyE) && game->win.event.key.code == sfKeyE
        && game->shop.can_open == true) {
        game->shop.shop_open = true;
        game->dial.player_can_move = false;
        sfSound_play(game->sound.talk);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && object_is_col_vector(game->shop.quit, game->pos_mouse)
        && game->win.event.key.code == sfMouseLeft && game->shop.shop_open == true) {
        game->shop.shop_open = false;
        game->dial.player_can_move = true;
        sfSound_play(game->sound.button);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && object_is_col_vector(game->shop.button, game->pos_mouse)
     && game->win.event.key.code == sfMouseLeft && PLAYER.nb_slimeball >= 5 && game->shop.shop_open == true) {
        if (increment_inventory(game))
            PLAYER.nb_slimeball -= 5;
        sfSound_play(game->sound.button);
    }
}