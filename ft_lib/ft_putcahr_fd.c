#include "libft.h"

void ft_putcahr_fd(char c, int fd)
{
    write(fd, &c, 1);
}

// #include <fcntl.h>
// int main(void)
// {
//     int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

//     if (fd == -1)
//         return (1);
//     ft_putcahr_fd('a', fd);
//     close(fd);
//     return (0);
// }