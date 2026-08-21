#include "ft_lib.h"

int ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("%d\n", ft_atoi(argv[1]));
// }