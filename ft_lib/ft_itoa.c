#include "libft.h"
#include <stdio.h>

static int strlen_int(long n)
{
    int     r;

    r = 0;
    if (n < 0)
    {
        r++;
        n *= -1;
    }
    while (n > 0)
    {
        n /= 10;
        r++;
    }
    if (r == 0)
        r = 1;
    return (r);
}

static int get_int(long n, int place)
{
    int     i;

    i = strlen_int(n) - 1;
    while (i > place)
    {
        n /= 10;
        i--;
    }
    if (n > 9)
        n %= 10;
    return (n);
}

char *ft_itoa(int n)
{
    long    nn;
    int     size;
    char    *str;
    int     i;
    int     dec;

    i = -1;
    dec = 0;
    nn = n;
    size = strlen_int(nn);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    if (nn < 0)
    {
        str[++i] = '-';
        nn *= -1;
        dec = 1;
    }
    while (++i < size)
        str[i] = ((get_int(nn, i - dec)) + '0');
    str[i] = '\0';
    return (str);
}

// int main(void)
// {
//     char *a = ft_itoa(-123);
//     printf("%s\n", a);
//     free(a);
// }
