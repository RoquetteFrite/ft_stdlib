#include <unistd.h>

int	is_int(double nbr)
{
	long int	nbr_int;

	nbr_int = (long int)nbr;
	return (nbr_int == nbr);
}

void	ft_putnbr_double(double nbr)
{
	char to_print;

	if (is_int(nbr) && nbr < 10)
	{
		to_print = nbr + '0';
		write(1, &to_print, 1);
	}
	else if (is_int(nbr))
	{
		ft_putnbr_double((long int)nbr / 10);
		to_print = (long int)nbr % 10 + '0';
		write(1, &to_print, 1);
	}
	else if (nbr < 10 && nbr != 0)
	{
		to_print = (long int)nbr + '0';
		write(1, &to_print, 1);
		ft_putnbr_double(nbr * 10);
	}
	else if (nbr != 0)
	{
		ft_putnbr_double(nbr - (long int)nbr);
	}
}

void ft_putnbr_dec(double nbr)
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

#include <stdio.h>
int main(void)
{
	float	test_dec;

	test_dec = 0.567;
	ft_putnbr_double(100.4);
	write(1, "\n", 1);
	ft_putnbr_dec(test_dec);
	printf("\n%f\n", test_dec - (int)test_dec);
	printf("%.20f\n", 0.567);
}