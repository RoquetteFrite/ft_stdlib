#include "libft.h"

static int len(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int     size_s1;
    int     size_s2;
    char    *str;
    int     i;
    int     y;

    size_s1 = len(s1);
    size_s2 = len(s2);
    str = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
    if (!str)
        return (0);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    y = 0;
    while (s2[y])
        str[i++] = s2[y++];
    str[i] = '\0';
    return (str);
}

// #include <stdio.h>
// int main(void)
// {
//     char *a = "";
//     char *b = "";
//     char *ret = ft_strjoin(a, b);
//     if (ret)
//     {
//         printf("%s\n", ret);
//         free(ret);
//     }
//     else
//         printf("NULL\n");
// }