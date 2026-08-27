#include "ft_lib.h"

int ft_perror(const char *message, int fd, int return_value)
{
	write(fd, message, ft_strlen(message));
	return (return_value);
}

