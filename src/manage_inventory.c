/*
** EPITECH PROJECT, 2022
** manage_inventory.c
** File description:
** manage_inventory
*/

#include "rpg.h"

void heal(game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && game->win.event.key.code == sfMouseLeft
        && HP < 500 && game->dial.player_can_move == true) {
        if (INVENTORY.what_item[INVENTORY.act_tool] == POTION) {
            if ((HP + 50) > 500)
                HP = 500;
            else
                HP += 50;
            INVENTORY.slots[INVENTORY.act_tool] = unset_slot(game, INVENTORY.act_tool);
            sfSound_play(game->sound.slurp);
        }
    }
}

void manage_inventory(game_t *game)
{
    game->pos_mouse = sfMouse_getPositionRenderWindow(game->win.window);
    heal(game);
    if (sfKeyboard_isKeyPressed(sfKeyTab) && game->win.event.key.code == sfKeyTab && VIEW != MENU) {
        if (INVENTORY.show_invent == false)
            INVENTORY.show_invent = true;
        else {
            INVENTORY.show_invent = false;
            if (INVENTORY.obj_take != -1) {
                INVENTORY.slots[INVENTORY.obj_take].pos = INVENTORY.start_pos;
                sfSprite_setPosition(INVENTORY.slots[INVENTORY.obj_take].sprite, INVENTORY.slots[INVENTORY.obj_take].pos);
                INVENTORY.obj_take = -1;
            }
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && INVENTORY.show_invent == true && INVENTORY.obj_take == -1 && game->win.event.key.code == sfMouseLeft) {
        for (int i = 0; i != 11; i++) {
            if (object_is_col_vector(INVENTORY.slots[i], game->pos_mouse) && INVENTORY.obj_take == -1 && INVENTORY.is_empty[i] == false) {
                INVENTORY.obj_take = i;
                INVENTORY.start_pos = INVENTORY.slots[i].pos;
                sfSound_play(game->sound.button);
            }
        }
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && INVENTORY.obj_take != -1 && game->win.event.key.code == sfMouseLeft) {
        for (int i = 0; i != 11; i++) {
            if (object_is_col_vector(INVENTORY.slots[i], game->pos_mouse) && INVENTORY.is_empty[i] == true) {
                if (INVENTORY.what_item[INVENTORY.obj_take] == POTION) {
                    INVENTORY.slots[i] = set_slot(game, INVENTORY.pos_slot[i], "sprite/potion.png", i, POTION);
                    INVENTORY.what_item[i] = POTION;
                } else if (INVENTORY.what_item[INVENTORY.obj_take] == IRONSWORD) {
                    INVENTORY.slots[i] = set_slot(game, INVENTORY.pos_slot[i], "sprite/iron_sword.png", i, IRONSWORD);
                    INVENTORY.what_item[i] = IRONSWORD;
                }
                INVENTORY.what_item[INVENTORY.obj_take] = -1;
                INVENTORY.is_empty[INVENTORY.obj_take] = true;
                INVENTORY.is_empty[i] = false;
                INVENTORY.obj_take = -1;
                sfSound_play(game->sound.button);
            }
        }
    }
    if (INVENTORY.obj_take != -1) {
        INVENTORY.slots[INVENTORY.obj_take].pos.x = game->pos_mouse.x;
        INVENTORY.slots[INVENTORY.obj_take].pos.y = game->pos_mouse.y;
        sfSprite_setPosition(INVENTORY.slots[INVENTORY.obj_take].sprite, INVENTORY.slots[INVENTORY.obj_take].pos);
    }
}