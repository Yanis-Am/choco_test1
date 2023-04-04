/*
** EPITECH PROJECT, 2023
** my_setenv.c
** File description:
** setenv
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"
#include "minishell1.h"
#include "errno.h"

char *create_env_var(char *name, char *value)
{
    size_t name_len = my_strlen(name);
    char *new_env_var = malloc(name_len + my_strlen(value) + 2);
    if (new_env_var == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_env_var = my_strcpy(new_env_var, name);
    new_env_var = my_strcat(new_env_var, "=");
    new_env_var = my_strcat(new_env_var, value);
    return new_env_var;
}

void update_env_var(env_node_t *env_list, char *name, char *value, int ov)
{
    char **env;
    size_t name_len = my_strlen(name);
    for (env = env_list_to_char_array(env_list); *env != NULL; ++env) {
        if (my_strncmp(*env, name, name_len) == 0
            && (*env)[name_len] == '=' && ov) {
            char *new_env_var = create_env_var(name, value);
            *env = my_strdup(new_env_var);
            free(new_env_var);
            return;
        }
    }
    char *new_env_var = create_env_var(name, value);
    *env = my_strdup(new_env_var);
    free(new_env_var);
    *(env + 1) = NULL;
}

env_node_t *create_new_node(char *name, char *value)
{
    env_node_t *new_node = malloc(sizeof(env_node_t));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    size_t name_len = my_strlen(name);
    new_node->name = malloc((name_len + 2) * sizeof(char));
    if (new_node->name == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    my_strncpy(new_node->name, name, name_len);
    new_node->name[name_len + 1] = '\0';
    new_node->value = my_strdup(value);
    new_node->next = NULL;
    return new_node;
}

void upd_or_add_var(env_node_t **env_list_ptr, char *name, char *value, int ov)
{
    env_node_t *env_list = *env_list_ptr;
    env_node_t *curr = NULL;
    env_node_t *prev = NULL;

    for (curr = env_list; curr != NULL; prev = curr, curr = curr->next) {
        if (my_strcmp(curr->name, name) == 0 && ov) {
                free(curr->value);
                curr->value = my_strdup(value);
                return;
        }
    }
    env_node_t *new_node = create_new_node(name, value);
    if (prev == NULL)
        env_list = new_node;
    else
        prev->next = new_node;
    *env_list_ptr = env_list;
}

int my_setenv(char *name, char *value, env_node_t **env_list_ptr, int ov)
{
    env_node_t *env_list = *env_list_ptr;
    env_node_t *curr = NULL;
    env_node_t *prev = NULL;
    size_t name_len = my_strlen(name);
    if (!is_valid_variable_name(name)) {
        return 1;
    }
    split_name(name);
    upd_or_add_var(env_list_ptr, name, value, ov);
    update_env_var(env_list, name, value, ov);
    return 0;
}
