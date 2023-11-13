/*
** EPITECH PROJECT, 2022
** move_slime
** File description:
** move_slime
*/

#include "rpg.h"

static void implement_move(link_t *current)
{
    current->data.nb_move--;
    if (current->data.direction == UP) {
        current->data.pos.y -= 0.1f;
    }
    if (current->data.direction == DOWN) {
        current->data.pos.y += 0.1f;
    }
    if (current->data.direction == RIGHT) {
        current->data.pos.x += 0.1f;
    }
    if (current->data.direction == LEFT) {
        current->data.pos.x -= 0.1f;
    }
    if (current->data.direction == 5) {
        current->data.pos.x -= 0.1f;
        current->data.pos.y -= 0.1f;
    }
    if (current->data.direction == 6) {
        current->data.pos.x -= 0.1f;
        current->data.pos.y += 0.1f;
    }
    if (current->data.direction == 7) {
        current->data.pos.x += 0.1f;
        current->data.pos.y += 0.1f;
    }
    if (current->data.direction == 8) {
        current->data.pos.x += 0.1f;
        current->data.pos.y -= 0.1f;
    }
}

static void manage_direction(link_t *current)
{
    if (current->data.pos.x <= 0) {
        current->data.direction = RIGHT;
    }
    if (current->data.pos.x >= 1780) {
        current->data.direction = LEFT;
    }
    if (current->data.pos.y <= 0) {
        current->data.direction = DOWN;
    }
    if (current->data.pos.y >= 830) {
        current->data.direction = UP;
    }
}

void move_slime(game_t *game)
{
    link_t *current = SLIMETAB[STARTLINK];
    set_col_slime(game);
    while (SLIME_IN_LIFE != 0 && current != NULL) {
        manage_direction(current);
        if (current->data.direction == IDLE && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 400;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == UP && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 400;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == DOWN && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 400;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == RIGHT && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 400;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == LEFT && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 400;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == 5 && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 400;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == 6 && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 400;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == 7 && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 1920;
            current->data.direction = rand() % 9;
        }
        if (current->data.direction == 8 && current->data.nb_move <= 0) {
            current->data.nb_move = 100 + rand() % 1920;
            current->data.direction = rand() % 9;
        }
        if (current->data.nb_move > 0) {
            implement_move(current);
        }
        current = current->next;
    }
}