/*
** EPITECH PROJECT, 2022
** manage_quest.c
** File description:
** manage_quest
*/

#include "rpg.h"

void manage_message_comming(game_t *game)
{
    if (VIEW == FORESTV) {
        if (PLAYER.obj.pos.x >= 1850) {
            game->show_comming = true;
        } else {
            game->show_comming = false;
        }
    }
}

void manage_rock(game_t *game)
{
    if (VIEW == SPAWNV && game->quest.can_destroy == true) {
        if (PLAYER.obj.pos.x + 50 >= (game->play.rock.pos.x - 15) 
        && (PLAYER.obj.pos.y + PLAYER.obj.collider.height) >= game->play.rock.pos.y 
        &&PLAYER.obj.pos.y <= (game->play.rock.pos.y + 174)) {
            game->quest.show_text = true;
        } else {
            game->quest.show_text = false;
        }
        if (PLAYER.obj.pos.x + 50 >= (game->play.rock.pos.x - 15) 
        && (PLAYER.obj.pos.y + PLAYER.obj.collider.height) >= game->play.rock.pos.y 
        &&PLAYER.obj.pos.y <= (game->play.rock.pos.y + 174) && sfKeyboard_isKeyPressed(sfKeyE)) {
            game->quest.destroy = true;
            sfSound_play(game->sound.rock);
        }
    }
}