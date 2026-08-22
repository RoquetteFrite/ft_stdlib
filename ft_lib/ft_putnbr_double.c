#include <unistd.h>
#include <stdio.h> 	// DEBUG DEBUG DEBUG

#include "ft_lib.h"

void ft_putnbr_dec(long double nbr)
{
	int		nbr_int;
	char	to_print;

	nbr = nbr * 10;
	nbr_int = (int)nbr;
	if (nbr != 0)
	{
		ft_putnbr_dec(nbr - (long int)nbr);
		to_print = nbr_int + '0';
		write(1, &to_print, 1);
	}
}

int ft_digit_nbr(long int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

double	ft_round(long double nbr)
{
	if (nbr >= ((long int)nbr + 0.5))
		return ((long int)nbr + 1);
	else
		return ((long int)nbr);
}

int	is_int(double nbr)
{
	long int	nbr_int;

	nbr_int = (long int)nbr;
	return (nbr_int == nbr);
}

void	ft_putnbr_double(double nbr)
{
	long double	long_double_nbr;
	long int	int_part;
	long double	dec_part;

	long_double_nbr = nbr;
	if (long_double_nbr < 0)
	{
		long_double_nbr *= -1;
		write(1, "-", 1);
	}
	int_part = (long int)nbr;
	dec_part = nbr - int_part;
	ft_putnbr(int_part);
	write(1, ".", 1);
	ft_putnbr_dec(dec_part);
}

#include <stdio.h>
int main(void)
{
	float		test_dec;

	test_dec = 0.567;
	ft_putnbr_double(test_dec);
	write(1, "\n", 1);
	ft_putnbr_dec(test_dec);
	// printf("\ntest_dec: %lf\n", test_dec);
}