/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-adrien.picot
** File description:
** set_inventory.c
*/

#include "rpg.h"

void set_col_slot(obj_t *slot, sfVector2f pos)
{
    slot->collider.height = 80;
    slot->collider.width = 80;
    slot->collider.left = pos.x - 40;
    slot->collider.right = pos.x + 40;
    slot->collider.top = pos.y - 40;
    slot->collider.bot = pos.y + 40;
}

obj_t set_slot(game_t *game, sfVector2f pos, char *path, int act, items_e what)
{
    obj_t slot;

    game->play.inventory.is_empty[act] = false;
    game->play.inventory.what_item[act] = what;
    set_obj(&slot, path, pos, (sfIntRect){0});
    if (what == IRONSWORD)
        sfSprite_rotate(slot.sprite, 30);
    sfSprite_setOrigin(slot.sprite, (sfVector2f){40, 40});
    sfSprite_setPosition(slot.sprite, pos);
    set_col_slot(&slot, INVENTORY.pos_slot[act]);
    return slot;
}

obj_t unset_slot(game_t *game, int act)
{
    obj_t slot;

    INVENTORY.is_empty[act] = true;
    INVENTORY.what_item[act] = -1;
    slot.pos = INVENTORY.pos_slot[act];
    set_col_slot(&slot, INVENTORY.pos_slot[act]);
    return slot;
}

void set_inventory(game_t *game)
{
    sfVector2f pos;

    set_obj(&game->play.inventory.tools_bar, "sprite/tools_bar.png", (sfVector2f){780, 900}, (sfIntRect){0, 0, 400, 80});
    set_obj(&game->play.inventory.inv_font, "sprite/inventory.png", (sfVector2f){0, 300}, (sfIntRect){0});
    pos = INVENTORY.tools_bar.pos;
    INVENTORY.obj_take = -1;
    pos.x += 40;
    pos.y += 40;
    game->play.inventory.slots = malloc(sizeof(obj_t) * 11);
    game->play.inventory.is_empty = malloc(sizeof(bool) * 11);
    game->play.inventory.what_item = malloc(sizeof(items_e) * 11);
    game->play.inventory.pos_slot = malloc(sizeof(sfVector2f) * 11);
    game->play.inventory.show_invent = false;
    for (int i = 0; i != 11; i++) {
        INVENTORY.pos_slot[i] = pos;
        pos.x += 80;
        if (i == 4) {
            pos.x = 40;
            pos.y = 300 + 120;
        }
        if (i == 7) {
            pos.x = 40;
            pos.y = 420 + 80;
        }
    }
    for (int i = 0; i != 11; i++) {
        game->play.inventory.is_empty[i] = true;
        game->play.inventory.what_item[i] = -1;
        set_col_slot(&INVENTORY.slots[i], INVENTORY.pos_slot[i]);
    }
    game->play.inventory.slots[0] = set_slot(game, INVENTORY.pos_slot[0], "sprite/iron_sword.png", 0, IRONSWORD);
    game->play.inventory.act_tool = 0;
}