/*
** EPITECH PROJECT, 2022
** print_all_link.c
** File description:
** print_all_link
*/

#include "rpg.h"

void print_all_link(link_t *link, game_t *game)
{
    link_t *act = link;

    while (act != NULL) {
        print_link(act, game);
        act = act->next;
    }
}