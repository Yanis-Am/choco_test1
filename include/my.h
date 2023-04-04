/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** header file
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

void my_putchar(char c);

int my_is_prime(int nb);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_isneg(int n);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *tab, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(const char *s1, const char *s2);

char *my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str);

int my_isalnum(int c);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(const char *s1, const char *s2, size_t n);

char *my_strncpy(char *dest, const char *src, size_t n);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

char *my_strchr(const char *s, int c);

char **my_str_to_word_array(char *str, char separator);

char my_isupper(char c);

int my_tolower(int c);

char my_islower(char c);

int my_verification (char c);

char *my_strdup (char *str);

int sum_strings_length(int n, ...);

void my_fprintf(const char *str, int fd);

int count_lines(char **str);
int parse_line(char *str);
int my_show_word_array(char * const *tab);
int is_num(char c);
char *clean_str(char *av, int i);
void *my_memcpy(void *dest, void *src, int n);
void *my_realloc(void *ptr, size_t size);
void trim_string(char *str);
void free_tab(char **tab);
int my_isspace(int c);


#endif
