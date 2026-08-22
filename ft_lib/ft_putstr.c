#include "ft_lib.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

// int main(void)
// {
// 	ft_putstr("YOLOOOOOO");
// }