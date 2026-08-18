#include "ft_linked_list/ft_list.h"

#include <stdio.h>

void	print_elem_int(t_list *elem)
{
	printf("%d", *(int*)elem->data);
}

void	print_list_int(t_list *list)
{
	t_list	*cursor;

	cursor = list;
	while (cursor != NULL)
	{
		print_elem_int(cursor);
		printf(", ");
	}
}

void	test_list()
{
	t_list	*list;
	int		data;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (-1);
	data = 10;
	list->data = &data;
	list->next = NULL;
	print_list_int(list);
}

int	main(void)
{
	test_list();
	printf("test");
	return 0;
}
