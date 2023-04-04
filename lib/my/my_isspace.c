/*
** EPITECH PROJECT, 2023
** my_isspace.c
** File description:
** isspace fx
*/

int my_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\r' || c == '\f' || c == '\v');
}
