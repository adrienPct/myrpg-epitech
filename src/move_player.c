/*
** EPITECH PROJECT, 2022
** move_player.c
** File description:
** move_player
*/

#include "rpg.h"

static void move_dir(game_t *game, int i)
{

    if (i == UP && CAN_MOVE.up == true) {
        PLAYER.obj.pos.y -= PLAYER.speed;
    }
    if (i == DOWN && CAN_MOVE.down == true) {
        PLAYER.obj.pos.y += PLAYER.speed;
    }
    if (i == RIGHT && CAN_MOVE.right == true) {
        PLAYER.obj.pos.x += PLAYER.speed;
    }
    if (i == LEFT && CAN_MOVE.left == true) {
        PLAYER.obj.pos.x -= PLAYER.speed;
    }
}

void set_col_player(obj_t *object, float height, float width)
{
    object->collider.height = height;
    object->collider.width = width;
    object->collider.top = object->pos.y + 15;
    object->collider.bot = object->pos.y + 25;
    object->collider.right = object->pos.x + 30;
    object->collider.left = object->pos.x - 30;
    object->collider.middle.x = object->pos.x + (width / 2);
    object->collider.middle.y = object->pos.y + (height / 2);
}

static int manage_col(game_t *game, bool in_col)
{
    if (in_col == true) {
        if (PLAYER.dir_tab[DOWN] == true && CAN_MOVE.down == true) {
            CAN_MOVE.down = false;
            PLAYER.obj.pos.y -= 5;
        }
        if (PLAYER.dir_tab[UP] == true && CAN_MOVE.up == true) {
            CAN_MOVE.up = false;
            PLAYER.obj.pos.y += 5;
        }
        if (PLAYER.dir_tab[RIGHT] == true && CAN_MOVE.right == true) {
            CAN_MOVE.right = false;
            PLAYER.obj.pos.x -= 5;
        }
        if (PLAYER.dir_tab[LEFT] == true && CAN_MOVE.left == true) {
            CAN_MOVE.left = false;
            PLAYER.obj.pos.x += 5;
        }
    }
}

void move_player(game_t *game)
{
    set_col_player(&PLAYER, 100, 100);
    set_col_attack(game);
    if (PLAYER.obj.pos.x >= 1900 && VIEW == FORESTV)
        manage_col(game, true);
    else if (on_collision(PLAYER.obj, game->play.house) && VIEW == SPAWNV) {
        manage_col(game, true);
    } else if (on_collision(PLAYER.obj, game->play.rock) && game->quest.destroy == false) {
        manage_col(game, true);
    } else if (check_col64(&PLAYER, &game->play.act_map_col) == 1) {
        manage_col(game, true);
    } else {
        CAN_MOVE.right = true;
        CAN_MOVE.left = true;
        CAN_MOVE.up = true;
        CAN_MOVE.down = true;
    }
    if (CAN_MOVE.right == false && CAN_MOVE.left == false
     && CAN_MOVE.up == false && CAN_MOVE.down == false) {
        PLAYER.stuck = true;
        CAN_MOVE.right = true;
        CAN_MOVE.left = true;
        CAN_MOVE.up = true;
        CAN_MOVE.down = true;
     }
    for (int i = 0; i != 5; i++) {
        if (PLAYER.dir_tab[i] == true) {
            move_dir(game, i);
        }
    }
}