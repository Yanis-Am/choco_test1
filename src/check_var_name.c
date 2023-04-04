/*
** EPITECH PROJECT, 2023
** check var
** File description:
** var fx
*/

#include "my.h"
#include <stdio.h>

int is_valid_variable_name(char *name)
{
    for (size_t i = 0; i < my_strlen(name); i++) {
        if (!my_isalnum(name[i])) {
            my_putstr("setenv: Variable name must " \
            "contain alphanumeric characters.\n");
            return 0;
        }
    }
    return 1;
}

void split_name(char *name)
{
    char *equal_sign = my_strchr(name, '=');
    if (equal_sign != NULL) {
        size_t name_len = equal_sign - name;
        name[name_len] = '\0';
    }
}
