#include "ft_list.h"
#include "ft_t_list.h"

t_list  *ft_push_back(t_list *list, void *data)
{
	t_list	*cursor;
	t_list	*new_elem;
    
	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->next = NULL;
	cursor = list;
	while (cursor != NULL)
		cursor = cursor->next;
	cursor->next = new_elem;
	return (list);
}