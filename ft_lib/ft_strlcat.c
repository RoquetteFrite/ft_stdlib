#include "libft.h"

static size_t  ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t     i;
    size_t     y;
    size_t     src_len;
    size_t     dst_len;

    src_len = ft_strlen(src);
    dst_len = 0;
    while ((dst_len < size) && dst[dst_len])
        dst_len++;
    if (dst_len == size)
        return (dst_len + src_len);
    i = dst_len;
    y = 0;
    while (i < (size - 1) && src[y])
    {
        dst[i] = src[y];
        i++;
        y++;
    }
    dst[i] = '\0';
    return (dst_len + src_len);
}