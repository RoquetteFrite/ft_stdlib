#include "libft.h"

void	*ft_calloc(size_t sizeof_type, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	total_size;

	total_size = sizeof_type * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
