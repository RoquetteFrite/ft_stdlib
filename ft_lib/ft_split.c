#include "libft.h"
#include <stdio.h>

int number_of_sep(char const *s, char c)
{
    int     i;
    int     n;

    n = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c))
            n++;
        i++;
    }
    return (n);
}

int number_of_carac(char const *s, char c, int start)
{
    int     n;

    n = 0;
    while(s[start])
    {
        if (s[start] == c)
            return (n);
        n++;
        start++;
    }
    return (n);
}

char **ft_split(char const *s, char c)
{
    char    **split;
    int     i;
    int     y;
    int     str_i;
    int     size_y;

    if (!s)
        return (NULL);
    size_y = number_of_sep(s, c);
    split = malloc(sizeof(char *) * (size_y + 1));
    if (!split)
        return (NULL);
    i = 0;
    y = 0;
    while (y < size_y)
    {
        while (s[i] == c)
            i++;
        str_i = 0;
        split[y] = malloc(sizeof(char) * (number_of_carac(s, c, i) + 1));
        if (!split[y])
            return (NULL);
        while (s[i] && s[i] != c)
            split[y][str_i++] = s[i++];
        split[y][str_i] = '\0';
        y++;
    }
    split[y] = NULL;
    return (split);
}
