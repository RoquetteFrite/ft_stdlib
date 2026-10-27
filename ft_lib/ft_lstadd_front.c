#include "libft.h"

// static t_list *ft_lstnew(void *content)
// {
//     t_list      *new;

//     new = malloc(sizeof(t_list));
//     if (!new)
//         return (NULL);
//     new->content = content;
//     new->next = NULL;
//     return (new);
// }

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     t_list  *head;
//     t_list  *tmp;

//     head = NULL;
//     ft_lstadd_front(&head, ft_lstnew("C"));
//     ft_lstadd_front(&head, ft_lstnew("B"));
//     ft_lstadd_front(&head, ft_lstnew("A"));
//     tmp = head;
//     while (tmp)
//     {
//         printf("%s -> ", (char *)tmp->content);
//         tmp = tmp->next;
//     }
//     printf("NULL\n");
//     while (head)
//     {
//         tmp = head->next;
//         free(head);
//         head = tmp;
//     }
//     return (0);
// }