#include "ft_t_list.h"

#include <stdio.h>

void	print_elem_int(t_list *elem)
{
	printf("%d", *(int*)elem->data);
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
	
}

int	main(void)
{
	test_list();
	printf("test");
	return 0;
}
