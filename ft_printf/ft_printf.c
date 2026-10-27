#include "ft_printf.h"
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putnbr(int nb, int size)
{
	long	i;
	char	c;

	// printf("ft_putnbr\n");
	i = nb;
	if (i < 0)
	{
		size += write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
	{
		size = ft_putnbr(i / 10, size);
	}
	c = (i % 10) + '0';
	size += write(1, &c, 1);
	return(size);
}

int ft_putnbr_long(long nb, int size)
{
	char	c;

	// printf("ft_putnbr_long\n");
	if (nb< 0)
	{
		size += write(1, "-", 1);
		nb*= -1;
	}
	if (nb> 9)
	{
		size = ft_putnbr_long(nb / 10, size);
	}
	c = (nb% 10) + '0';
	size += write(1, &c, 1);
	return (size);
}

int ft_putstr(const char *str)
{
	int	i;
	int size;
	
	// printf("ft_putstr\n");
	i = -1;
	size = 0;
	while (str[++i])
		size += write(1, &str[i], 1);
	return (size);
}

int ft_putchar(int c)
{
	char	a;
	// printf("ft_putchar\n");
	a = c;
	return (write(1, &a, 1));
}

int ft_unsigned_putnbr(unsigned int nb, int size)
{
	char	c;

	// printf("ft_unsigned_putnbr\n");
	if (nb > 9)
	{
		size = ft_unsigned_putnbr(nb / 10, size);
	}
	c = (nb % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}

int ft_unsi_long_putnbr(unsigned long nb, int size)
{
	char	c;

	// printf("ft_unsi_long_putnbr\n");
	if (nb > 9)
	{
		size = ft_unsigned_putnbr(nb / 10, size);
	}
	c = (nb % 10) + '0';
	size += write(1, &c, 1);
	return (size);
}

int ft_putnbr_octal(unsigned int nb)
{
	const char hex[] = "01234567";
	char buffer[8];
	int i;

	i = 8;
	if (nb == 0)
		buffer[--i] = '0';
	else
		while (nb > 0)
		{
			buffer[--i] = hex[nb % 8];	
			nb /= 8;
		}
	return (write(STDOUT_FILENO, &buffer[i], 8 - i));
}

int ft_long_octal(unsigned long nb)
{
	const char hex[] = "01234567";
	char buffer[8];
	int i;

	// printf("ft_long_octal\n");
	i = 8;
	if (nb == 0)
		buffer[--i] = '0';
	else
		while (nb > 0)
		{
			buffer[--i] = hex[nb % 8];	
			nb /= 8;
		}
	return (write(STDOUT_FILENO, &buffer[i], 8 - i));
}

int ft_hexa(unsigned int adress, char *base)
{
	char buffer[8];
	int i;

	i = 8;
	if (adress == 0)
		buffer[--i] = '0'; // mettre (nil)
	else
		while (adress > 0)
		{
			buffer[--i] = base[adress % 16];	
			adress /= 16;
		}
	return (write(STDOUT_FILENO, &buffer[i], 8 - i));
}

int parsing_u_int(t_path *path)
{
	if (path->flag & F_O)
		return (ft_putnbr_octal(va_arg(path->args, unsigned int)));
	if (path->flag & F_U)
		return (ft_unsigned_putnbr(va_arg(path->args, unsigned int), 0));
	if (path->flag & F_X)
		return (ft_hexa(va_arg(path->args, unsigned int), "0123456789abcdef"));
	if (path->flag & F_X_U)
		return (ft_hexa(va_arg(path->args, unsigned int), "0123456789ABCDEF"));
}

int parsing_u_long(t_path *path)
{
	if (path->flag & F_O_U)
		return (ft_long_octal(va_arg(path->args, unsigned long)));
	if (path->flag & F_U_U)
		return (ft_unsi_long_putnbr(va_arg(path->args, unsigned long), 0));
}

int print_adress(unsigned long address)
{
    const char hex[] = "0123456789abcdef";
	char buffer[19];
	int i;

	// printf("print_adress\n");
	i = 18;
	buffer[i--] = '\0';
	if (address == 0)
		return (write(1, "(nil)", 5));
	else
		while (address > 0 && i >= 2)
		{
			buffer[i--] = hex[address % 16];	
			address /= 16;
		}
	buffer[i--] = 'x';
	buffer[i] = '0';
	return (write(STDOUT_FILENO, &buffer[i], 18 - i));
}

int general_parsing(t_path *path)
{
	if (path->flag & F_INT)
		return (ft_putnbr(va_arg(path->args, int), 0));
	if (path->flag & F_LONG)
		return (ft_putnbr_long(va_arg(path->args, long), 0));
	if (path->flag & F_STR)
		return (ft_putstr(va_arg(path->args, char*)));
	if (path->flag & F_CHAR)
		return (ft_putchar(va_arg(path->args, int)));
	if (path->flag & F_U_INT)
		return parsing_u_int(path);
	if (path->flag & F_U_LONG)
		return (parsing_u_long(path));
	if (path->flag & F_PER)
		ft_putchar((int)'%');
	if (path->flag & F_PER)
		ft_putchar((int)'%');
	if (path->flag & F_P)
		return (print_adress(va_arg(path->args, unsigned long)));
}

int analyse_specifiers(t_path *path)
{
	if (path->flag & F_O || path->flag & F_O_U)
		return (write (1, "0", 1));
	if (path->flag & F_X)
		return (write (1, "0x", 2));
	if (path->flag & F_X_U)
		return (write (1, "0X", 2));
}

int is_format_spe(char c)
{
    const char *flags = "sSpDdioOuUxXcC%";
    int i;

    i = 0;
    while (flags[i])
    {
        if (flags[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
	t_path	path;
	int		n;
	int		size;
	const char *flags = "sSpDdioOuUxXcC%#0-+HhlLjz";

	path.i = 0;
	path.val = 0;
	path.format = (char *)format;
	size = 0;
	va_start(path.args, format);
	while (path.format[path.i])
	{
		if (path.format[path.i] == '%')
		{
			path.i++;
			path.flag = 0;
			while (path.format[path.i])
			{
				n = 0;
				while (flags[n] && flags[n] != path.format[path.i])
					n++;
				if (flags[n])
				{
					path.flag |= (1 << n);
					if (is_format_spe(path.format[path.i]))
						break;
				}
				path.i++;
			}
			if (path.flag & F_BASE)
				size += analyse_specifiers(&path);
			size += general_parsing(&path);
		}
		else
			size += write(1, &path.format[path.i], 1);
		path.i++;
	}
	return (size);
}

int	main(void)
{
	unsigned int mon_nombre = 149;

	int ret_a = 0, ret_b = 0;
    
    // printf("%-10da\n", mon_nombre);   // Affiche 0xff
    ret_a = printf("%#d %#x %#X %#lo %#o\n", mon_nombre, mon_nombre, mon_nombre, mon_nombre, mon_nombre);
    ret_b = ft_printf("%#d %#x %#X %#O %#o\n", mon_nombre, mon_nombre, mon_nombre, mon_nombre, mon_nombre);

	printf("return value %d %d\n", ret_a, ret_b);
	
	return (0);
}
