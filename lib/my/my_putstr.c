/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** string introduction
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
