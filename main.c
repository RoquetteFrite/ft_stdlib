#include "ft_linked_list/ft_list.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>

typedef struct s_personne
{
	int age;
	char *name;
} t_personne;

void	print_elem_int(t_list *elem)
{
	ft_printf("%d", *(int*)elem->data);
}

void	print_list_int(t_list *list)
{
	t_list	*cursor;

	cursor = list;
	while (cursor != NULL)
	{
		print_elem_int(cursor);
		ft_printf(", ");
		cursor = cursor->next;
	}
}

void	test_list()
{
	t_list	*list;
	int		data;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return ;
	data = 10;
	list->data = &data;
	list->next = NULL;
	print_list_int(list);
}

void display(void *data)
{
	t_personne *p = data;
	ft_printf("%d - %s\n", p->age, p->name);
}

int	main(void)
{
	t_list *list;
	t_personne p = {42, "ft"};
	ft_push(list, &p);
	ft_foreach(list, display);
	// ft_printf("test");
	return 0;
}
