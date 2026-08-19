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

void ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

va_list print_int(va_list args)
{
	int	val;

	val = va_arg(args, int);
	ft_putnbr(val);
	return args;
}

va_list print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char*);
	ft_putstr(str);
	return args;
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
				args = print_int(args);
			else if (format[i + 1] && format[i + 1] == 's')
				args = print_str(args);
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

int pos_in_hex(int character)
{
    const char hex_table[17] = "0123456789abcdef";
    int i;

    i = 0;
    if (character >= 16)
        return (-1);
    else
    {
        while (hex_table[i])
        {
            if (character == hex_table[i])
                return (i);
            i++;
        }
    }
    return (-1);
}

// void print_int_to_hex(size_t nbr)
// {
//     const char hex_table[17] = "0123456789abcdef";
// }

#include <stdlib.h>
// int main(void)
// {
// 	ft_printf("test: %d %s fin\n", 42, "ft_test");
// 	//ft_printf("test %%str%% %s", "tessssst");
// 	//ft_printf("%s%s", "first", " second");

//     int *ptr = NULL;
//     size_t ptr_value;

    ptr = malloc(sizeof(int));
    ptr_value = (long int)ptr;
    printf("ptr pointer: %p\n", ptr);
    printf("%ld\n", ptr_value);
    return 0;
}
