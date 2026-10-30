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

void rev_str(char *b, int len)
{
    int start;
    int stop;
    char tmp;

    start = 0;
    stop = len - 1;
    while (start < stop)
    {
        tmp = b[start];
        b[start++] = b[stop];
        b[stop--] = tmp;
    }
}

int dec_to_str(long a, char *b)
{
    int i;

    i = 5;
    while (i >= 0)
    {
        b[i--] = (a % 10) + '0';
        a /= 10;
    }
    return (6);
}

int int_to_str(unsigned __int128 a, char *b)
{
    int i;

    i = 0;
    if (a == 0)
        b[i++] = '0';
    while (a > 0)
    {
        b[i++] = ((a % 10) + '0');
        a /= 10;
    }
    rev_str(b, i);
    return (i);
}

void ft_strcpy(char *dst, const char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

char *print_error_float(double f, int flag, char *b)
{
    double pos_inf = 1.0 / 0.0;
    double neg_inf = -1.0 / 0.0;
    
	b[0] = '\0';
    if (f == pos_inf && flag == 0)
        ft_strcpy(b, POS_INF);
	else if (f == pos_inf && flag == 1)
		ft_strcpy(b, POS_INF_U);
    if (f == neg_inf && flag == 0)
        ft_strcpy(b, NEG_INF);
	else if (f == neg_inf && flag == 1)
		ft_strcpy(b, NEG_INF_U);
    if (f != f && flag == 0)
        ft_strcpy(b, NAN_MSG);
	else if (f != f && flag == 1)
		ft_strcpy(b, NAN_MSG_U);
	return (b);
}

int float_to_str(double f, char *b, int flag)
{
    unsigned __int128 int_part;
    long dec_part;
    int i;

	b = print_error_float(f, flag, b);
    if (b[0] != '\0')
        return (ft_strlen(b));
    i = 0;
    if (f < 0)
    {
        b[i++] = '-';
        f = -f;
    }
    int_part = (unsigned __int128)f;
    dec_part = (long)((f - (double)int_part) * 1000000 + 0.5);
    if (dec_part >= 1000000)
    {
        int_part++;
        dec_part = 0;
    }
    i += int_to_str(int_part, b + i);
    b[i++] = '.';
    i += dec_to_str(dec_part, b + i);
    b[i] = '\0';
    return (i);
}

int ft_longlen(long long n, char *base)
{
	int	i;
	unsigned long long num;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		num = n * -1;
	}
	else
		num = n;
	while (num > 0)
	{
		num /= ft_strlen(base);
		i++;
	}
	return (i);
}

