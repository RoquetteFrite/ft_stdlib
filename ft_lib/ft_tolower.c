int ft_tolower(int c)
{
    if ((char)c >= 'A' && (char)c <= 'Z')
        c -= 32;
    return c;
}
