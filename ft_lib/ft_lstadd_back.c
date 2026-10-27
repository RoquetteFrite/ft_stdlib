#include "libft.h"

static void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *tmp;

    if (!lst || !new)
        return ;
    tmp = *lst;
    if (tmp == NULL)
    {
        ft_lstadd_front(lst, new);
        return ;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}
