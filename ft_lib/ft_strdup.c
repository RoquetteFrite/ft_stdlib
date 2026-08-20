#include "ft_lib.h"

char	*ft_strdup(const char *str)
{
	int	i;
	char	*ret_str;

	i = 0;
	ret_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!str)
		return (NULL);
	while (str[i])
	{
		ret_str[i] = str[i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
