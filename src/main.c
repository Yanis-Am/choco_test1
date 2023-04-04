/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "minishell1.h"

char **env_to_array(char **envp)
{
    int num_vars = 0;
    char **p = envp;
    while (*p != NULL) {
        num_vars++;
        p++;
    }
    char **env_array = (char **) malloc(sizeof(char *) * (num_vars + 1));
    if (env_array == NULL)
        return NULL;
    int i = 0;
    p = envp;
    while (*p != NULL) {
        env_array[i] = *p;
        i++;
        p++;
    }
    env_array[i] = NULL;
    return env_array;
}

int exec_path(char **cmd, env_node_t **env_list_ptr)
{
    env_node_t *envlist = *env_list_ptr;
    char **envp = env_list_to_char_array(envlist);
    int status = 0;
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
        return -1;
    }
    if (pid == 0) {
        char *path = get_path(cmd, env_list_ptr);
        if (path == NULL){
            my_putstr(cmd[0]);
            my_putstr(": Command not found.\n");
            exit(ENOENT);
        }
        if (execve(path, cmd, envp) == -1) {
            free(path);
            exit(EXIT_FAILURE);
        } free(path);
    } waitpid(pid, &status, 0);
}

char **split(char *info, char *limit)
{
    if (info == NULL || limit == NULL || limit[0] == '\0')
        return NULL;
    char **cmd = NULL;
    size_t index = 0;
    char *ptr = strtok(info, limit);
    while (ptr != NULL) {
        cmd = my_realloc(cmd, (index + 1) * sizeof(char *));
        if (cmd == NULL)
            return NULL;
        cmd[index] = my_strdup(ptr);
        if (cmd[index] == NULL)
            return NULL;
        ptr = strtok(NULL, limit);
        index++;
    }
    cmd = my_realloc(cmd, (index + 1) * sizeof(char *));
    if (cmd == NULL)
        return NULL;
    cmd[index] = NULL;
    return cmd;
}

void print_env(env_node_t *env_list)
{
    while (env_list != NULL) {
        my_putstr(env_list->name);
        my_putstr("=");
        my_putstr(env_list->value);
        my_putchar('\n');
        env_list = env_list->next;
    }
}

int main(int ac, char **av, char **env)
{
    ssize_t read;
    char *info = NULL;
    size_t len = 2048;
    env_node_t *env_list = getenvlist(env);
    env = env_list_to_char_array(env_list);
    info = malloc(sizeof(info) + len);
    while (1){
        if (isatty(0) != 0)
            my_putstr(ANSI_COLOR_GREEN "minishell_1$>" ANSI_COLOR_RESET);
        if (getline(&info, &len, stdin) == -1)
            return 0;
        if (my_strlen(info) > 1){
            char **cmd = split(info, "  \n\t");
            get_commands(cmd, &env_list);
            free_tab(cmd);
        }
    }
    free(info);
    return EXIT_SUCCESS;
}
