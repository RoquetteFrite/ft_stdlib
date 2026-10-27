#include "libft.h"

int isset(char const *set, char c)
{
    int     i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int     i;
    int     y;
    char    *str;

    i = 0;
    y = 0;
    while (s1[i])
    {
        if (!isset(set, s1[i]))
            y++;
        i++;
    }
    str = malloc(sizeof(char) * (y + 1));
    i = 0;
    y = 0;
    while (s1[i])
    {
        if (!isset(set, s1[i]))
            str[y++] = s1[i];
        i++;
    }
    str[y] = '\0';
    return (str);
}

// #include <stdio.h>
// int main(void)
// {
//     char *a = "qraje suiqras enzo";
//     char *b = "qra";
//     char *ret = ft_strtrim(a, b);
//     if (ret)
//     {
//         printf("%s\n", ret);
//         free(ret);
//     }
//     else
//         printf("NULL\n");
// }