/*
** EPITECH PROJECT, 2022
** slime
** File description:
** anim
*/

#include "rpg.h"

static void player_death(game_t *game)
{
    if (HP <= 0) {
        if (PLAYER.obj.is_dead == true) {
            PLAYER.obj.is_dead = false;
            sfSound_play(game->sound.death);
        }
        game->dial.player_can_move = false;
        PLAYER.obj.rect.top = 300;
        PLAYER.obj.rect.left = 200;
        PLAYER.obj.rect.width = 200;
    }
}

void anim_slime(game_t *game)
{
    game->play.slime.clock_slime.time = sfClock_getElapsedTime(game->play.slime.clock_slime.clock);
    game->play.slime.clock_slime.sec = sfTime_asSeconds(game->play.slime.clock_slime.time);
    player_death(game);
    if (game->play.slime.clock_slime.sec >= 0.15f) {
        link_t *current = SLIMETAB[STARTLINK];
        while (SLIME_IN_LIFE != 0 && current != NULL) {
            if (on_collision(PLAYER.obj, current->data) && HP > 0) {
                HP -= game->play.slime.damage;
                if (HP < 0)
                    HP = 0;
                if (HP == 0)
                    PLAYER.obj.is_dead = true;
            }
            current->data.rect.top = 100;
            if (current->data.rect.left <= 400)
                current->data.rect.left += 100;
            else
                current->data.rect.left = 0;
            current = current->next;
        }
        sfClock_restart(game->play.slime.clock_slime.clock);
    }
}