/*
** EPITECH PROJECT, 2023
** my_memcpy.c
** File description:
** memcpy
*/

#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    if (dest == NULL || src == NULL)
        return NULL;
    char *char_dest = dest;
    const char *char_src = src;
    size_t i;
    for (i = 0; i < n; i++)
        char_dest[i] = char_src[i];
    return dest;
}
