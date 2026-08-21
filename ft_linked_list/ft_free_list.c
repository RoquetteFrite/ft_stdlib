#include "ft_list.h"

void	ft_free_list(t_list *t)
{
	t_list	*tmp;

	while (t)
	{
		tmp = t;
		t = t->next;
		free(tmp);
	}
}
