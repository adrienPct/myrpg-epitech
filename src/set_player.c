/*
** EPITECH PROJECT, 2022
** set_player.c
** File description:
** set_player
*/

#include "rpg.h"

void set_col_attack(game_t *game)
{
    if (PLAYER.orientation == RIGHT) {
        PLAYER.col_attack.left = PLAYER.obj.collider.left;
        PLAYER.col_attack.right = PLAYER.obj.collider.right + 50;
        PLAYER.col_attack.top = PLAYER.obj.collider.top;
        PLAYER.col_attack.bot = PLAYER.obj.collider.bot + 25;
    } else if (PLAYER.orientation == LEFT) {
        PLAYER.col_attack.left = PLAYER.obj.collider.left - 50;
        PLAYER.col_attack.right = PLAYER.obj.collider.right;
        PLAYER.col_attack.top = PLAYER.obj.collider.top;
        PLAYER.col_attack.bot = PLAYER.obj.collider.bot + 25;
    }
}

static void set_lvl(game_t *game)
{
    LVL.lvl = 1;
    LVL.xp = 0;
    set_obj(&LVL.xp_bar, "sprite/lvl.png", (sfVector2f){840, 870}, (sfIntRect){0, 0, 320, 32});
    set_text(&LVL.lvl_txt, 30, (sfVector2f){800, 865}, my_itoa(LVL.lvl));
}

void set_player(game_t *game)
{
    game->play.player.idle_base = 0;
    game->play.player.attack = false;
    game->dial.player_can_move = true;
    game->play.player.walk_base = 100;
    game->play.player.anim.clock = sfClock_create();
    game->play.player.speed = 0.2f;
    game->play.player.dir_tab = malloc(sizeof(bool) * 5);
    game->play.player.dir_tab[IDLE] = true;
    set_obj(&game->play.player.obj, "sprite/player.png", (sfVector2f){500, 800}, (sfIntRect){0, 0, 100, 100});
    sfSprite_setOrigin(game->play.player.obj.sprite, (sfVector2f){50, 50});
    CAN_MOVE.down = true;
    CAN_MOVE.up = true;
    CAN_MOVE.left = true;
    CAN_MOVE.right = true;
    PLAYER.stuck = false;
    set_lvl(game);
    PLAYER.orientation = RIGHT;
    set_col_player(&PLAYER.obj, 100, 100);
    set_col_attack(game);
    PLAYER.walk_speed = 0.2f;
    PLAYER.run_speed = 0.4f;
}