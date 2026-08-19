#ifndef FT_LIST_H
# define FT_LIST_H

#include "ft_t_list.h"

#include <stdlib.h>
#include <stdio.h>

t_list  *ft_push_back(t_list *list, void *data);
t_list  *ft_push(t_list *l, void *data);
void ft_foreach(t_list *list, void (*function)(void*));

#endif
