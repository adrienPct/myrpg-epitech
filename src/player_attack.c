/*
** EPITECH PROJECT, 2022
** player_attack.c
** File description:
** attack
*/

#include "rpg.h"

void check_xp(game_t *game)
{
    switch (LVL.xp)
    {
    case 0:
        LVL.xp_bar.rect.top = 0;
        break;
    case 1:
        LVL.xp_bar.rect.top = 32;
        break;
    case 2:
        LVL.xp_bar.rect.top = 64;
        break;
    case 3:
        LVL.xp_bar.rect.top = 96;
        break;
    case 4:
        LVL.xp_bar.rect.top = 128;
        break;
    case 5:
        LVL.xp_bar.rect.top = 160;
        break;
    case 6:
        LVL.xp_bar.rect.top = 192;
        break;
    case 7:
        LVL.xp_bar.rect.top = 224;
        break;
    case 8:
        LVL.xp_bar.rect.top = 256;
        break;
    case 9:
        LVL.xp_bar.rect.top = 288;
        break;
    case 10:
        LVL.xp_bar.rect.top = 0;
        LVL.xp = 0;
        LVL.lvl++;
        game->statis.upgrade_point++;
        break;
    default:
        break;
    }
}

static int check_col_slime(game_t *game, link_t *slime)
{
    if (PLAYER.col_attack.right >= slime->data.collider.left
     && PLAYER.col_attack.left <= slime->data.collider.right
     && PLAYER.col_attack.top <= slime->data.collider.bot
     && PLAYER.col_attack.bot >= slime->data.collider.top)
         return 1;
    return 0;
}

static void increment(game_t *game)
{
    if (VIEW == FORESTV) {
        game->quest.nb_slime++;
        PLAYER.nb_slimeball += 2;
        LVL.xp++;
        check_xp(game);
    }
}

void player_attack(game_t *game)
{
    link_t *current = SLIMETAB[STARTLINK];

    sfSound_play(game->sound.sword_hit);
    set_col_slime(game);
    while (SLIME_IN_LIFE != 0 && current != NULL) {
        if (check_col_slime(game, current)) {
            if (current->prev == NULL && current->next == NULL) {
                current = NULL;
                SLIME_IN_LIFE = 0;
                increment(game);
                break;
            } else if (current->prev == NULL) {
                STARTLINK = current->next->id;
                current->next->prev = NULL;
            } else if (current->next == NULL)
                current->prev->next = NULL;
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            increment(game);
        }
        current = current->next;
    }
}