/*
** EPITECH PROJECT, 2023
** my_realloc.c
** File description:
** realloc
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

size_t my_malloc_usable_size(void *ptr)
{
    if (ptr == NULL)
        return 0;
    size_t *size_ptr = (size_t *)ptr - 1;
    return *size_ptr - sizeof(size_t);
}

void *my_realloc(void *ptr, size_t size)
{
    void *new_data = NULL;

    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (!ptr)
        return malloc(size);
    new_data = malloc(size);
    if (new_data) {
        size_t copy_size = size;
            if (size > my_malloc_usable_size(ptr))
                copy_size = my_malloc_usable_size(ptr);
        my_memcpy(new_data, ptr, copy_size);
        free(ptr);
    }
    return new_data;
}
