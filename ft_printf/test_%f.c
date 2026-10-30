#include <stdio.h>
#include <unistd.h>
#include <float.h>

void rev_str(char *b, int len)
{
    int start;
    int stop;
    char tmp;

    start = 0;
    stop = len - 1;
    while (start < stop)
    {
        tmp = b[start];
        b[start++] = b[stop];
        b[stop--] = tmp;
    }
}

int dec_to_str(long a, char *b)
{
    int i;

    i = 5;
    while (i >= 0)
    {
        b[i--] = (a % 10) + '0';
        a /= 10;
    }
    return (6);
}

int int_to_str(unsigned __int128 a, char *b)
{
    int i;

    i = 0;
    if (a == 0)
        b[i++] = '0';
    while (a > 0)
    {
        b[i++] = ((a % 10) + '0');
        a /= 10;
    }
    rev_str(b, i);
    return (i);
}

#define POS_INF         "inf"
#define NEG_INF         "-inf"
#define NAN_MSG         "-nan"

#define POS_INF_U         "INF"
#define NEG_INF_U         "-INF"
#define NAN_MSG_U         "-NAN"

char *print_error_float(double f)
{
    double pos_inf = 1.0 / 0.0;
    double neg_inf = -1.0 / 0.0;
    
    if (f == pos_inf)
        return POS_INF_U;
    if (f == neg_inf)
        return NEG_INF_U;
    if (f != f)
        return NAN_MSG_U;
    return ("\0");
}

char *float_to_str(double f, char *b)
{
    unsigned __int128 int_part;
    long dec_part;
    int i;

    if (print_error_float(f)[0] != '\0')
        return (print_error_float(f));
    i = 0;
    if (f < 0)
    {
        b[i++] = '-';
        f = -f;
    }
    int_part = (unsigned __int128)f;
    dec_part = (long)((f - int_part) * 1000000 + 0.5);
    if (dec_part >= 1000000)
    {
        int_part++;
        dec_part = 0;
    }
    i += int_to_str(int_part, b + i);
    b[i++] = '.';
    i += dec_to_str(dec_part, b + i);
    b[i] = '\0';
    return (b);
}

int main(void)
{
    double a = 0.0 / 0.0;
    char buf[50];
    printf("%s\n", float_to_str(a, buf));
    printf("%F %d\n", a, 2);
    // double_to_str((double)17.2904);
}

// -4.14