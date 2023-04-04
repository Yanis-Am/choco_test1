/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** string to words through array
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int my_strlen(char const *str);

static int nb_sep(char const *str, char sep)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == sep)
            count++;
        i++;
    }
    return count + 1;
}

static int line_size(char const *str, char separator, int i)
{
    int size = 1;

    while (str[i] != separator && str[i] != '\0'){
        size++;
        i++;
    }
    return size;
}

char **my_str_to_word_array(char *str, char separator)
{
    int j = 0;
    int size = my_strlen(str);
    int nb_line = nb_sep(str, separator);
    char **array = malloc(sizeof(*array) * (nb_line + 1));
    int nb_char = 0;

    for (int i = 0, x = 0; str[i] != '\0'; i++, j++) {
        nb_char = line_size(str, separator, i);
        array[j] = malloc(sizeof(array) * (nb_char + 1));
        for (int y = 0; y <= nb_char; y++)
            array[j][y] = '\0';
        for (x = 0; str[i] != separator && str[i] != '\0'; i++, x++)
            array[j][x] = str[i];
    }
    array[nb_line] = NULL;
    return array;
}
