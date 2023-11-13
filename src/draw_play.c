/*
** EPITECH PROJECT, 2022
** draw_play.c
** File description:
** draw_play
*/

#include "rpg.h"

static void draw_slime(game_t *game)
{
    // for (int i = 0; i != game->play.slime.size; i++) {
    //     sfSprite_setTextureRect(game->play.slime.tab[i].sprite, game->play.slime.tab[i].rect);
    //     sfSprite_setPosition(game->play.slime.tab[i].sprite, game->play.slime.tab[i].pos);
    //     sfRenderWindow_drawSprite(game->win.window, game->play.slime.tab[i].sprite, NULL);
    // }
    if (SLIME_IN_LIFE != 0)
        print_all_link(SLIMETAB[STARTLINK], game);
}

void draw_slots(game_t *game)
{
    for (int i = 0; i != 5; i++) {
        if (game->play.inventory.is_empty[i] == false) {
            sfRenderWindow_drawSprite(game->win.window, game->play.inventory.slots[i].sprite, NULL);
        }
    }
}

void draw_play(game_t *game)
{
    sfSprite_setTextureRect(game->play.inventory.tools_bar.sprite, game->play.inventory.tools_bar.rect);

    if (VIEW == FORESTV)
        draw_slime(game);
    
    game->play.life.hp_bar.rect.width = HP;
    if (VIEW == SPAWNV)
        sfRenderWindow_drawSprite(game->win.window, game->play.house.sprite, NULL);
    if (VIEW == SPAWNV && game->quest.destroy == false)
        sfRenderWindow_drawSprite(game->win.window, game->play.rock.sprite, NULL);
    if (VIEW != FORESTV) {
        sfSprite_setTextureRect(game->play.campfire.sprite, game->play.campfire.rect);
        sfRenderWindow_drawSprite(game->win.window, game->play.campfire.sprite, NULL);
    }
    if (VIEW == SPAWNV)
        for (int i = 0; i != game->env.nb_flower; i++) 
            sfRenderWindow_drawSprite(game->win.window, game->env.flowers[i].sprite, NULL);
    sfSprite_setTextureRect(game->play.player.obj.sprite, game->play.player.obj.rect);
    sfSprite_setPosition(game->play.player.obj.sprite, game->play.player.obj.pos);
    sfRenderWindow_drawSprite(game->win.window, game->play.player.obj.sprite, NULL);
    if (game->env.is_day == false)
        sfRenderWindow_drawSprite(game->win.window, game->env.cycle_filter.sprite, NULL);
    sfSprite_setTextureRect(game->play.life.hp_bar.sprite, game->play.life.hp_bar.rect);
    sfRenderWindow_drawSprite(game->win.window, game->play.life.hp_bar.sprite, NULL);
    sfRenderWindow_drawSprite(game->win.window, game->play.life.hp_cont.sprite, NULL);
    if (VIEW == SPAWNV && game->quest.show_text == true && game->quest.destroy == false)
        sfRenderWindow_drawText(game->win.window, game->quest.rock_text.text, NULL);
    if (VIEW == SPAWNV && game->quest.destroy == true && game->quest.show_cant_go == true && game->quest.mission_finish_rock == false)
        sfRenderWindow_drawText(game->win.window, game->play.text_cant_go.text, NULL);
    if (VIEW == SPAWNV || VIEW == FORESTV || VIEW == HOME)
        draw_stat(game);
    if (VIEW == FORESTV && game->show_comming == true)
        sfRenderWindow_drawText(game->win.window, game->comming_soon.text, NULL);
    sfRenderWindow_drawSprite(game->win.window, game->play.inventory.tools_bar.sprite, NULL);
}