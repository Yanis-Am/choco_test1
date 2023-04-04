/*
** EPITECH PROJECT, 2023
** my_cd.c
** File description:
** cd builtin
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "minishell1.h"
#include "my.h"

int cd_home(env_node_t **env_list_ptr, char *cwd                                                    )
{
    char *home = my_getenv("HOME", env_list_ptr);
    int ret = chdir(home);
    my_setenv("OLDPWD", cwd, env_list_ptr, 1);
    my_setenv("PWD", home, env_list_ptr, 1);
    return ret;
}

int cd_prev(env_node_t **env_list_ptr, char *cwd)
{
    char *old_cwd = my_getenv("OLDPWD", env_list_ptr);

    if (old_cwd == NULL) {
        my_putstr(": No such file or directory.\n");
        return 0;
    }
    int ret = chdir(old_cwd);
    my_setenv("OLDPWD", cwd, env_list_ptr, 1);
    my_setenv("PWD", old_cwd, env_list_ptr, 1);
    return ret;
}

int simple_cd(char *path, env_node_t **env_list_ptr, char *cwd)
{
    int ret = chdir(path);

    if (ret == 0) {
        my_setenv("OLDPWD", cwd, env_list_ptr, 1);
        char *new_cwd = getcwd(NULL, 0);
        my_setenv("PWD", new_cwd, env_list_ptr, 1);
        free(new_cwd);
    }
    return ret;
}

int my_cd(char *path, env_node_t **env_list_ptr)
{
    char *cwd = getcwd(NULL, 0);
    int ret = -1;

    if (path == NULL || my_strcmp(path, "~") == 0) {
        ret = cd_home(env_list_ptr, cwd);
    } else if (my_strcmp(path, "-") == 0) {
        ret = cd_prev(env_list_ptr, cwd);
    } else {
        ret = simple_cd(path, env_list_ptr, cwd);
    }
    free(cwd);
    if (ret != 0) {
        perror("cd");
        return -1;
    }
    return 0;
}
