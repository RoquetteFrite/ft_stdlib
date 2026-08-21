#include "ft_list.h"

int   ft_list_find(t_list *l, void *data)
{
	t_list	*current;
	
	current = l;
	while (current)
	{
		if (current->data == data)
			return (1);
		current = current->next;
	}
	return (0);
}
