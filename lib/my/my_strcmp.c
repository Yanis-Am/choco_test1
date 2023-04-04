/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** strcmp
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 < *s2) ? -1 : 1;
        }
        s1++;
        s2++;
    }
    return (*s1 == '\0' && *s2 == '\0') ? 0 : ((*s1 == '\0') ? -1 : 1);
}
