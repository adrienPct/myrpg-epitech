/*
** EPITECH PROJECT, 2022
** graphic_lib.h
** File description:
** grahic_lib
*/

#ifndef GRAHIC_LIB_H_
#define GRAHIC_LIB_H_

    #include "structs_graph.h"
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

void set_obj(obj_t *object, char *text_path, sfVector2f pos, sfIntRect rect);
void set_collider(obj_t *object, float height, float width);

int object_is_col_vector(obj_t object, sfVector2i pos_mouse);
int on_collision(obj_t object1, obj_t object2);
int on_middle_collision(obj_t object1, obj_t object2);
void draw_obj(sfRenderWindow *window, obj_tab_t objects);
void animation_buts(sfRenderWindow *window, obj_tab_t tab, sfVector2i pos_mouse);

#endif /* !GRAHIC_LIB_H_ */