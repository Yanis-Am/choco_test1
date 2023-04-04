/*
** EPITECH PROJECT, 2022
** my_radar.h
** File description:
** radar header
*/

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_RESET   "\x1b[0m"
    #include <stdlib.h>
    #include <stdio.h>

typedef struct env_node {
    char *name;
    char *value;
    struct env_node *next;
} env_node_t;

char *my_getenv(char *name, env_node_t **env_list_ptr);

char **split(char *info, char *limit);

char *get_path(char** cmd, env_node_t **env_list_ptr);

int my_cd(char *path, env_node_t **env_list_ptr);

int my_setenv(char *name, char *value,
            env_node_t **env_list_ptr, int overwrite);

int my_unsetenv(void);

env_node_t *getenvlist(char **env);

void print_env_list(env_node_t *env_list);

char **env_to_array(char **envp);

char **env_list_to_char_array(env_node_t *env_list);

int is_valid_variable_name(char *name);

void split_name(char *name);

void get_commands(char **cmd, env_node_t **env_list_ptr);

int exec_path(char **cmd, env_node_t **env_list_ptr);

#endif /* !MY_RADAR_H_ */
