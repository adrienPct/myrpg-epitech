/*
** EPITECH PROJECT, 2022
** struct_graph.h
** File description:
** structs_graph
*/

#ifndef STRUCTS_GRAPH_H_
#define STRUCTS_GRAPH_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "stdbool.h"

    typedef struct collider
    {
        float height;
        float width;
        float top;
        float bot;
        float left;
        float right;
        sfVector2f middle;
    } col_t;

    typedef struct object {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        sfVector2f start_pos;
        sfIntRect rect;
        col_t collider;
        int tag;
        int pv;
        int direction;
        int can_move;
        bool hit;
        bool is_dead;
        int damage;
        int id;
        int nb_move;
    } obj_t;

    typedef struct ptr_obj_tab
    {
        obj_t **tab;
        int size;
    } ptr_obj_tab_t;

    typedef struct obj_tab
    {
        obj_t *tab;
        int size;
    } obj_tab_t;

    typedef struct my_clock
    {
        sfClock *clock;
        sfTime time;
        float sec;
    } my_clock_t;

#endif /* !STRUCTS_GRAPH_H_ */