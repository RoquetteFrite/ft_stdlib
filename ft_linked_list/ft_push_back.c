#include "ft_list.h"
#include "ft_t_list.h"

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

t_list  *ft_push_back(t_list *list, void *data, int size)
{
	t_list	*cursor;
	t_list	*new_elem;
    
	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->next = NULL;
	new_elem->data = malloc(size);
	if (!new_elem->data)
	{
		free (new_elem);
		return (NULL);
	}
	new_elem->data = ft_memmove(new_elem->data, data, size);
	if (!list)
		return (new_elem);
	cursor = list;
	while (cursor->next != NULL)
		cursor = cursor->next;
	cursor->next = new_elem;
	return (list);
}
