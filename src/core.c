/*
** EPITECH PROJECT, 2022
** core.c
** File description:
** main
*/

#include "rpg.h"

static void my_help()
{
    write(1, "\n", 1);
    write(1, "To launch the game write in the terminal ./my_rpg\n", 51);
    write(1, "\n", 2);
    write(1, "If you get stuck in a wall,\npress all arrow keys until you unlock!\n", 70);
    write(1, "\n", 1);
}

int main(int ac)
{
    game_t game;
    
    if (ac > 1) {
        my_help();
        return 0;
    }
    set_all(&game);
    loop_window(&game);
    return 0;
}