#include "libft.h"

static t_list *ft_lstnew(void *content)
{
    t_list      *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

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

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *tmp;
    t_list  *next;

    if (!lst || !del)
        return ;
    tmp = *lst;
    while (tmp)
    {
        next = tmp->next;
        del(tmp->content);
        free(tmp);
        tmp = next;
    }
    *lst = NULL;
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_node;
    t_list *new_lst;
    void *content;

    if (!lst || !f || !del)
        return (NULL);
    new_lst = NULL;
    while (lst)
    {
        content = f(lst->content);
        new_node = ft_lstnew(content);
        if (!new_node)
        {
            del(content);
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_node);
        lst = lst->next;
    }
    return (new_lst);
}