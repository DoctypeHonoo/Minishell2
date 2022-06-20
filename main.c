/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-guillaume.lemoine
** File description:
** main
*/

#include "include/my.h"

int execute_semi_colonne(shell_t *shell)
{
    int j = 0;

    for (int i = 0; shell->console[i + 1]; i++)
        if (shell->console[i] != ';')
            j++;
    if (j == 0)
        return 0;
    if (shell->console[my_strlen(shell->console) - 2] == ';') {
        for (int i = 0; my_strtok(shell->console, ";")[i + 1]; i++) {
            shell->args = my_str_to_word_array(my_strtok(shell->console, ";")[i]);
            if (handle_cmds(shell) == 84)
                return 84;
        }
    } else {
        for (int i = 0; my_strtok(shell->console, ";")[i]; i++) {
            shell->args = my_str_to_word_array(my_strtok(shell->console, ";")[i]);
            if (handle_cmds(shell) == 84)
                return 84;
        }
    }
    return 0;
}

int main(int argc UNUSED(), char **argv UNUSED(), char **env)
{
    shell_t shell = {.console = NULL, .env_nodes = char_to_node(env),
    .length = 0};

    while (42) {
        if (isatty(0))
            my_printf("╚> %s 》", getcwd(shell.pwd, sizeof(shell.pwd)));
        if (getline(&shell.console, &shell.length, stdin) == -1)
            return 0;
        if (my_strcmp(shell.console, "\n") == 0)
            continue;
        else
            shell.console[shell.length - 1] = '\0';
        if (execute_semi_colonne(&shell) == 84)
            return 84;
    }
    return 0;
}
