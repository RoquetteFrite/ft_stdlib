#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    int     i;

    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (start < len)
    {
        str[i] = s[start];
        start++;
        i++;
    }
    return (str);
}

// #include <stdio.h>
// int main(void)
// {
//     char *s = "Coupe moi bitch";
//     char *ret = ft_substr(s, 6, 22);
//     if (ret)
//     {
//         printf("%s\n", ret);
//         free(ret);
//     }
//     else
//         printf("NULL\n");
// }