/*
** EPITECH PROJECT, 2022
** set_all.c
** File description:
** set_all
*/

#include "rpg.h"

static void set_sound(game_t *game)
{
    game->sound.slurp = sfSound_create();
    game->sound.slurp_buf = sfSoundBuffer_createFromFile("audio/Slurp-Sound-Effect.ogg");
    sfSound_setBuffer(game->sound.slurp, game->sound.slurp_buf);
    game->sound.button = sfSound_create();
    game->sound.button_buf = sfSoundBuffer_createFromFile("audio/Button-Click-Sound-Effect.ogg");
    sfSound_setBuffer(game->sound.button, game->sound.button_buf);
    sfSound_setVolume(game->sound.button, 50);
    game->sound.rock = sfSound_create();
    game->sound.rock_buf = sfSoundBuffer_createFromFile("audio/Rock-Smash-Sound-Effect.ogg");
    sfSound_setBuffer(game->sound.rock, game->sound.rock_buf);
    game->sound.death = sfSound_create();
    game->sound.death_buf = sfSoundBuffer_createFromFile("audio/Bone-Crack-Sound-Effect.ogg");
    sfSound_setBuffer(game->sound.death, game->sound.death_buf);
    game->sound.door = sfSound_create();
    game->sound.door_buf = sfSoundBuffer_createFromFile("audio/Door-Opening-Sound-Effect-ProSounds.ogg");
    sfSound_setBuffer(game->sound.door, game->sound.door_buf);
    game->sound.talk = sfSound_create();
    game->sound.talk_buf = sfSoundBuffer_createFromFile("audio/Minecraft-Villager-Sound-Effect.ogg");
    sfSound_setBuffer(game->sound.talk, game->sound.talk_buf);
    game->sound.sword_hit = sfSound_create();
    game->sound.sword_hit_buf = sfSoundBuffer_createFromFile("audio/Sword-Whoosh-Sound-Effect-First-Variation.ogg");
    sfSound_setBuffer(game->sound.sword_hit, game->sound.sword_hit_buf);
    game->sound.spawn = sfMusic_createFromFile("audio/Medieval-Music-–-Cobblestone-Village.ogg");
    sfMusic_setVolume(game->sound.spawn, 20);
    sfMusic_play(game->sound.spawn);
    sfMusic_setLoop(game->sound.spawn, sfTrue);
    game->sound.house = sfMusic_createFromFile("audio/Kingdom Come Deliverance - Tavern Theme 1.ogg");
    sfMusic_setVolume(game->sound.house, 30);
    game->sound.forest = sfMusic_createFromFile("audio/The Elder Scrolls V - Skyrim - Combat #1.ogg");
    sfMusic_setVolume(game->sound.forest, 30);
}

void set_all(game_t *game)
{
    game->win.mode = (sfVideoMode){1920, 1080, 32};
    game->win.window = sfRenderWindow_create(game->win.mode, "THE SLIME FOREST", sfResize | sfClose, NULL);
    game->view = MENU;
    SCENEPATH = SPAWN;
    game->fps.clock = sfClock_create();
    set_menu(game);
    set_play(game);
    set_quest(game);
    set_house(game);
    set_stat(game);
    set_env(game);
    set_sound(game);
    PLAYER.obj.is_dead = false;
}