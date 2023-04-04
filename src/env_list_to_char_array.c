/*
** EPITECH PROJECT, 2023
** env_list_to_char_array.c
** File description:
** fx
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"
#include "minishell1.h"

int get_env_count(env_node_t *env_list)
{
    int count = 0;
    env_node_t *node = env_list;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

char **alloc_env_array(int count)
{
    char **envp = malloc((count + 1) * sizeof(char *));
    if (envp == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return envp;
}

void copy_env_node_to_array(char **envp, env_node_t *node, int index)
{
    char *env_var = malloc(my_strlen(node->name) +
                            my_strlen(node->value) + 2);
    if (env_var == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    env_var = my_strcpy(env_var, node->name);
    env_var = my_strcat(env_var, "=");
    env_var = my_strcat(env_var, node->value);
    envp[index] = env_var;
}

char **env_list_to_char_array(env_node_t *env_list)
{
    int count = get_env_count(env_list);
    char **envp = alloc_env_array(count);
    env_node_t *node = env_list;
    for (int i = 0; i < count; i++) {
        copy_env_node_to_array(envp, node, i);
        node = node->next;
    }
    envp[count] = NULL;
    return envp;
}
