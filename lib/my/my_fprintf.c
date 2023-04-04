/*
** EPITECH PROJECT, 2023
** my_fprintf.c
** File description:
** fprintf
*/

#include "my.h"

void my_fprintf(const char *str, int fd)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    write(fd, str, len);
}
