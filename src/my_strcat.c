/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** return str
*/

char *my_strcat(char *dest, char const *src)
{
    int len = 0;
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * 10);

    for (; dest[len] != '\0'; len++)
        new[len] = dest[len];
    for (; src[i] != '\0'; i++) {
        new[len] = src[i];
        len++;
    }
    new[len] = '\0';
    return new;
}