void        ft_bzero(void *s, int n)
{
    char    *p;

    p = (char *)s;
    while (n--)
        *p++ = 0;
}
