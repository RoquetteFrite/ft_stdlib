#include "ft_lib.h"

#include <stddef.h>

ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    unsigned char	*ft_dst;
    const char		*ft_src;
    unsigned int	i;

    ft_dst = (unsigned char*)dst;
    ft_src = (const unsigned char*)src;
    i = 0;
    while (ft_src[i] != NULL && i < n)
    {
        ft_dst[i] = ft_src[i];
        i++;
    }
    return (ft_dst);
}