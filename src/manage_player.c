/*
** EPITECH PROJECT, 2022
** manage_player.c
** File description:
** manage_player
*/

#include "rpg.h"

void manage_player(game_t *game)
{
    int check = false;

    for (int i = 0; i != 5; i++) {
        PLAYER.dir_tab[i] = false;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        PLAYER.dir_tab[UP] = true;
        check = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        PLAYER.dir_tab[DOWN] = true;
        check = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        PLAYER.dir_tab[RIGHT] = true;
        PLAYER.idle_base = 0;
        PLAYER.walk_base = 100;
        check = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        PLAYER.dir_tab[LEFT] = true;
        PLAYER.idle_base = 400;
        PLAYER.walk_base = 500;
        check = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) && game->win.event.key.code == sfKeySpace && HP <= 0) {
        PLAYER.obj.pos = (sfVector2f){500, 800};
        VIEW = SPAWNV;
        SCENEPATH = SPAWN;
        SCENE.texture =  sfTexture_createFromFile(SCENEPATH, NULL);
        game->play.act_map_col = game->play.spawn_col;
        game->dial.player_can_move = true;
        PLAYER.obj.rect.width = 100;
        HP = 500;
        sfMusic_stop(game->sound.forest);
        sfMusic_play(game->sound.spawn);
        sfMusic_setLoop(game->sound.spawn, sfTrue);
    }
    if (check == false) {
        PLAYER.dir_tab[IDLE] = true;
    } else {
        PLAYER.dir_tab[IDLE] = false;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        PLAYER.speed = PLAYER.run_speed;
    } else {
        PLAYER.speed = PLAYER.walk_speed;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && PLAYER.attack == false
     && INVENTORY.what_item[INVENTORY.act_tool] == IRONSWORD && game->dial.player_can_move == true) {
        PLAYER.attack = true;
        PLAYER.attack_start =true;
        game->pos_mouse = sfMouse_getPosition(game->win.window);
        if (game->pos_mouse.x <= PLAYER.obj.pos.x) {
            PLAYER.obj.rect.top = 600;
            PLAYER.obj.rect.left = 500;
            PLAYER.orientation = LEFT;
        } else {
            PLAYER.obj.rect.top = 200;
            PLAYER.obj.rect.left = 0;
            PLAYER.orientation = RIGHT;
        }
        player_attack(game);
    }
    if(PLAYER.dir_tab[UP] == true && PLAYER.dir_tab[DOWN] == true) {
        PLAYER.dir_tab[UP] = false;
        PLAYER.dir_tab[DOWN] = false;
        if (PLAYER.dir_tab[RIGHT] == false && PLAYER.dir_tab[LEFT] == false) {
            PLAYER.dir_tab[IDLE] = true;
        }
    }
    if(PLAYER.dir_tab[LEFT] == true && PLAYER.dir_tab[RIGHT] == true) {
        PLAYER.dir_tab[LEFT] = false;
        PLAYER.dir_tab[RIGHT] = false;
        if (PLAYER.dir_tab[DOWN] == false && PLAYER.dir_tab[UP] == false) {
            PLAYER.dir_tab[IDLE] = true;
        }
    }
}