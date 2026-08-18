#ifndef FT_T_LIST_H
# define FT_T_LIST_H

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

#endif