#include "ft_lib.h"

void	*ft_realloc(void *ptr, int new_size, int current_size, int sizeof_type)
{
	void	*new;

	new = malloc(sizeof_type * new_size);
	if (!new)
		return (NULL);
	new = ft_memmove(new, ptr, sizeof_type * current_size);
	free(ptr);
	return (new);
}
