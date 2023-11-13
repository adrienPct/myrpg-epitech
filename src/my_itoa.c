/*
** EPITECH PROJECT, 2021
** MY_ITOA.C
** File description:
** Transform a nb in str
*/

#include "rpg.h"

static int size_int(int value)
{
    int size = 0;
	for (; value != 0;) {
        value = value/10;
        size++;
    }
    return size;
}

char *my_itoa(int value)
{
    int size = size_int(value);
    char *nb_to_str = malloc(sizeof(char) * (size + 1));
    char c = '\0';
	int nb = value;
	int i = 0;
	
    if (nb == 0)
        return "0\0";
	if (value < 0)
		value *= -1;
    for (; value != 0; i++) {
        c = value % 10 + 48;
		value /= 10;
		nb_to_str[i] = c;
    }
	nb_to_str[i] = '\0';
	return my_revstr(nb_to_str);
}