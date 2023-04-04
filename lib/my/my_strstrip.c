/*
** EPITECH PROJECT, 2023
** my_strstrip.c
** File description:
** strstrip
*/

#include <stdio.h>
#include <ctype.h>
#include "my.h"

void trim_string(char *str)
{
    int i = my_strlen(str) - 1;
    while (i > 0){
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            i--;
        else
            break;
    }
    str[i + 1] = '\0';
}
