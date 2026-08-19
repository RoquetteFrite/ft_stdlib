#include "ft_list.h"

void ft_foreach(t_list *list, void (*function)(void*))
{
	t_list *current;

	current = list;
	while (current)
	{
		function(current->data);
		current = current->next;
	}
}
