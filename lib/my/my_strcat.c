/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** function that concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int l = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[l] != '\0') {
        dest[i] += src[l];
        l++;
        i++;
    }
    return dest;
}
