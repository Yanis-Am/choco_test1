/*
** EPITECH PROJECT, 2023
** get_path.c
** File description:
** path fx
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"
#include "minishell1.h"

static char *find_executable(char **env_tok, char **cmd)
{
    char *exec = NULL;
    for (int i = 0; env_tok[i]; i++) {
        int env_tok_len = my_strlen(env_tok[i]);
        int cmd_len = my_strlen(cmd[0]);
        exec = malloc((env_tok_len + cmd_len + 2) * sizeof(char));
        if (exec == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        my_strcpy(exec, env_tok[i]);
        my_strcat(exec, "/");
        my_strcat(exec, cmd[0]);
        if (access(exec, F_OK) == 0) {
            return exec;
        }
        free(exec);
        exec = NULL;
    }
    return NULL;
}

char *get_path(char** cmd, env_node_t **env_list_ptr)
{
    char* envi = my_getenv("PATH", env_list_ptr);
    char *exec = NULL;
    if (envi == NULL)
        envi = my_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
    if (cmd[0][0] != '/' && my_strncmp(cmd[0], "./", 2) != 0) {
        char **env_tok = split(envi, ":");
        free(envi);
        envi = NULL;
        exec = find_executable(env_tok, cmd);
        free_tab(env_tok);
        if (exec == NULL)
            return NULL;
        char *path = my_strdup(exec);
        free(exec);
        exec = NULL;
        return path;
    } else {
        free(envi);
        envi = NULL;
    }
}
