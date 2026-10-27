#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ft_dst;
	const unsigned char	*ft_src;

	if (dst == src)
		return (dst);
	ft_dst = (unsigned char *)dst;
	ft_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ft_dst[i] = ft_src[i];
		i++;
	}
	return (dst);
}