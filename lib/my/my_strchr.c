/*
** EPITECH PROJECT, 2023
** strchr.c
** File description:
** strchr fx
*/

#include <stdio.h>

char *my_strchr(const char *s, int c)
{
    while (*s != '\0') {
        if (*s == c) {
            return (char *)s;
        }
        s++;
    }
    if (c == '\0') {
        return (char *)s;
    }
    return NULL;
}
