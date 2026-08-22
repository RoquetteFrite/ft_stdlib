#include "ft_lib.h"

void ft_putnbr_long(long int nbr)
{
	char	to_print;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < 10)
	{
		to_print = nbr += '0';
		write(1, &to_print, 1);
	}
	else
	{
		ft_putnbr_long(nbr / 10);
		to_print = nbr % 10 + '0';
		write(1, &to_print, 1);
	}
}

void	ft_putnbr(int nbr)
{
	ft_putnbr_long(nbr);
}


// int	main(void)
// {
// 	ft_putnbr_long(-2147483648);
// }