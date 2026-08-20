#include "ft_list.h"

void *ft_memmove(void *dest, const void *src, unsigned int size)
{
	unsigned int		i;
	unsigned const char	*s;
	unsigned char		*d;

	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	i = -1;
	if (s == d)
		return (d);
	if (d < s)
		while (++i < size)
			d[i] = s[i];
	else
	{
		i = size;
		while (i > 0)
		{
			i--;
			d[i] = s[i];

		}
	}
	return (dest);
}

t_list *ft_push(t_list *l, void *data, int size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = malloc(size);
	if (!list->data)
	{
		free(list);
		return (NULL);
	}
	list->data = ft_memmove(list->data, data, size);
	list->next = l;
	return (list);
}
