#ifndef FT_LIST_H
# define FT_LIST_H

#include "ft_t_list.h"

#include <stdlib.h>
#include <stdio.h>

t_list  *ft_push_back(t_list *list, void *data, int size);
t_list  *ft_push(t_list *l, void *data, int size);
void ft_foreach(t_list *list, void (*function)(void*));
void	ft_free_list(t_list *t);

#endif
