int ft_atoi(const char *nptr)
{
	long	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = ((res * 10) + (nptr[i] - '0'));
		i++;
	}
	return ((int)(res * sign));
}
