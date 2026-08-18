#include "ft_t_list.h"

t_list *ft_push(void *data, t_list l)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	while (l)
	{
		list = ft_push_back(l->data, list);
		l = l->next;
	}
	return (list);
}

int main(void);
{
	t_list *l;

	ft_push("aze", l);
	return 0;
}
