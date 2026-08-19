#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int i = 0;
	int compteur = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && formqt[i + 1] == 'd')
				print_int(args);
		 if (format[i + 1] && formqt[i + 1] == 's')
			 print_str(args);
			compteur++;
		i++;
	}
	i = 0;
    	while (i < compteur)
	{
		int val = va_arg(args, int);
		printf("%d\n", val);
		i++;
	}
	return compteur;
}

int main(void)
{
	ft_printf("% % %", 3, 42, 24);
	return 0;
}
