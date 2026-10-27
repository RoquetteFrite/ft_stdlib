void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int     i;

    if (!s || !f)
        return ;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}

#include <stdio.h>
void test_function(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = '0';
}

int main(void)
{
    char s[] = "je suis une phrase";
    ft_striteri(s, test_function);
    printf("%s\n", s);
    return (0);
}