#include "ft_list.h"

t_list	*ft_pop_back(t_list *l)
{
	t_list	*current;
	t_list	*remove;

	if (!l)
		return (NULL);
	if (!l->next)
	{
		free(l);
		return (NULL);
	}
	current = l;
	while (current->next->next)
		current = current->next;
	remove = current->next;
	current->next = NULL;
	free(remove);
	return (l);
}
