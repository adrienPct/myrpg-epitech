/*
** EPITECH PROJECT, 2022
** set_text.c
** File description:
** aa
*/

#include "rpg.h"

void set_text(text_t *text, int size, sfVector2f pos, char *what)
{
    text->text = sfText_create();
    text->font = sfFont_createFromFile("font/tuto.ttf");
    text->pos = pos;
    text->size = size;
    text->color = sfWhite;

    sfText_setString(text->text, what);
    sfText_setPosition(text->text, pos);
    text->start_pos = text->pos;
    sfText_setFont(text->text, text->font);
    sfText_setColor(text->text, sfWhite);
    sfText_setCharacterSize(text->text, size);
}