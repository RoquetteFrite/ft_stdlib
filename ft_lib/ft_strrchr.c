static int  ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strrchr(const char *s, int c)
{
    int    size;

    size = ft_strlen(s);
    while (size >= 0)
    {
        if (s[size] == (char)c)
            return ((char *)(s + size));
        size--;
    }
    return (0);
}
