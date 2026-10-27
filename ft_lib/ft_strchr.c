char *ft_strchr(const char *s, int c)
{
    while (*s && *s != (char)c)
        s++;
    if (!(*s))
        return (0);
    else
        return ((char *)s);
}
