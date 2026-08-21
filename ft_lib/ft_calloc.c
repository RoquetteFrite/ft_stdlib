#include "ft_lib.h"

void	*ft_calloc(int sizeof_type, int size)
{
	void	*ptr;
	int	total_size;

	total_size = sizeof_type * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, 0, total_size);
	return (ptr);
}
