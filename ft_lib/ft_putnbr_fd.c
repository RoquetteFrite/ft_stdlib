#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char       c;

    while (n > 0)
    {
        c = ((n % 10) + '0');    
        write(fd, &c, 1);
        n /= 10;
    }
}

#include <fcntl.h>
int main(void)
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd == -1)
        return (1);
    ft_putnbr_fd(454689, fd);
    close(fd);
    return (0);
}