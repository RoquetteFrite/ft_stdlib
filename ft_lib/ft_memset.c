void *ft_memset(void *s, int c, int n)
{
	unsigned char	*str;
	int		i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
