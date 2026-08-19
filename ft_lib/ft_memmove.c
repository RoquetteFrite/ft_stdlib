#include "ft_lib.h"

void *ft_memmove(void *dest, const void *src, unsigned int size)
{
	unsigned int		i;
	unsigned const char	*s;
	unsigned char		*d;

	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	i = -1;
	if (s == d)
		return (d);
	if (d < s)
		while (++i < size)
			d[i] = s[i];
	else
	{
		i = size;
		while (i > 0)
		{
			i--;
			d[i] = s[i];

		}
	}
	return (dest);
}
