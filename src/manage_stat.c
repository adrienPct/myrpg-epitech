/*
** EPITECH PROJECT, 2022
** manage stat.c
** File description:
** manage_stat
*/

#include "rpg.h"

static void life_add(game_t *game)
{
    if (object_is_col_vector(game->statis.plus_life, game->pos_mouse) && sfMouse_isButtonPressed(sfMouseLeft) && game->win.event.key.code == sfMouseLeft 
        && game->statis.upgrade_point >= 1 && game->statis.life < 5) {
        game->statis.life++;
        game->statis.upgrade_point--;
        game->play.slime.damage = game->play.slime.damage - 5;
        sfSound_play(game->sound.button);
        if (game->statis.life >= 5) {
            set_text(&game->statis.life_point, 20, (sfVector2f){89, 700}, "Level max");
        } else 
            set_text(&game->statis.life_point, 20, (sfVector2f){89, 700}, my_itoa(game->statis.life));
    }
}

static void strength_add(game_t *game)
{
    if (object_is_col_vector(game->statis.plus_strenght, game->pos_mouse) && sfMouse_isButtonPressed(sfMouseLeft) && game->win.event.key.code == sfMouseLeft 
        && game->statis.upgrade_point >= 1 && game->statis.strength < 5) {
        game->statis.strength++;
        game->statis.upgrade_point--;
        sfSound_play(game->sound.button);
        if (game->statis.strength >= 5) {
            set_text(&game->statis.strenght_point, 20, (sfVector2f){115, 750}, "Level max");
        } else 
            set_text(&game->statis.strenght_point, 20, (sfVector2f){115, 750}, my_itoa(game->statis.strength));
    }
}

static void speed_add(game_t *game)
{
    if (object_is_col_vector(game->statis.plus_speed, game->pos_mouse) && sfMouse_isButtonPressed(sfMouseLeft) && game->win.event.key.code == sfMouseLeft 
        && game->statis.upgrade_point >= 1 && game->statis.speed < 5) {
        game->statis.speed++;
        game->statis.upgrade_point--;
        PLAYER.walk_speed += 0.2;
        PLAYER.run_speed += 0.2;
        sfSound_play(game->sound.button);
        if (game->statis.speed >= 5) {
            set_text(&game->statis.speed_point, 20, (sfVector2f){86, 800}, "Level max");
        } else 
            set_text(&game->statis.speed_point, 20, (sfVector2f){86, 800}, my_itoa(game->statis.speed));
    }
}

void manage_stat(game_t *game)
{
    animation_solo_buts_little(game->win.window, game->statis.plus_life, game->pos_mouse);
    animation_solo_buts_little(game->win.window, game->statis.plus_strenght, game->pos_mouse);
    animation_solo_buts_little(game->win.window, game->statis.plus_speed, game->pos_mouse);
    set_text(&game->statis.point_spend_var, 20, (sfVector2f){20, 636}, my_itoa(game->statis.upgrade_point));
    life_add(game);
    strength_add(game);
    speed_add(game);
}