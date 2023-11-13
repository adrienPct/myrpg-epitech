/*
** EPITECH PROJECT, 2022
** tools_bar.c
** File description:
** tools_bar
*/

#include "rpg.h"

void tools_bar(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
    {
        game->play.inventory.tools_bar.rect.top = 0;
        game->play.inventory.act_tool = 0;
        SLOT = ONE;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
    {
        game->play.inventory.tools_bar.rect.top = 80;
        game->play.inventory.act_tool = 1;
        SLOT = TWO;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
    {
        game->play.inventory.tools_bar.rect.top = 160;
        game->play.inventory.act_tool = 2;
        SLOT = THREE;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
    {
        game->play.inventory.tools_bar.rect.top = 240;
        game->play.inventory.act_tool = 3;
        SLOT = FOURTH;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum5))
    {
        game->play.inventory.tools_bar.rect.top = 320;
        game->play.inventory.act_tool = 4;
        SLOT = FIVE;
    }
}