/*
** EPITECH PROJECT, 2022
** set_play.c
** File description:
** set_play
*/

#include "rpg.h"

void set_col_slime(game_t *game)
{
    link_t *current = SLIMETAB[STARTLINK];
    
    while (current != NULL) {
        current->data.collider.left = current->data.pos.x + 25;
        current->data.collider.right = current->data.pos.x + 75;
        current->data.collider.top = current->data.pos.y + 25;
        current->data.collider.bot = current->data.pos.y + 75;
        current = current->next;
    }
}

obj_t create_slime(void)
{
    obj_t slime;
    set_obj(&slime, "sprite/slime.png", (sfVector2f){rand() % 1800, rand () % 900}, (sfIntRect){0, 0, 100, 100});
    return slime;
}

void set_slime(game_t *game)
{
    game->play.slime.damage = 50;
    game->play.slime.clock_slime.clock = sfClock_create();
    game->play.slime.size = 10;
    game->play.slime.tab = malloc(sizeof(obj_t) * game->play.slime.size);
    for (int i = 0; i != game->play.slime.size; i++) {
        game->play.slime.tab[i] = create_slime();
        game->play.slime.tab[i].direction = rand() % 9;
        game->play.slime.tab[i].nb_move = 0;
    }
    STARTLINK = 0;
    SLIMETAB = malloc(sizeof(link_t *) * game->play.slime.size);
    for (int i = 0; i != game->play.slime.size; i++) {
        SLIMETAB[i] = create_link(&game->play.slime.tab[i], i);
        SLIMETAB[i]->data.is_dead = false;
    }
    for (int i = 1; i != game->play.slime.size; i++) {
        connect_links(SLIMETAB[i - 1], SLIMETAB[i], 0);
    }
    SLIME_IN_LIFE = game->play.slime.size;
    set_col_slime(game);
}

void set_play(game_t *game)
{
    SLOT = ONE;
    PAUSE = false;
    game->show_comming = false;
    game->play.inventory.act_tool = 1;
    game->play.check = malloc(sizeof(bool) * 5);
    for (int i = 0; i != 5; i++)
        game->play.check[i] = true;
    game->play.spawn_col = create_map_col("map/spawn.txt");
    game->play.forest_col = create_map_col("map/forest.txt");
    game->play.act_map_col = game->play.spawn_col;
    set_player(game);
    set_inventory(game);
    HP = 500;
    PLAYER.nb_slimeball = 0;
    set_text(&game->play.pause, 120, (sfVector2f){820, 200}, "PAUSE");
    set_text(&game->comming_soon, 30, (sfVector2f){1700, 700}, "Comming soon...");
    sfText_setColor(game->play.pause.text, sfBlack);
    set_obj(&game->play.button_resume, "sprite/button_resume.png", (sfVector2f){790, 400}, (sfIntRect){0});
    set_collider(&game->play.button_resume, 100, 360);
    set_obj(&game->play.button_quit, "sprite/quit_menu.png", (sfVector2f){910, 560}, (sfIntRect){0});
    set_collider(&game->play.button_quit, 100, 100);
    set_text(&PLAYER.txt_slime, 30, (sfVector2f){110, 70}, my_itoa(PLAYER.nb_slimeball));
    set_obj(&PLAYER.slimeball, "sprite/slimeball.png", (sfVector2f){60, 70}, (sfIntRect){0});
    sfSprite_setScale(PLAYER.slimeball.sprite, (sfVector2f){0.5, 0.5});
    set_obj(&SCENE, SPAWN, (sfVector2f){0, 0}, (sfIntRect){0});
    set_obj(&game->play.life.hp_bar, "sprite/hp.png", (sfVector2f){50, 30}, (sfIntRect){0, 0, 500, 30});
    set_obj(&game->play.life.hp_cont, "sprite/hp_cont.png", (sfVector2f){50, 30}, (sfIntRect){0});
    set_obj(&game->play.png, "sprite/png_quest.png", (sfVector2f) {650, 550}, (sfIntRect){0, 0, 100, 100});
    set_obj(&game->play.house, "sprite/house.png", (sfVector2f){1360, 80}, (sfIntRect){0});
    set_obj(&game->play.bubble_int, "sprite/disc_buble.png", (sfVector2f){675, 480}, (sfIntRect){64, 64, 64, 64});
    set_collider(&game->play.house, 260, 260);
    set_collider(&game->play.png, 100, 100);
    set_obj(&game->play.rock, "sprite/rock.png", (sfVector2f){1750, 550}, (sfIntRect){0});
    set_collider(&game->play.rock, 250, 190);
    set_text(&game->play.text_cant_go, 30, (sfVector2f){1525, 500}, "Go back to the old man.");
    set_slime(game);
    set_shop(game);
    set_obj(&game->play.campfire, "sprite/campfire.png", (sfVector2f){680, 550}, (sfIntRect){600, 0, 150, 126});
    game->play.fire_clock.clock = sfClock_create();
    set_text(&game->game_over, 60, (sfVector2f){700, 200}, "             Game Over\n\n\nPresss [space] to respawn");
}