/*
** EPITECH PROJECT, 2022
** connect_links.c
** File description:
** connect_links
*/

#include "game.h"

void connect_links(link_t *link1, link_t *link2, int first)
{
    link1->next = link2;
    link2->prev = link1;
}