/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse a string 
*/

char *my_revstr(char *str)
{
    int taille = 0;

    while (str[taille] != '\0'){
        taille++;
    }
    int start = 0;
    int end = taille - 1;
    int len = taille;
    char temp;

    while (start != len / 2){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}
