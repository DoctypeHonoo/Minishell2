/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-guillaume.lemoine
** File description:
** node_to_array
*/

#include "../../include/my.h"

char **node_to_array(t_node *env)
{
    t_node *cpy = env;
    t_node *cpy2 = env;
    int i = 0;

    for (; cpy->next; i++)
        cpy = cpy->next;
    char **env_array = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++) {
        env_array[j] = malloc(sizeof(char) * (my_strlen(cpy2->key) +
        my_strlen(cpy2->value) + 2));
        cpy2 = cpy2->next;
    }
    for (int j = 0; j < i; j++) {
        my_strcat(env_array[j], env->key);
        my_strcat(env_array[j], "=");
        my_strcat(env_array[j], env->value);
        env = env->next;
    }
    return env_array;
}
