#include <stdlib.h>

typedef struct s_list
{
    void            *data;
    struct s_list   next;
}