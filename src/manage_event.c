/*
** EPITECH PROJECT, 2022
** manage_event.c
** File description:
** manage_event
*/

#include "rpg.h"

static void text_png_reduc(game_t *game)
{
    if (game->quest.can_destroy == false || game->quest.destroy == false) {
        if (game->dial.i == 0) {
            game->dial.i = 1;
        } else if (game->dial.i == 1) {
            sfText_setString(game->dial.quest_text.text, "condemns the forest. Because\nof this rock no one can go to the\nforest, it is invaded by slime.");
            game->dial.i = 2;
        } else if (game->dial.i == 2) {
            sfText_setString(game->dial.quest_text.text, " We need someone strong to kill\nthem and free the forest.");
            game->dial.i = 3;
        } else if (game->dial.i == 3) {
            sfText_setString(game->dial.quest_text.text, "Your first mission is to\nremove the rock.");
            game->dial.i = 4;
        } else if (game->dial.i == 4) {
            game->dial.player_can_move = true;
            game->quest.is_talking = false;
            game->quest.can_destroy = true;
        }
    }
}

static void text_png_reduc2(game_t *game)
{   
    if (game->quest.destroy == true) {
        sfText_setString(game->dial.quest_text.text, "Congratulations, you have\nsuccessfully completed your \nfirst mission !");
        if (game->dial.i == 5) {
            game->dial.i = 6;
        } else if (game->dial.i == 6) {
            sfText_setString(game->dial.quest_text.text, "Now you have to save the village by \nkilling the forest slimes");
            game->dial.i = 7;
        } else if (game->dial.i == 7) {
            sfText_setString(game->dial.quest_text.text, "Now you have to save the village by \nkilling the forest slimes");
            game->dial.player_can_move = true;
            game->quest.is_talking = false;
            game->quest.mission_finish_rock = true;
            game->quest.can_destroy = false;
        }
    }
}

static void text_png_reduc3(game_t *game)
{   
    if (game->quest.kill_slime == true) {
        if (game->dial.i == 8) {
            sfText_setString(game->dial.quest_text.text, "Congratulations, you save the village !");
            game->dial.player_can_move = true;
            game->quest.is_talking = false;
            game->quest.mission_finish_slime = true;
        }
    }
}

void experience_quest(game_t *game)
{
    if (game->quest.mission_finish_rock == true && game->quest.xp_first_quest == false) {
        LVL.xp = 10;
        check_xp(game);
        game->quest.xp_first_quest = true;
    }
    if (game->quest.mission_finish_slime == true && game->quest.xp_seconde_quest == false) {
        LVL.xp = 10;
        check_xp(game);
        game->quest.xp_seconde_quest = true;
    }
}

int manage_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win.window, &game->win.event)) {
        game->pos_mouse = sfMouse_getPositionRenderWindow(game->win.window);
        if (PAUSE == false) {
            manage_inventory(game);
            manage_shop(game);
            manage_house(game);
        }
        if (on_collision(PLAYER.obj, game->play.png) && sfKeyboard_isKeyPressed(sfKeyE)
            && VIEW == HOME) {
            game->play.bubble_int.rect.left = 0;
            game->quest.is_talking = true;
            game->dial.player_can_move = false;
            sfSound_play(game->sound.talk);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->win.event.key.code == sfKeyEscape && PAUSE == false && VIEW != MENU) {
            PAUSE = true;
            game->dial.player_can_move = false;
        } else if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->win.event.key.code == sfKeyEscape && PAUSE == true && VIEW != MENU) {
            PAUSE = false;
            game->dial.player_can_move = true;
        }
        if (PAUSE == false && object_is_col_vector(game->home.arrow, game->pos_mouse) && sfMouse_isButtonPressed(sfMouseLeft) && game->win.event.key.code == sfMouseLeft) {
            text_png_reduc(game);
            text_png_reduc2(game);
            text_png_reduc3(game);
            sfSound_play(game->sound.button);
        }
        if (game->win.event.type == sfEvtClosed) {
            sfRenderWindow_close(game->win.window);
        }
        manage_rock(game);
        manage_message_comming(game);
        tools_bar(game);
        if (VIEW == MENU) {
            manage_menu(game);
        }
        if (VIEW == FORESTV || VIEW == SPAWNV || VIEW == HOME) {
            manage_player(game);
            manage_house(game);
        }
        if (VIEW == FORESTV || VIEW == SPAWNV || VIEW == HOME && game->play.inventory.show_invent == true) {
            manage_stat(game);
        }
        if (VIEW != MENU && PAUSE == true) {
            manage_pause(game);
        }
    }
}