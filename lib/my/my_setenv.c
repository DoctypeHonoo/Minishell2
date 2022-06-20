/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_setenv
*/

#include <stdlib.h>
#include "../../include/my.h"

void my_setenv_2(shell_t *shell)
{
    t_node *cpy = shell->env_nodes;
    t_node *new = malloc(sizeof(t_node));
    char *charset2 = "~{}^[\\@?=:/-,+*";

    for (int i = 1; shell->args[1][i] != '\0'; i++) {
        if (is_in(charset2, shell->args[1][i])) {
            my_printf("setenv: Variable name must contain \
alphanumeric characters.\n");
            return;
        }
    }
    while (cpy->next && my_strcmp(cpy->next->key, shell->args[1]) != 0)
        cpy = cpy->next;
    new->key = shell->args[1];
    if (get_args_quantity(shell->args) == 2)
        new->value = "";
    else
        new->value = shell->args[2];
    cpy->next = new;
}

void my_setenv(shell_t *shell)
{
    char *charset = "=?/@[\\]^`{}~*1234567890";

    if (get_args_quantity(shell->args) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return;
    }
    if (get_args_quantity(shell->args) == 1) {
        my_env(shell->env_nodes);
        return;
    }
    if (is_in(charset, shell->args[1][0])) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return;
    }
    my_setenv_2(shell);
}
