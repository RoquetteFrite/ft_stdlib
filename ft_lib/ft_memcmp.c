#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t     i;
    const unsigned char *str_1;
    const unsigned char *str_2;

    i = 0;
    str_1 = (const unsigned char *)s1;
    str_2 = (const unsigned char *)s2;
    while (i < n)
    {
        if (str_1[i] != str_2[i])
            return (str_1[i] - str_2[i]);
        i++;
    }
    return (0);
}
