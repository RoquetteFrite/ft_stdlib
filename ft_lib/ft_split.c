#include "ft_lib.h"

int	is_separator(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' /*il en manque*/)
		return (1);
	else
		return (0);
}

int	count_words(char *str)
{
	int	i;
	int	break_flag;
	int count_words;

	i = 0;
	break_flag = 1;
	count_words = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			break_flag = 1;
		if (break_flag && str[i] != ' ')
		{
			break_flag = 0;
			count_words++;
		}
		i++;
	}
	return (count_words);
}

void ft_strcpy_delim(char *dest, char *src, char delim)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != delim)
	{
		dest[i] = src[i];
		i++;
	}
}

int str_len_delim(char *str, char delim)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delim)
		i++;
	return (i);
}

void ft_free_split_string(char **split_string)
{
	int	i;

	i = 0;
	while (split_string[i] != NULL)
	{
		free(split_string[i]);
		i++;
	}
}

char **ft_split(char *str)
{
	int	i;
	int	break_flag;
	int word_count;
	char **split_string;

	i = 0;
	break_flag = 1;
	word_count = 0;
	split_string = malloc((count_words(str) + 1) * sizeof(char*));
	if (split_string == NULL)
		return (NULL);
	split_string[count_words(str)] = NULL;
	while (str[i])
	{
		if (str[i] == ' ')
			break_flag = 1;
		if (break_flag && str[i] != ' ')
		{
			break_flag = 0;
			split_string[word_count] = malloc(str_len_delim(&str[i], ' ') * sizeof(char));
			if (split_string[word_count] == NULL)
			{
				ft_free_split_string(split_string);
				return (NULL);
			}
			ft_strcpy_delim(split_string[word_count], &str[i], ' ');
			word_count++;
		}
		i++;
	}
	return (split_string);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	int i;
// 	char **split_string;

// 	i = 0;
// 	(void)argc;
// 	split_string = ft_split(argv[1]);
// 	printf("%d\n", count_words(argv[1]));
// 	while (split_string[i] != NULL)
// 	{
// 		printf("%s, ", split_string[i]);
// 		i++;
// 	}
// }