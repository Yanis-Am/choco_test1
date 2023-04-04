/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** memory allocation fx
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    if (str == NULL)
        return NULL;
    size_t len = my_strlen(str);
    char *new_str = malloc(len + 1);
    if (new_str != NULL) {
        my_strcpy(new_str, str);
    }
    return new_str;
}
