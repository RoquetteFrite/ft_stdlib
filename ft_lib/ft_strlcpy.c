#include "libft.h"

static size_t  ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t strlcpy(char *dst, const char *src, size_t size)
{
    size_t     i;

    if (size == 0)
        return ft_strlen(src);
    i = 0;
    while (i < (size - 1) && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return ft_strlen(src);
}
