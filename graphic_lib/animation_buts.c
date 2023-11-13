/*
** EPITECH PROJECT, 2022
** animation_buts.c
** File description:
** animation_buts
*/

#include "graphic_lib.h"
#include "game.h"
#define BUTTON 4

static int is_click(obj_t object, sfVector2i pos_mouse)
{
    if ((pos_mouse.x >= object.collider.left) 
    && (pos_mouse.x <= object.collider.right) 
    && (pos_mouse.y >= object.collider.top) 
    &&  (pos_mouse.y <= object.collider.bot)) {
        return 1;
    }
    return 0;
}

void animation_buts(sfRenderWindow *window, obj_tab_t tab, sfVector2i pos_mouse)
{
    pos_mouse = sfMouse_getPositionRenderWindow(window);
    for (int i = 0; i != tab.size; i++) {
        if (is_click(tab.tab[i], pos_mouse) && tab.tab[i].tag == BUTTON) {
            tab.tab[i].pos.x = tab.tab[i].start_pos.x + 5;
            tab.tab[i].pos.y = tab.tab[i].start_pos.y + 5;
            sfSprite_setPosition(tab.tab[i].sprite, tab.tab[i].pos);
        } else if (tab.tab[i].tag == BUTTON) {
            tab.tab[i].pos.x = tab.tab[i].start_pos.x;
            tab.tab[i].pos.y = tab.tab[i].start_pos.y;
            sfSprite_setPosition(tab.tab[i].sprite, tab.tab[i].pos);
        }
    }
}

void animation_solo_buts(sfRenderWindow *window, obj_t obj, sfVector2i pos_mouse)
{
    pos_mouse = sfMouse_getPositionRenderWindow(window);
    if (is_click(obj, pos_mouse)) {
        obj.pos.x = obj.start_pos.x - 5;
        obj.pos.y = obj.start_pos.y - 5;
        sfSprite_setPosition(obj.sprite, obj.pos);
    } else {
        obj.pos.x = obj.pos.x + 5;
        obj.pos.y = obj.pos.y + 5;
        sfSprite_setPosition(obj.sprite, obj.pos);
    }
}

void animation_solo_buts_little(sfRenderWindow *window, obj_t obj, sfVector2i pos_mouse)
{
    pos_mouse = sfMouse_getPositionRenderWindow(window);
    if (is_click(obj, pos_mouse)) {
        obj.pos.x = obj.start_pos.x - 1;
        obj.pos.y = obj.start_pos.y - 1;
        sfSprite_setPosition(obj.sprite, obj.pos);
    } else {
        obj.pos.x = obj.pos.x + 1;
        obj.pos.y = obj.pos.y + 1;
        sfSprite_setPosition(obj.sprite, obj.pos);
    }
}

void animation_shop(sfRenderWindow *window, obj_t obj, sfVector2i pos_mouse, text_t text)
{
    pos_mouse = sfMouse_getPositionRenderWindow(window);
    if (is_click(obj, pos_mouse)) {
        obj.pos.x = obj.start_pos.x + 2;
        obj.pos.y = obj.start_pos.y + 2;
        text.pos.x = text.start_pos.x + 2;
        text.pos.y = text.start_pos.y + 2;
        sfText_setPosition(text.text, text.pos);
        sfSprite_setPosition(obj.sprite, obj.pos);
    } else {
        obj.pos.x = obj.pos.x - 2;
        obj.pos.y = obj.pos.y - 2;
        text.pos.x = text.pos.x - 2;
        text.pos.y = text.pos.y - 2;
        sfText_setPosition(text.text, text.pos);
        sfSprite_setPosition(obj.sprite, obj.pos);
    }
}