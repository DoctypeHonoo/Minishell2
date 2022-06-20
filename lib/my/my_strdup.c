/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** duplicates a string in a new area
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}
