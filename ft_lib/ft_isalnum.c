#include "libft.h"

int ft_isalnum(char c)
{
    return ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'));
}