int	putnbr_base(unsigned long long nb, const char *base, char *buf)
{
	int		i;
	char	c;
	int		size_base;
	int		size;

	i = ft_longlen(nb, (char *)base);
	if (nb == 0)
	{
		buf[0] = base[0];
		buf[1] = '\0';
	}
	else
		buf[i--] = '\0';
	size = 0;
	size_base = ft_strlen((char*)base);
	while (nb > 0)
	{
		c = (base[nb % size_base]);
		buf[i--] = c; 
		nb /= size_base;
		size++;
	}
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

	a = c;
	return (write(1, &a, 1));
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

void display(t_path *path, int len)
{
	if ((!(path->flag & F_MINUS) && !(path->flag & F_ZERO)) && path->width > 0)
		path->size += print_flag(path, len, ' ');
	if (path->flag & F_SPACE && (!path->is_neg && !(path->flag & F_PLUS)))
		path->size += write(1, " ", 1);
	if (path->flag & F_PLUS && path->is_neg == 0)
		path->size += write(1, "+", 1);
	if (path->is_neg == 1)
		path->size += write (1, "-", 1);
	if (path->flag & F_ZERO && path->width > 0)
		path->size += print_flag(path, len, '0');
	path->size += write(1, path->buf, ft_strlen(path->buf));
	if (path->flag & F_MINUS)
		path->size += print_flag(path, len, ' ');
}

void display_unsigned(t_path *path, unsigned long tmp, char *base)
{
	if ((!(path->flag & F_MINUS) && !(path->flag & F_ZERO)) && path->width > 0)
		path->size += print_flag(path, ft_longlen(tmp, base), ' ');
	if (path->flag & F_HASH && path->flag & F_BASE && tmp != 0)
	{
		if (path->flag & F_B)
			path->size += write (1, "0b", 2);
		if (path->flag & F_O || path->flag & F_O_U)
			path->size += write (1, "0", 1);
		if (path->flag & F_X)
			path->size += write (1, "0x", 2);
		if (path->flag & F_X_U)
			path->size += write (1, "0X", 2);
	}
	if (path->flag & F_ZERO && path->width > 0)
		path->size += print_flag(path, ft_longlen(tmp, base), '0');
	path->size += write(1, path->buf, ft_strlen(path->buf));
	if (path->flag & F_MINUS)
		path->size += print_flag(path, ft_longlen(tmp, base), ' ');
}

void parsing_signed(t_path *path)
{
	long long	tmp;
	int			len;

	if (path->flag & F_LONG)
		tmp = va_arg(path->args, long);
	else
		tmp = va_arg(path->args, int);
	if (tmp < 0)
	{
		path->is_neg = 1;
		tmp = tmp * -1;
	}
	len = putnbr_base(tmp, BASE_TEN, path->buf);
	if (path->is_neg || path->flag & F_PLUS)
		len = len + 1;
	display(path, len);
}

void other_parsing(t_path *path)
{
	int len;

	if (path->flag & F_F)
		len = float_to_str(va_arg(path->args, double), path->buf, 0);
	if (path->flag & F_F_U)
		len = float_to_str(va_arg(path->args, double), path->buf, 1);

	display(path, len);
}

void unsigned_parsing(t_path *path)
{
	unsigned long	tmp;
	char			*base;

	base = BASE_OCTAL;
	tmp = 0;
	if (path->flag & F_O)
		tmp = va_arg(path->args, unsigned int);
	if (path->flag & F_O_U)
		tmp = va_arg(path->args, unsigned long);
	if (path->flag & F_U)
	{
		tmp = va_arg(path->args, unsigned int);
		base = BASE_TEN;
	}
	if (path->flag & F_U_U)
	{
		tmp = va_arg(path->args, unsigned long);
		base = BASE_TEN;
	}
	if (path->flag & F_X)
	{
		tmp = va_arg(path->args, unsigned int);
		base = BASE_SIX_LOW;
	}
	if (path->flag & F_X_U)
	{
		tmp = va_arg(path->args, unsigned int);
		base = BASE_SIX_UPP;
	}
	if (path->flag & F_B)
	{
		tmp = va_arg(path->args, unsigned int);
		base = BASE_BINARY;
	}
	putnbr_base(tmp, base, path->buf);
	display_unsigned(path, tmp, base);
}

void general_parsing(t_path *path)
{
	if (path->flag & F_INT || path->flag & F_LONG)
		parsing_signed(path);
	if (path->flag & F_STR)
		path->size += ft_putstr(va_arg(path->args, char*));
	if (path->flag & F_CHAR)
		path->size += ft_putchar(va_arg(path->args, int));
	if (path->flag & F_U_INT || path->flag & F_U_LONG)
		unsigned_parsing(path);
	if (path->flag & F_PER)
		path->size +=  ft_putstr("%");
	if (path->flag & F_P)	
		path->size +=  print_adress(va_arg(path->args, unsigned long));
	if (path->flag & F_FLOAT)
		other_parsing(path);
	if (path->flag & F_N)
		*va_arg(path->args, int *) = path->size;
}

int is_format_spe(char c)
{
    const char *flags = "sSpDdioOuUxXcC%fFbn";
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

int print_flag(t_path *path, int len, char flag)
{
	int		size;

	size = 0;
	while (len++ < path->width)
		size += write(1, &flag, 1);
	return (size);
}

int get_bit(char c)
{
	const char *flags = "sSpDdioOuUxXcC%fFbn #0-+HhlLjz";
	int		n;

	n = 0;
	while (flags[n] && flags[n] != c)
		n++;
	if (flags[n])
		return (1 << n);
	return (-1);
}

int is_flag_char(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+');
}

void read_flag(t_path *path)
{
	while (is_flag_char(path->format[path->i]))
	{
		path->flag |= get_bit(path->format[path->i]);
		path->i++;
	}
	if (path->flag & F_ZERO && path->flag & F_MINUS)
		path->flag &= ~F_ZERO;
}

void read_width(t_path *path)
{
	while (path->format[path->i] >= '0' && path->format[path->i] <= '9')
	{
		path->width = path->width * 10 + (path->format[path->i] - '0');
		path->i++;
	}
}

void get_spec(t_path *path)
{
	int		n;

	while (path->format[path->i])
	{
		n = get_bit(path->format[path->i]);
		if (n != -1)
			path->flag |= n;
		if (is_format_spe(path->format[path->i]))
			break;
		path->i++;
	}
}

int ft_printf(const char *format, ...)
{
	t_path	path;

	path.i = 0;
	path.format = (char *)format;
	path.size = 0;
	va_start(path.args, format);
	while (path.format[path.i])
	{
		if (path.format[path.i] == '%')
		{
			path.i++;
			path.flag = 0;
			path.width = 0;
			path.is_neg = 0;
			read_flag(&path);
			read_width(&path);
			get_spec(&path);
			general_parsing(&path);
		}
		else
			path.size += write(1, &path.format[path.i], 1);
		path.i++;
	}
	va_end(path.args);
	return (path.size);
}

// #include <sys/types.h>
// #include <stdint.h>
// #include <stddef.h>
// int	main(void)
// {	
// 	int a = 9;

// 	int r1 = ft_printf("%% %s %010d %p\n", "bonjour", 42, &a);
// 	int r2 =    printf("%% %s %010d %p\n", "bonjour", 42, &a);

// 	printf("%d - %d\n", r1, r2);



// 	return (0);
// }
