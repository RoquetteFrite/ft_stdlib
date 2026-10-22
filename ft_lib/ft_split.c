#include "ft_lib.h"

int is_sep(char c, char *sep)
{
	int		x;

	x = 0;
	while (sep[x])
		if (c == sep[x++])
			return (1);
	return (0);
}

int number_of_sep(const char *str, char *sep)
{
	int		i;
	int		separateur;

	i = 0;
	separateur = 0;
	while (str[i])
	{
		if (is_sep(str[i], sep))
			separateur++;
		i++;
	}
	return (separateur);
}

int until_sep(char *str, int i, char *sep)
{
	int		n;
	int		y;

	n = 0;
	while (str[i] && !is_sep(str[i], sep))
	{
		i++;
		n++;
	}
	return(n);
}

char **loop(char **split, char *str, char *sep, int y)
{
	int		i;
	int		tmpi;
	int		splity;

	i= 0;
	tmpi = 0;
	splity = 0;
	while (splity <= y)
	{
		split[splity] = malloc(sizeof(char) * (until_sep(str, i, sep) + 1));
		if (!split[splity])
			return (NULL);
		while (str[i] && !is_sep(str[i], sep))
		{
			split[splity][tmpi++] = str[i++];
		}
		split[splity][tmpi] = '\0';
		tmpi = 0;
		if (str[i + 1])
			i++;
		splity++;
	}
	split[splity] = NULL;
	return (split);
}

char **ft_split(char *str, char *sep)
{
	char	**split;
	int		y;

	y = number_of_sep(str, sep);
	split = malloc(sizeof(char*) * (y + 2));
	if (!split)
		return (NULL);
	split = loop(split, str, sep, y);
	return (split);
}
