#include "libft.h"

static size_t  len(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int	i;
	char	*ret_str;

	i = 0;
	ret_str = malloc(sizeof(char) * len(str) + 1);
	if (!ret_str)
		return (NULL);
	while (str[i])
	{
		ret_str[i] = str[i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
