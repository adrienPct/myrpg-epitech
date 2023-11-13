/*
** EPITECH PROJECT, 2022
** set_env.c
** File description:
** set_env
*/

#include "rpg.h"

static void set_flower(game_t *game)
{
    set_obj(&game->env.flowers[0], "sprite/pink_flower.png", (sfVector2f){450, 800}, (sfIntRect){0});
    set_obj(&game->env.flowers[1], "sprite/pink_flower.png", (sfVector2f) {350, 300}, (sfIntRect){0});
    set_obj(&game->env.flowers[2], "sprite/pink_flower.png", (sfVector2f) {900, 700}, (sfIntRect){0});
    set_obj(&game->env.flowers[3], "sprite/pink_flower.png", (sfVector2f) {1200, 600}, (sfIntRect){0});
    set_obj(&game->env.flowers[4], "sprite/pink_flower.png", (sfVector2f) {650, 450}, (sfIntRect){0});
    set_obj(&game->env.flowers[5], "sprite/pink_flower.png", (sfVector2f) {1450, 350}, (sfIntRect){0});
    set_obj(&game->env.flowers[6], "sprite/pink_flower.png", (sfVector2f) {1450, 450}, (sfIntRect){0});
    set_obj(&game->env.flowers[7], "sprite/pink_flower.png", (sfVector2f) {1450, 550}, (sfIntRect){0});
    set_obj(&game->env.flowers[8], "sprite/pink_flower.png", (sfVector2f) {1620, 400}, (sfIntRect){0});
    set_obj(&game->env.flowers[9], "sprite/pink_flower.png", (sfVector2f) {1620, 500}, (sfIntRect){0});

    set_obj(&game->env.flowers[10], "sprite/yellow_flower.png", (sfVector2f){800, 300}, (sfIntRect){0});
    set_obj(&game->env.flowers[11], "sprite/yellow_flower.png", (sfVector2f){300, 500}, (sfIntRect){0});
    set_obj(&game->env.flowers[12], "sprite/yellow_flower.png", (sfVector2f){1200, 800}, (sfIntRect){0});
    set_obj(&game->env.flowers[13], "sprite/yellow_flower.png", (sfVector2f){500, 650}, (sfIntRect){0});
    set_obj(&game->env.flowers[14], "sprite/yellow_flower.png", (sfVector2f){1000, 450}, (sfIntRect){0});
    set_obj(&game->env.flowers[15], "sprite/yellow_flower.png", (sfVector2f){1450, 400}, (sfIntRect){0});
    set_obj(&game->env.flowers[16], "sprite/yellow_flower.png", (sfVector2f){1450, 500}, (sfIntRect){0});
    set_obj(&game->env.flowers[17], "sprite/yellow_flower.png", (sfVector2f){1620, 350}, (sfIntRect){0});
    set_obj(&game->env.flowers[18], "sprite/yellow_flower.png", (sfVector2f){1620, 450}, (sfIntRect){0});
    set_obj(&game->env.flowers[19], "sprite/yellow_flower.png", (sfVector2f){1620, 550}, (sfIntRect){0});
}

void set_env(game_t *game)
{
    game->env.nb_flower = 20;
    game->env.flowers = malloc(sizeof(obj_t) * game->env.nb_flower);

    set_flower(game);
     for (int i = 0; i != game->env.nb_flower; i++)
        sfSprite_setOrigin(game->env.flowers[i].sprite, (sfVector2f){25, 25});
    game->env.cycle_clock.clock = sfClock_create();
    set_obj(&game->env.cycle_filter, "sprite/cycle_filter.png", (sfVector2f){0, 0}, (sfIntRect){0});
    game->env.is_day = true;
    game->env.hours = 6;
    game->env.is_am = true;
    set_text(&game->env.hours_time, 30, (sfVector2f){1790, 20}, my_itoa(game->env.hours));
    set_text(&game->env.hours_txt, 30, (sfVector2f){1860, 20}, "Am");
    game->env.clock.clock = sfClock_create();
}

void rotate_flower(game_t *game)
{
    game->env.clock.time = sfClock_getElapsedTime(game->env.clock.clock);
    game->env.clock.sec = sfTime_asSeconds(game->env.clock.time);
    if (game->env.clock.sec >= 0.5) {
        if (sfSprite_getRotation(game->env.flowers[0].sprite) != 5)
            for (int i = 0; i != game->env.nb_flower; i++)
                sfSprite_rotate(game->env.flowers[i].sprite, 5);
        else 
            for (int i = 0; i != game->env.nb_flower; i++)
                sfSprite_rotate(game->env.flowers[i].sprite, -10);
        sfClock_restart(game->env.clock.clock);
    }

}