/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-guillaume.lemoine
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define UNUSED() __attribute__((unused))
    #include <stddef.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <dirent.h>

typedef struct s_node {
    char *key;
    char *value;
    struct s_node *next;
} t_node;

typedef struct s_tree {
    char *cmd;
    char *operator;
    int fdin;
    int fdout;
    struct s_tree *left;
    struct s_tree *right;
} tree_t;

typedef struct s_console {
    char *console;
    char **args;
    t_node *env_nodes;
    char *cmd;
    size_t length;
    char pwd[1024];
    int child;
    int status;
} shell_t;

typedef struct array {
    char **array;
    int i;
    int target;
    int index;
    int cpy;
} array_t;

t_node *char_to_node(char **env);
char *get_param(t_node *env, const char *param);
void my_putchar(char ch);
void my_env(t_node *env);
char *my_strdup(char const *src);
void my_cd (shell_t *shell);
int my_strlen(char const *str);
char **my_strtok(char *str, char *separators);
char **my_str_to_word_array_3(char *str);
int is_in(const char *str, char ch);
void my_unsetenv(shell_t *shell);
void my_setenv(shell_t *shell);
char *where_is_cmd(char *cmd, t_node *environement);
int handle_cmds(shell_t *shell);
char **my_links_to_word_array(char const *str);
int get_args_quantity(char **args);
char **my_str_to_word_array(char *str);
char **node_to_array(t_node *env);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_printf(const char *format, ...);

#endif
