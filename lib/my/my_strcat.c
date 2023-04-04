/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** strcat function
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
