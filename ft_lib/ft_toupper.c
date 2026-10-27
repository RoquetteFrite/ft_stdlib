int ft_toupper(int c)
{
    if ((char)c >= 'a' && (char)c <= 'z')
        c += 32;
    return c;
}
