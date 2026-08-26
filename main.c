#include "ft_linked_list/ft_list.h"
#include "ft_printf/ft_printf.h"
#include "ft_lib/ft_lib.h"
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
	t_list *list = NULL;
	t_personne *p = malloc(sizeof(t_personne));
	t_personne *pp = malloc(sizeof(t_personne));
	p->age = 25;
	p->name = ft_strdup("enzo");
	pp->age = 30;
	pp->name = ft_strdup("lucas");
	list = ft_push(list, p);
	list = ft_push(list, pp);
	// list = ft_pop_front(list);
	if (list == NULL)
		ft_printf("LIST NULL\n");
	ft_foreach(list, display);
	ft_printf("%d\n", ft_list_find(list, p));
	ft_free_list(list);
	// ft_printf("test");
	return 0;
}
