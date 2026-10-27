#include "libft.h"

size_t len(char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void ft_putendl_fd(char *s, int fd)
{
    write(fd, s, len(s));
    write(fd, "\n", 1);
}

// #include <fcntl.h>
// int main(void)
// {
//     int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
//     if (fd == -1)
//         return (1);
//     ft_putendl_fd("hellloooooo!!", fd);
//     close(fd);
//     return (0);
// }
