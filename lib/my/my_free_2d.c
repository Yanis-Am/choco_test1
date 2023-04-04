/*
** EPITECH PROJECT, 2023
** my_free_2d.c
** File description:
** free for 2d arrays
*/

#include <stdio.h>
#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++){
        free(tab[i]);
    }
    free(tab);
}
