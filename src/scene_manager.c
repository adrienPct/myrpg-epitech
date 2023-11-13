/*
** EPITECH PROJECT, 2022
** scene_manager.c
** File description:
** scene_manager
*/

#include "rpg.h"

void scene_manager(game_t *game)
{
    if (VIEW == SPAWNV) {
        if (PLAYER.obj.pos.x >= 1920) {
            if (SLIME_IN_LIFE == 0)
                set_slime(game);
            PLAYER.obj.pos = (sfVector2f){10, 500};
            VIEW = FORESTV;
            SCENEPATH = FOREST;
            SCENE.texture =  sfTexture_createFromFile(SCENEPATH, NULL);
            game->play.act_map_col = game->play.forest_col;
            sfMusic_stop(game->sound.spawn);
            sfMusic_play(game->sound.forest);
            sfMusic_setLoop(game->sound.forest, sfTrue);
        }
    }
    if (VIEW == FORESTV) {
        if (PLAYER.obj.pos.x <= 0) {
            PLAYER.obj.pos = (sfVector2f){1910, 600};
            VIEW = SPAWNV;
            SCENEPATH = SPAWN;
            SCENE.texture =  sfTexture_createFromFile(SCENEPATH, NULL);
            game->play.act_map_col = game->play.spawn_col;
            sfMusic_stop(game->sound.forest);
            sfMusic_play(game->sound.spawn);
            sfMusic_setLoop(game->sound.spawn, sfTrue);
        }
    }
    if(on_collision(game->play.player.obj, game->play.house) && VIEW == SPAWNV) {
        if (PLAYER.obj.pos.x > 1510 && PLAYER.obj.pos.x < 1550) {
            VIEW = HOME;
            PLAYER.obj.pos = (sfVector2f){1220, 650};
            game->play.act_map_col = game->home.col_map;
            sfSound_play(game->sound.door);
            sfMusic_stop(game->sound.spawn);
            sfMusic_play(game->sound.house);
            sfMusic_setLoop(game->sound.house, sfTrue);
        }
    }
    if (VIEW == HOME && PLAYER.obj.pos.y > 660 && PLAYER.obj.pos.x > 1200 && PLAYER.obj.pos.x < 1240) {
        PLAYER.obj.pos = (sfVector2f){1530, 330};
        VIEW = SPAWNV;
        sfSound_play(game->sound.door);
        game->play.act_map_col = game->play.spawn_col;
        sfMusic_stop(game->sound.house);
        sfMusic_play(game->sound.spawn);
        sfMusic_setLoop(game->sound.spawn, sfTrue);
    }
}