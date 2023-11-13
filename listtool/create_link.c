/*
** EPITECH PROJECT, 2022
** create_link.c
** File description:
** create_link
*/

#include "game.h"

link_t *create_link(obj_t *data, int id)
{
    link_t *link = malloc(sizeof(link_t));
    
    link->data = *data;
    link->prev = NULL;
    link->next = NULL;
    link->id = id;
    return link;
}