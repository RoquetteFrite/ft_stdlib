#include "ft_lib.h"

char	*ft_strstr(char *str, char *find)
{
	char	*save_str;
	char	*current_str;
	char	*current_find;

	save_str = str;
	if (!find)
		return (str);
	while (*save_str)
	{
		current_str = save_str;
		current_find = find;
		while (*current_str && *current_find && *current_str == *current_find)
		{
			current_str++;
			current_find++;
		}
		if (*current_find == 0)
			return (save_str);
		save_str++;
	}
	return (NULL);
}
