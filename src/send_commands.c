/*
** EPITECH PROJECT, 2023
** send_commands.c
** File description:
** commands sender
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"
#include "minishell1.h"

static int is_empty(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!my_isspace(str[i])) {
            return 0;
        }
    }
    return 1;
}

static void execute_cd(char **cmd, env_node_t **env_list)
{
    if (cmd[2] != NULL) {
        my_fprintf("cd: too many arguments\n", 2);
        return;
    }
    if (cmd[1] == NULL) {
        return my_cd(NULL, env_list);
    } else {
        return my_cd(cmd[1], env_list);
    }
}

static void execute_setenv(char **cmd, env_node_t **env_list)
{
    if (cmd[1] == NULL) {
        return print_env(*env_list);
    } else if (cmd[2] == NULL) {
        return my_setenv(cmd[1], "", env_list, 1);
    } else {
        return my_setenv(cmd[1], cmd[2], env_list, 1);
    }
}

static void execute_command(char **cmd, env_node_t **env_list)
{
    if (my_strncmp(cmd[0], "cd", 2) == 0) {
        return execute_cd(cmd, env_list);
    } else if (my_strncmp(cmd[0], "setenv", 6) == 0) {
        return execute_setenv(cmd, env_list);
    } else {
        return exec_path(&cmd[0], env_list);
    }
}

void get_commands(char **cmd, env_node_t **env_list_ptr)
{
    env_node_t *env_list = *env_list_ptr;
    size_t i = 0;
    if (cmd == NULL || cmd[0] == NULL) {
        return;
    }
    while (cmd[i] != NULL) {
        if (is_empty(cmd[i])) {
            continue;
        }
        return execute_command(&cmd[i], &env_list);
        i++;
    }
    *env_list_ptr = env_list;
}
