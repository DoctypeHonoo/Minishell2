/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_links_to_word_array
*/

#include "../../include/my.h"

int check_alpha_2(char ch)
{
    if (ch == ':')
        return 0;
    return 1;
}

int calc_words_2(char const *str)
{
    int i = 0;
    int words = 1;

    while (str[i] != '\0') {
        if (check_alpha_2(str[i]) == 0)
            words++;
        i++;
    }
    return words;
}

int word_size_2(char const *str, int target)
{
    int size = 0;

    while (check_alpha_2(str[target]) == 1 && str[target] != '\0') {
        size++;
        target++;
    }
    return size;
}

char **myltwa_sec(array_t arr, char const *str, int words)
{
    while (str[arr.target] != '\0') {
        int size = word_size_2(str, arr.target);
        arr.array[arr.index] = malloc(sizeof(char) * (size + 1));
        arr.cpy = arr.target;
        while (str[arr.target] != str[arr.cpy + size]) {
            arr.array[arr.index][arr.i] = str[arr.target];
            arr.target++;
            arr.i++;
        }
        arr.array[arr.index][arr.i] = '\0';
        arr.target++;
        arr.index++;
        arr.i = 0;
    }
    arr.array[words] = NULL;
    return arr.array;
}

char **my_links_to_word_array(char const *str)
{
    int words = calc_words_2(str);
    array_t arr;

    arr.array = malloc(sizeof(char *) * (words + 1));
    arr.cpy = 0;
    arr.i = 0;
    arr.index = 0;
    arr.target = 0;
    return myltwa_sec(arr, str, words);
}
