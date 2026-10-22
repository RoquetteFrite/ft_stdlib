#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void ft_long_putnbr(long nb)
{
	char	c;

	if (nb< 0)
	{
		write(1, "-", 1);
		nb*= -1;
	}
	if (nb> 9)
	{
		ft_long_putnbr(nb/ 10);
	}
	c = (nb% 10) + '0';
	write(1, &c, 1);
}

void ft_unsigned_putnbr(unsigned int nb)
{
	char	c;
	unsigned long int i;

	i = nb;
	if (i > 9)
	{
		ft_unsigned_putnbr(i / 10);
	}
	c = (i % 10) + '0';
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int how_many_numbers(int val)
{
	int i;

	i = 0;
	while (val > 0) {
		val /= 10;
		i++;
	}
	return i;
}

int how_many_long_numbers(long val)
{
	int i;

	i = 0;
	while (val > 0) {
		val /= 10;
		i++;
	}
	return i;
}

int print_int(va_list *args)
{
	int	val;

	val = va_arg(*args, int);
	ft_putnbr(val);
	return how_many_numbers(val);
}

int print_unsigned(va_list *args)
{
	int val;

	val = va_arg(*args, unsigned int);
	ft_unsigned_putnbr(val);
	return how_many_numbers(val);
}

int print_str(va_list *args)
{
	char	*str;
	int	i;

	str = va_arg(*args, char*);
	ft_putstr(str);

	i = 0;
	while (str[i])
		i++;
	return i;
}

int print_float(va_list *args)
{
	float	val;
	int right;
	int left;
	float dec;
	int mul = 1;
	int limit = 6;
	int i = 0;

	val = va_arg(*args, double);
	left = (int) val;
	dec = val - left;
	float tmp = dec;
	while ((tmp - (int)tmp) > 0.00001f && i < limit)
	{
		mul *= 10;
		tmp *= 10;
		i++;
	}
	right = (int)((mul * dec)) + 1.0f;
	ft_putnbr(left);
	write(1, ".", 1);
	ft_putnbr(right);
	return how_many_numbers(left) + how_many_numbers(right) + 1;
}

int print_adress(va_list *args)
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
	buffer[i--] = 'x';
	buffer[i] = '0';
	write(STDOUT_FILENO, &buffer[i], 19 - i);
	return 19 - i - 1;
}

int print_char(va_list *args)
{
	char a;

	a = va_arg(*args, int);
	write(1, &a, 1);
	return 1;
}

int print_hexa_minuscule(va_list *args)
{
	const char hex[] = "0123456789abcdef";
	char buffer[8];
	unsigned int address;
	int i;
	int count;

	i = 8;
	count = 0;
	address = va_arg(*args, unsigned int);
	if (address == 0)
		buffer[--i] = '0'; // mettre (nil)
	else
		while (address > 0)
		{
			buffer[--i] = hex[address % 16];	
			address /= 16;
			count++;
		}
	write(STDOUT_FILENO, &buffer[i], 8 - i);
	return (count);
}

int print_hexa_uppercase(va_list *args)
{
	const char hex[] = "0123456789ABCDEF";
	char buffer[8];
	unsigned int address;
	int i;
	int count;

	count = 0;
	i = 8;
	address = va_arg(*args, unsigned int);
	if (address == 0)
		buffer[--i] = '0'; // mettre (nil)
	else
		while (address > 0)
		{
			buffer[--i] = hex[address % 16];	
			address /= 16;
			count++;
		}
	write(STDOUT_FILENO, &buffer[i], 8 - i);
	return count;
}

int print_octal(va_list *args)
{
	const char hex[] = "01234567";
	char buffer[8];
	unsigned int address;
	int i;
	int count;

	i = 8;
	address = va_arg(*args, unsigned int);
	count = 0;
	if (address == 0)
		buffer[--i] = '0';
	else
		while (address > 0)
		{
			buffer[--i] = hex[address % 8];	
			address /= 8;
			count++;
		}
	write(STDOUT_FILENO, &buffer[i], 8 - i);
	return count;
}

int print_long(va_list *args)
{
	long val;

	val = va_arg(*args, long);
	ft_long_putnbr(val);
	return how_many_long_numbers(val);
}

void write_space(va_list *args)
{
	int val;
	int i;

	i = 0;
	val = va_arg(*args, int);
	while (i++ < val)
		write (1, " ", 1);
}

int write_percentage(void)
{
	write(1, "%", 1);
	return 1;
}

int ft_printf(const char *format, ...)
{
	va_list		args;
	int		i;
	int byte = 0;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && format[i + 1] == 'd')
				byte += print_int(&args);
			else if (format[i + 1] && format[i + 1] == 'u')
				byte += print_unsigned(&args);
			else if (format[i + 1] && format[i + 1] == 's')
				byte += (print_str(&args));
			else if (format[i + 1] && format[i + 1] == 'c')
				byte += print_char(&args);
			else if (format[i + 1] && format[i + 1] == 'p')
				byte += print_adress(&args);
			else if (format[i + 1] && format[i + 1] == 'f')
				byte += print_float(&args);
			else if (format[i + 1] && format[i + 1] == 'x')
				byte += print_hexa_minuscule(&args);
			else if (format[i + 1] && format[i + 1] == 'X')
				byte += print_hexa_uppercase(&args);
			else if (format[i + 1] && format[i + 1] == 'o')
				byte += print_octal(&args);
			else if (format[i + 1] && format[i + 2] && format[i + 1] == 'l' && format[i++ + 2] == 'd')
				byte += print_long(&args);
			else if  (format[i + 1] && format[i + 1] == '%')
				byte += write_percentage();
		 	else
			 	return (-1);
			i+=2;
		} else {
			write (1, &format[i], 1);
			i++;
			byte++;
		}
	}
	return byte;
}

// #include <stdlib.h>
// int	main(void)
// {
// 	int a = 25;
// 	int b = 344;
// 	char c[] = "Enzo";

// 	int x = printf("%f %f %f\n", 42.42f, 56.7f, 99.58877f);
// 	int y = ft_printf("%f %f %f\n", 42.42f, 56.7f, 99.58877f);

// 	printf("\n(return)\nprintf: %d\nft_printf:%d\n", x, y);
// 	return (0);
// }
