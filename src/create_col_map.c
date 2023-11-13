/*
** EPITECH PROJECT, 2022
** create_col_map.c
** File description:
** create_col_map
*/

#include "rpg.h"

void create_spawn_col_map(game_t *game)
{
    int fd = open("map/spawn.txt", O_RDONLY);
    float x = - 64;
    float y = 0;
    int j = 0;

    game->play.spawn_col.size = 0;
    game->play.spawn_col.buffer = malloc(sizeof(char) * (1920 * 1100));
    read(fd, game->play.spawn_col.buffer, (1920 * 1100));
    close(fd);
    for (int i = 0; game->play.spawn_col.buffer[i] != 'e'; i++) {
        if (game->play.spawn_col.buffer[i] == 'x')
            game->play.spawn_col.size++;
    }
    game->play.spawn_col.colliders = malloc(sizeof(m_col_t) * (game->play.spawn_col.size));
    for (int i = 0; game->play.spawn_col.buffer[i] != 'e'; i++) {
        if (game->play.spawn_col.buffer[i] == 'x') {
            game->play.spawn_col.colliders[j].height = 64;
            game->play.spawn_col.colliders[j].width = 64;
            game->play.spawn_col.colliders[j].x = x;
            game->play.spawn_col.colliders[j].y = y;
            j++;
        }
        x += 64;
        if (game->play.spawn_col.buffer[i] == 'n') {
            x = - 64;
            y += 64;
        }
    }
    free(game->play.spawn_col.buffer);
}

map_col_t create_map_col(char *path)
{
    int fd = open(path, O_RDONLY);
    float x = -64;
    float y = 0;
    int j = 0;
    map_col_t col;

    col.size = 0;
    col.buffer = malloc(sizeof(char) * (1920 * 1100));
    read(fd, col.buffer, (1920 * 1100));
    close(fd);
    for (int i = 0; col.buffer[i] != 'e'; i++) {
        if (col.buffer[i] == 'x')
            col.size++;
    }
    col.colliders = malloc(sizeof(m_col_t) * (col.size));
    for (int i = 0; col.buffer[i] != 'e'; i++) {
        if (col.buffer[i] == 'x') {
            col.colliders[j].height = 64;
            col.colliders[j].width = 64;
            col.colliders[j].x = x;
            col.colliders[j].y = y;
            j++;
        }
        x += 64;
        if (col.buffer[i] == 'n') {
            x = - 64;
            y += 64;
        }
    }
    free(col.buffer);
    return col;
}