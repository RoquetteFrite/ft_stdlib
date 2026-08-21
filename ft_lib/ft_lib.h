
#pragma once

#include <stdlib.h>
#include <unistd.h>

void *ft_memmove(void *dest, const void *src, unsigned int size);
int ft_strlen(const char *str);
void ft_swap(void *a, void *b);
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(const char *str);
void *ft_realloc(void *ptr, int new_size, int current_size, int sizeof_type);
void *ft_calloc(int sizeof_type, int size);
void *ft_memset(void *s, int c, int n);
char *ft_strstr(char *str, char *find);
