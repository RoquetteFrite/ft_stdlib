#include "libft.h"

int len(char const *s)
{
    int     i;

    i = 0;
    while (s[i])
        i++;
    return(i);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int     i;
    char    *str;

    i = 0;
    str = malloc(sizeof(char) * len(s) + 1);
    if (!str)
        return (NULL);
    while (s[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}

// #include <stdio.h>
// char test_function(unsigned int i, char c)
// {
//     int     add;

//     if (i % 2 == 0)
//         add = 0;
//     else
//         add = 1;
//     return (c + add);
// }

// int main(void)
// {
//     char *s = ft_strmapi("je suis une phrase", test_function);
//     printf("%s\n", s);
//     free(s);
//     return (0);
// }