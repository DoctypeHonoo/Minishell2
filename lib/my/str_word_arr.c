/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-guillaume.lemoine
** File description:
** str_word_arr
*/

#include "../../include/my.h"

int check_alpha_3(char ch)
{
    if (ch == ';')
        return 0;
    return 1;
}

int calc_words_3(char const *str)
{
    int i = 0;
    int words = 1;
    int still = 0;

    while (str[i] != '\0') {
        if (check_alpha_3(str[i]) && still)
            still = 0;
        if (check_alpha_3(str[i]) == 0 && still == 0) {
            words++;
            still = 1;
        }
        i++;
    }
    return words;
}

char **my_str_to_word_array_3(char *str)
{
    int words = calc_words_3(str);
    char **array = malloc(sizeof(char *) * (words + 1));
    char *token = strtok(str, ";");
    int i = 0;

    for (i = 0; token; i++) {
        array[i] = my_strdup(token);
        token = strtok(NULL, ";");
    }
    //array[words] = NULL;
    return array;
}
