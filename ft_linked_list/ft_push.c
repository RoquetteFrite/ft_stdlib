#include "ft_list.h"



t_list *ft_push(t_list *l, void *data, int size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = malloc(sizeof(size));
	if (!list->data)
		return (NULL);
	list->data = ft_memmove(list->data, data, size);
	list->next = NULL;
	while (l)
	{
		list = ft_push_back(list, l->data);
		l = l->next;
	}
	return (list);
}
