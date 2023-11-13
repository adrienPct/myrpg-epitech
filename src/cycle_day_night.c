/*
** EPITECH PROJECT, 2022
** cycle_day_night.c
** File description:
** cycle_day_night
*/

#include "rpg.h"

void cycle_day_night(game_t *game)
{
    game->env.cycle_clock.time = sfClock_getElapsedTime(game->env.cycle_clock.clock);
    game->env.cycle_clock.sec = sfTime_asSeconds(game->env.cycle_clock.time);
    if (game->env.cycle_clock.sec >= 5) {
        if (game->env.hours == 11 && game->env.is_am == true)
            game->env.is_am = false;
        else if (game->env.hours == 11 && game->env.is_am == false)
            game->env.is_am = true;
        if (game->env.hours == 12 && game->env.is_am == true) {
            game->env.hours = 0;
        } else if (game->env.hours == 12 && game->env.is_am == false) {
            game->env.hours = 0;
        }
        game->env.hours++;
        sfClock_restart(game->env.cycle_clock.clock);
    }
    if (game->env.hours == 7 && game->env.is_am == false)
        game->env.is_day = false;
    else if (game->env.hours == 6 && game->env.is_am == true)
        game->env.is_day = true;
    if (game->env.is_am == false)
        sfText_setString(game->env.hours_txt.text, "Pm");
    if (game->env.is_am == true)
        sfText_setString(game->env.hours_txt.text, "Am");
    sfText_setString(game->env.hours_time.text, my_strcat(my_itoa(game->env.hours), ":00"));
}