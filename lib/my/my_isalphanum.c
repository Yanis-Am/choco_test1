/*
** EPITECH PROJECT, 2023
** my_isalphanum.c
** File description:
** apha fx
*/

#include "my.h"

int my_isalnum(int c)
{
    return (c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
}
