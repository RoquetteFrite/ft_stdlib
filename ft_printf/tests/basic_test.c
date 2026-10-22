#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

void	redirect_all_std(void)
{
	cr_redirect_stdout();
}

static void	report(const char *name, const char *got, const char *expected)
{
	if (strcmp(got, expected) == 0)
		fprintf(stderr, GREEN "%-60s [OK]"RESET"\n", name);
	else
		fprintf(stderr, RED"%-60s [KO]\ngot [%s] but expected [%s]"RESET"\n",
			name, got, expected);
}

Test(ft_printf, simple_text, .init = redirect_all_std)
{
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello how are you my friend ?");
	ft_printf("Hello how are you my friend ?");
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_text", out, buf);
}

Test(ft_printf, simple_pourcent, .init = redirect_all_std)
{
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello %%");
	ft_printf("Hello %%");
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_pourcent", out, buf);
}

Test(ft_printf, simple_int, .init = redirect_all_std)
{
	int	    a = 123;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello %d", a);
	ft_printf("Hello %d", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_int", out, buf);
}

Test(ft_printf, simple_unsigned_int, .init = redirect_all_std)
{
	unsigned int    a = 123;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello %u", a);
	ft_printf("Hello %u", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_unsigned_int", out, buf);
}

Test(ft_printf, simple_char, .init = redirect_all_std)
{
	char	a = 'x';
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello %c", a);
	ft_printf("Hello %c", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_char", out, buf);
}

Test(ft_printf, simple_string, .init = redirect_all_std)
{
    char	a[] = "world";
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello %s", a);
	ft_printf("Hello %s", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_string", out, buf);
}

Test(ft_printf, simple_float, .init = redirect_all_std)
{
    float	a = 11.44;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello %f", a);
	ft_printf("Hello %f", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_float", out, buf);
}

Test(ft_printf, simple_long, .init = redirect_all_std)
{
    long	a = 114567890;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "Hello %ld", a);
	ft_printf("Hello %ld", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_long", out, buf);
}

Test(ft_printf, simple_adresse, .init = redirect_all_std)
{
	int		a;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "%p", (void *)&a);
	ft_printf("%p", (void *)&a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_adresse", buf, out);
}

Test(ft_printf, simple_lowercase_hexa, .init = redirect_all_std)
{
	int		a = 456;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "%x", a);
	ft_printf("%x", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_lowercase_hexa", buf, out);
}

Test(ft_printf, simple_upercase_hexa, .init = redirect_all_std)
{
	int		a = 456;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "%X", a);
	ft_printf("%X", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_upercase_hexa", buf, out);
}

Test(ft_printf, simple_octal, .init = redirect_all_std)
{
	int		a = 456;
	char	buf[32];
	char	out[64] = {0};
	FILE	*f;

	snprintf(buf, sizeof(buf), "%o", a);
	ft_printf("%o", a);
	fflush(stdout);
	f = cr_get_redirected_stdout();
	fread(out, 1, sizeof(out) - 1, f);
    report("simple_octal", buf, out);
}