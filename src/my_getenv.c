/*
** EPITECH PROJECT, 2023
** my_getenv.c
** File description:
** getenv function
*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <string.h>
    #include "my.h"
    #include "minishell1.h"

void split_env_var(char *env_var, env_node_t *node)
{
    size_t len = my_strlen(env_var);
    char *equal_pos = my_strchr(env_var, '=');
    if (equal_pos == NULL) {
        node->name = my_strdup(env_var);
        node->value = NULL;
    } else {
        size_t name_len = equal_pos - env_var;
        node->name = malloc((name_len + 1) * sizeof(char));
        if (node->name == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        my_strncpy(node->name, env_var, name_len);
        node->name[name_len] = '\0';
        node->value = malloc((len - name_len + 1) * sizeof(char));
        if (node->value == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        } my_strcpy(node->value, equal_pos + 1);
    }
}

void add_env_node_to_list(env_node_t **head_ptr,
        env_node_t **tail_ptr, env_node_t *node)
{
    if (*head_ptr == NULL) {
        *head_ptr = node;
        *tail_ptr = node;
    } else {
        (*tail_ptr)->next = node;
        *tail_ptr = node;
    }
}

env_node_t *getenvlist(char **env)
{
    env_node_t *head = NULL;
    env_node_t *tail = NULL;

    for (env; *env != NULL; env++) {
        char *env_var = *env;
        env_node_t *new_node = malloc(sizeof(env_node_t));
        if (new_node == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        split_env_var(env_var, new_node);
        new_node->next = NULL;
        add_env_node_to_list(&head, &tail, new_node);
    }

    return head;
}

char *my_getenv(char *name, env_node_t **env_list_ptr)
{
    env_node_t *curr = NULL;
    size_t name_len = my_strlen(name);
    for (curr = *env_list_ptr; curr != NULL; curr = curr->next) {
        if (my_strncmp(curr->name, name, name_len) == 0) {
            return curr->value;
        }
    }
    return NULL;
}
