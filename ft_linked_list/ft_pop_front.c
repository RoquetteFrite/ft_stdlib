#include "ft_list.h"

t_list	*ft_pop_front(t_list *l)
{
	t_list	*remove;

	if (!l)
		return (NULL);
	remove = l;
	if (l->next)
	{
		l = l->next;
		free(remove);
		return (l);
	}
	else
	{
		free (l);
		return (NULL);
	}
}
