#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void ft_putnbr(int nb)
{
	long	i;
	char	c;

	i = nb;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
	}
	c = (i % 10) + '0';
	write(1, &c, 1);
}

void ft_unsigned_putnbr(unsigned int nb)
{
	unsigned long	i;
	char	c;

	i = nb;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
	}
	c = (i % 10) + '0';
	write(1, &c, 1);
}

void ft_floating_putnbr(float nb)
{
	// long	i;
	// char	c;

	// i = nb;
	// if (nb< 0)
	// {
	// 	write(1, "-", 1);
	// 	nb*= -1;
	// }
	// if (nb == 46)
	// {
	// 	write(1, ".", 1);
	// 	ft_floating_putnbr(nb / 10.0);
	// }
	// if (nb> 9)
	// {
	// 	ft_floating_putnbr(nb / 10.0);
	// }
	// c = (nb% 10.0) + '0';
	// write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void print_int(va_list *args)
{
	int	val;

	val = va_arg(*args, int);
	ft_putnbr(val);
}

void print_str(va_list *args)
{
	char	*str;

	str = va_arg(*args, char*);
	ft_putstr(str);
}

void print_float(va_list *args)
{
	float	val;

	val = va_arg(*args, double);
	ft_floating_putnbr(val);
}

void print_adress(va_list *args)
{
    const char hex[] = "0123456789abcdef";
	char buffer[19];
	unsigned long address;
	int i;

	i = 18;
	address = (unsigned long)va_arg(*args, void*);
	buffer[i--] = '\0';
	if (address == 0)
		buffer[i--] = '0';
	else
		while (address > 0 && i >= 2)
		{
			buffer[i--] = hex[address % 16];	
			address /= 16;
		}
	buffer[i--] = 'X';
	buffer[i] = '0';
	write(STDOUT_FILENO, &buffer[i], 19 - i);
}

void print_char(va_list *args)
{
	char a;

	a = va_arg(*args, int);
	write(1, &a, 1);
}

void print_hexa_minuscule(va_list *args)
{
	const char hex[] = "0123456789abcdef";
	char buffer[19];
	unsigned long address;
	int i;

	i = 18;
	address = (unsigned long)va_arg(*args, void*);
	buffer[i--] = '\0';
	if (address == 0)
		buffer[i--] = '0';
	else
		while (address > 0 && i >= 2)
		{
			buffer[i--] = hex[address % 16];	
			address /= 16;
		}
	write(STDOUT_FILENO, &buffer[i], 19 - i);
}

void print_hexa_uppercase(va_list *args)
{
	const char hex[] = "0123456789ABCDEF";
	char buffer[19];
	unsigned long address;
	int i;

	i = 18;
	address = (unsigned long)va_arg(*args, void*);
	buffer[i--] = '\0';
	if (address == 0)
		buffer[i--] = '0';
	else
		while (address > 0 && i >= 2)
		{
			buffer[i--] = hex[address % 16];	
			address /= 16;
		}
	write(STDOUT_FILENO, &buffer[i], 19 - i);
}

void print_octal(va_list *args)
{
	const char hex[] = "01234567";
	char buffer[19];
	unsigned long address;
	int i;

	i = 18;
	address = (unsigned long)va_arg(*args, void*);
	buffer[i--] = '\0';
	if (address == 0)
		buffer[i--] = '0';
	else
		while (address > 0 && i >= 2)
		{
			buffer[i--] = hex[address % 8];	
			address /= 8;
		}
	write(STDOUT_FILENO, &buffer[i], 19 - i);
}

void print_unsigned(va_list *args)
{
	unsigned int	val;

	val = va_arg(*args, unsigned int);
	ft_unsigned_putnbr(val);
}

int ft_printf(const char *format, ...)
{
	va_list		args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && format[i + 1] == 'd')
				print_int(&args);
			else if (format[i + 1] && format[i + 1] == 's')
				print_str(&args);
			else if (format[i + 1] && format[i + 1] == 'c')
				print_char(&args);
			else if (format[i + 1] && format[i + 1] == 'p')
				print_adress(&args);
			else if (format[i + 1] && format[i + 1] == 'f')
				print_float(&args);
			else if (format[i + 1] && format[i + 1] == 'x')
				print_hexa_minuscule(&args);
			else if (format[i + 1] && format[i + 1] == 'X')
				print_hexa_uppercase(&args);
			else if (format[i + 1] && format[i + 1] == 'o')
				print_octal(&args);
			// else if (format[i + 1] && format[i + 2] && format[i + 1] == 'l' && format[i + 2] == 'd')
				// print_long(&args);
			else if  (format[i + 1] && format[i + 1] == '%')
				write(1, "%", 1);
		 	else
			 	return (-1);
			i+=2;
		} else {
			write (1, &format[i], 1);
			i++;
		}
	}
	return i;
}

#include <stdlib.h>
int main(void)
{
	unsigned int a = 5214245;

	ft_printf("%u\n", a);
	printf("%u", a);

    return 0;
}
