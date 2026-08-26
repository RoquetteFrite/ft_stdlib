#include "ft_list.h"

t_list	*ft_remove_element(t_list *l, void *data)
{
	t_list	*current;
	t_list	*remove;
	
	if (!l)
		return (NULL);
	if (l->data == data)
	{
		remove = l;
		l = l ->next;
		free(remove);
		return (l);
	}
	current = l;
	while (current->next && current->next->data != data)
		current = current->next;
	if (current->next)
	{
		remove = current->next;
		if (current->next->next)
			current->next = current->next->next;
		else
			current->next = NULL;
		free(remove);
	}
	return (l);
}
