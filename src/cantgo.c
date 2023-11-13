/*
** EPITECH PROJECT, 2022
** cantgo.c
** File description:
** cantgo
*/

#include "rpg.h"

void cant_go(game_t *game)
{
    if (VIEW == SPAWNV && game->quest.mission_finish_rock == false) {
        if (PLAYER.obj.pos.x + 50 > 1880 && PLAYER.obj.pos.y > game->play.rock.pos.y 
            && PLAYER.obj.pos.y + 80 < game->play.rock.collider.height + game->play.rock.pos.y) {
            PLAYER.obj.pos.x = PLAYER.obj.pos.x - 5;
        }
        if (PLAYER.obj.pos.x + 100 > 1880 && PLAYER.obj.pos.y > game->play.rock.pos.y 
            && PLAYER.obj.pos.y + 80 < game->play.rock.collider.height + game->play.rock.pos.y && game->quest.destroy == true) {
            game->quest.show_cant_go = true;
        } else {
            game->quest.show_cant_go = false;
        }
    }
}