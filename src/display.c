/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/

#include "rpg.h"

void draw_player(game_t *game)
{
    game->play.life.hp_bar.rect.width = HP;
    sfSprite_setTextureRect(game->play.life.hp_bar.sprite, game->play.life.hp_bar.rect);
    sfRenderWindow_drawSprite(game->win.window, game->play.life.hp_bar.sprite, NULL);
    sfRenderWindow_drawSprite(game->win.window, game->play.life.hp_cont.sprite, NULL);
    sfSprite_setTextureRect(game->play.png.sprite, game->play.png.rect);
    sfRenderWindow_drawSprite(game->win.window, game->play.png.sprite, NULL);
    sfSprite_setTextureRect(game->play.player.obj.sprite, game->play.player.obj.rect);
    sfSprite_setPosition(game->play.player.obj.sprite, game->play.player.obj.pos);
    sfRenderWindow_drawSprite(game->win.window, game->play.player.obj.sprite, NULL);
    sfRenderWindow_drawSprite(game->win.window, game->play.inventory.tools_bar.sprite, NULL);
}

static void draw_house(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.window, game->home.build.sprite, NULL);
    sfSprite_setPosition(game->play.bubble_int.sprite, game->play.bubble_int.pos);
    sfSprite_setTextureRect(game->play.bubble_int.sprite, game->play.bubble_int.rect);
    sfRenderWindow_drawSprite(game->win.window, game->play.bubble_int.sprite, NULL);
    draw_player(game);
    draw_slots(game);
    interact(game);
    if (on_collision(PLAYER.obj, game->play.png) && game->quest.is_talking == false) {
        sfRenderWindow_drawText(game->win.window, game->home.text_png.text, NULL);
    }
    if (game->quest.is_talking == true) {
        sfRenderWindow_drawSprite(game->win.window, game->home.box_text.sprite, NULL);
        sfRenderWindow_drawText(game->win.window, game->dial.quest_text.text, NULL);
        sfSprite_setTextureRect(game->home.arrow.sprite, game->home.arrow.rect);
        sfRenderWindow_drawSprite(game->win.window, game->home.arrow.sprite, NULL);
    }
}

void display(game_t *game)
{
    sfRenderWindow_clear(game->win.window, sfBlack);
    if (VIEW == MENU) {
        draw_menu(game);
    }
    if (VIEW == SPAWNV || VIEW == FORESTV) {
        sfSprite_setTexture(SCENE.sprite, SCENE.texture, sfTrue);
        sfRenderWindow_drawSprite(game->win.window, SCENE.sprite, NULL);
        if (VIEW == SPAWNV) {
            sfSprite_setTextureRect(game->shop.png.sprite, game->shop.png.rect);
            sfRenderWindow_drawSprite(game->win.window, game->shop.png.sprite, NULL);
        }
        draw_play(game);
        if (VIEW == SPAWNV)
            draw_shop(game);
    }
    if (VIEW == HOME) {
        draw_house(game);
    }
    if (game->play.inventory.show_invent == true && (VIEW == HOME || VIEW == SPAWNV || VIEW == FORESTV))
        draw_inventory(game);
    if (VIEW != MENU) {
        sfRenderWindow_drawText(game->win.window, game->env.hours_time.text, NULL);
        sfRenderWindow_drawText(game->win.window, game->env.hours_txt.text, NULL);
    }
    if (VIEW != MENU) {
        if (game->quest.mission_finish_rock == false || game->quest.mission_finish_slime == false)
            show_current_quest(game);
        sfRenderWindow_drawSprite(game->win.window, PLAYER.slimeball.sprite, NULL);
        sfText_setString(PLAYER.txt_slime.text, my_itoa(PLAYER.nb_slimeball));
        sfRenderWindow_drawText(game->win.window, PLAYER.txt_slime.text, NULL);
        draw_slots(game);
        sfSprite_setTextureRect(LVL.xp_bar.sprite, LVL.xp_bar.rect);
        sfRenderWindow_drawSprite(game->win.window, LVL.xp_bar.sprite, NULL);
        sfText_setString(LVL.lvl_txt.text, my_itoa(LVL.lvl));
        sfRenderWindow_drawText(game->win.window, LVL.lvl_txt.text, NULL);
    }
    if (VIEW == SPAWNV || VIEW == FORESTV || VIEW == HOME)
        draw_stat(game);
    if (HP <= 0) {
        sfRenderWindow_drawText(game->win.window, game->game_over.text, NULL);
    }
    if (VIEW != MENU && PAUSE == true) {
        sfRenderWindow_drawText(game->win.window, game->play.pause.text, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->play.button_resume.sprite, NULL);
        sfRenderWindow_drawSprite(game->win.window, game->play.button_quit.sprite, NULL);
    }
    sfRenderWindow_display(game->win.window);
}