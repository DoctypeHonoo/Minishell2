/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-guillaume.lemoine
** File description:
** execute_binary
*/

#include "../../include/my.h"

int exec_binary_2(shell_t *shell)
{
    int signal = WTERMSIG(shell->status);

    if (signal == 0)
        return 0;
    if (!my_strcmp(strsignal(signal), "Floating point exception"))
        my_printf("Floating exception");
    else
        my_printf("%s", strsignal(signal));
    if (WCOREDUMP(shell->status))
        my_printf(" (core dumped)");
    my_printf("\n");
    return 0;
}

int check_exec_binary(shell_t *shell)
{
    DIR *directory = opendir(shell->args[0]);

    if (directory != NULL && is_in(shell->args[0], '/')) {
        my_printf("%s: Permission denied.\n", shell->args[0]);
        exit(0);
    }
    if (is_in(shell->args[0], '/')) {
        execve(shell->args[0], shell->args,
            node_to_array(shell->env_nodes));
        exit(0);
    } else {
        my_printf("%s: Command not found.\n", shell->args[0]);
        exit(0);
    }
}

int exec_binary(shell_t *shell)
{
    int a = 0;

    shell->cmd = where_is_cmd(shell->args[0], shell->env_nodes);
    shell->child = fork();
    if (shell->child == 0) {
        if (shell->cmd != NULL) {
            a = execve(shell->cmd, shell->args, node_to_array(shell->env_nodes));
        }
        if (a == -1) {
            my_printf("%s: Exec format error. Wrong Architecture.\n", shell->cmd);
            exit(0);
        }
        if (access(shell->args[0], F_OK) == -1) {
            my_printf("%s: Command not found.\n", shell->args[0]);
            exit(0);
        }
        check_exec_binary(shell);
    } else if (waitpid(shell->child, &shell->status, 0) == 1)
        return 84;
    return exec_binary_2(shell);
}

int handle_cmds_2(shell_t *shell)
{
    if (my_strcmp(shell->args[0], "unsetenv") == 0) {
        my_unsetenv(shell);
        return 0;
    }
    if (my_strcmp(shell->args[0], "setenv") == 0) {
        my_setenv(shell);
        return 0;
    }
    return exec_binary(shell);
}

int handle_cmds(shell_t *shell)
{
    if (my_strcmp(shell->args[0], "cd") == 0) {
        my_cd(shell);
        return 0;
    }
    if (my_strcmp(shell->args[0], "env") == 0) {
        my_env(shell->env_nodes);
        return 0;
    }
    if (my_strcmp(shell->args[0], "exit") == 0) {
        my_printf("exit\n");
        exit(0);
    }
    return handle_cmds_2(shell);
}
