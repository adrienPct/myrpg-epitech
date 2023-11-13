/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg h
*/

#ifndef RPG_H_
    #define RPG_H_

    #include "game.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

void set_all(game_t *game);
void set_play(game_t *game);
void set_menu(game_t *game);
void set_quest(game_t *game);
void draw_menu(game_t *game);

int loop_window(game_t *game);
int manage_event(game_t *game);
void manage_menu(game_t *game);

void set_player(game_t *game);
void manage_player(game_t *game);
void tools_bar(game_t *game);
void anim_player(game_t *game);

void move_player(game_t *game);
void set_col_player(obj_t *object, float height, float width);
void set_col_attack(game_t *game);
void player_attack(game_t *game);

void display(game_t *game);
void draw_play(game_t *game);

void move_slime(game_t *game);
void anim_slime(game_t *game);
void set_col_slime(game_t *game);
void set_slime(game_t *game);
void manage_house(game_t *game);

void cycle_day_night(game_t *game);
void set_env(game_t *game);

void manage_menu_bk(game_t *game);
void manage_rock(game_t *game);

char *my_itoa(int value);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);

void set_house(game_t *game);

void draw_slots(game_t *game);
void draw_player(game_t *game);
void draw_stat(game_t *game);

map_col_t create_map_col(char *path);
int check_col64(obj_t *obj, map_col_t *colliders);
void how_many_slime(game_t *game);
void animation_solo_buts(sfRenderWindow *window, obj_t obj, sfVector2i pos_mouse);

void set_inventory(game_t *game);

void cant_go(game_t *game);

void show_current_quest(game_t *game);

void campfire_gestion(game_t *game);

void experience_quest(game_t *game);

void scene_manager(game_t *game);

void manage_pause(game_t *game);

void set_text(text_t *text, int size, sfVector2f pos, char *what);

void animation_solo_buts_little(sfRenderWindow *window, obj_t obj, sfVector2i pos_mouse);

void interact(game_t *game);
void manage_message_comming(game_t *game);

void val_png_text(game_t *game);
void set_stat(game_t *game);
void manage_stat(game_t *game);

void draw_inventory(game_t *game);
void manage_inventory(game_t *game);
obj_t set_slot(game_t *game, sfVector2f pos, char *path, int act, items_e what);
void set_col_slot(obj_t *slot, sfVector2f pos);
obj_t unset_slot(game_t *game, int act);

void check_xp(game_t *game);

void set_shop(game_t *game);
void draw_shop(game_t *game);
void animation_shop(sfRenderWindow *window, obj_t obj, sfVector2i pos_mouse, text_t text);
void manage_shop(game_t *game);

void deco(game_t *game);
void rotate_flower(game_t *game);

#endif /* !RPG_H_ */
