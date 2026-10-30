#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ft_printf.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

static void	redirect_all_std(void)
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

Test(flag_test, int_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%d\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%d\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_base", actual, expected);
}

Test(flag_test, int_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#d\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#d\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_hash", actual, expected);
}

Test(flag_test, int_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05d\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05d\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_zero", actual, expected);
}

Test(flag_test, int_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6d\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6d\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_marge", actual, expected);
}

Test(flag_test, int_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+d\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+d\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_plus", actual, expected);
}

Test(flag_test, int_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5d\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5d\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_space", actual, expected);
}

Test(flag_test, int_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% d\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% d\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_one_space", actual, expected);
}

Test(flag_test, int_i, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%i\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%i\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_i", actual, expected);
}

Test(flag_test, int_i_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#i\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#i\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_i_hash", actual, expected);
}

Test(flag_test, int_i_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05i\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05i\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_i_zero", actual, expected);
}

Test(flag_test, int_i_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6i\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6i\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_i_marge", actual, expected);
}

Test(flag_test, int_i_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+i\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+i\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_i_plus", actual, expected);
}

Test(flag_test, int_i_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5i\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5i\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_i_space", actual, expected);
}

Test(flag_test, int_i_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% i\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% i\n", 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("int_i_one_space", actual, expected);
}

Test(flag_test, double_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%ld\n", (long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%D\n", (long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("double_base", actual, expected);
}

Test(flag_test, double_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#ld\n", (long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#D\n", (long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("double_hash", actual, expected);
}

Test(flag_test, double_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05ld\n", (long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05D\n", (long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("double_zero", actual, expected);
}

Test(flag_test, double_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6ld\n", (long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6D\n", (long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("double_marge", actual, expected);
}

Test(flag_test, double_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+ld\n", (long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+D\n", (long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("double_plus", actual, expected);
}

Test(flag_test, double_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5ld\n", (long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5D\n", (long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("double_space", actual, expected);
}

Test(flag_test, double_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% ld\n", (long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% D\n", (long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("double_one_space", actual, expected);
}

Test(flag_test, octal_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%o\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%o\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_base", actual, expected);
}

Test(flag_test, octal_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#o\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#o\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_hash", actual, expected);
}

Test(flag_test, octal_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05o\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05o\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_zero", actual, expected);
}

Test(flag_test, octal_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6o\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6o\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_marge", actual, expected);
}

Test(flag_test, octal_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+o\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+o\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_plus", actual, expected);
}

Test(flag_test, octal_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5o\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5o\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_space", actual, expected);
}

Test(flag_test, octal_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% o\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% o\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_one_space", actual, expected);
}

Test(flag_test, octal_U_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%lo\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%O\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_U_base", actual, expected);
}

Test(flag_test, octal_U_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#lo\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#O\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_U_hash", actual, expected);
}

Test(flag_test, octal_U_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05lo\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05O\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_U_zero", actual, expected);
}

Test(flag_test, octal_U_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6lo\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6O\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_U_marge", actual, expected);
}

Test(flag_test, octal_U_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+lo\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+O\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_U_plus", actual, expected);
}

Test(flag_test, octal_U_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5lo\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5O\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_U_space", actual, expected);
}

Test(flag_test, octal_U_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% lo\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% O\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("octal_U_one_space", actual, expected);
}

Test(flag_test, unsigned_int_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%u\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%u\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_int_base", actual, expected);
}

Test(flag_test, unsigned_int_base_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#u\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#u\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_int_base_hash", actual, expected);
}

Test(flag_test, unsigned_int_base_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05u\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05u\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_int_base_zero", actual, expected);
}

Test(flag_test, unsigned_int_base_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6u\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6u\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_int_base_marge", actual, expected);
}

Test(flag_test, unsigned_int_base_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+u\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+u\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_int_base_plus", actual, expected);
}

Test(flag_test, unsigned_int_base_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5u\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5u\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_int_base_space", actual, expected);
}

Test(flag_test, unsigned_int_base_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% u\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% u\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_int_base_one_space", actual, expected);
}

Test(flag_test, unsigned_long_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%lu\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%U\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_long_base", actual, expected);
}

Test(flag_test, unsigned_long_base_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#lu\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#U\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_long_base_hash", actual, expected);
}

Test(flag_test, unsigned_long_base_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05lu\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05U\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_long_base_zero", actual, expected);
}

Test(flag_test, unsigned_long_base_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6lu\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6U\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_long_base_marge", actual, expected);
}

Test(flag_test, unsigned_long_base_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+lu\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+U\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_long_base_plus", actual, expected);
}

Test(flag_test, unsigned_long_base_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5lu\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5U\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_long_base_space", actual, expected);
}

Test(flag_test, unsigned_long_base_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% lu\n", (unsigned long)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% U\n", (unsigned long)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("unsigned_long_base_one_space", actual, expected);
}

Test(flag_test, hexa_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%x\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%x\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_base", actual, expected);
}

Test(flag_test, hexa_base_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#x\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#x\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_base_hash", actual, expected);
}

Test(flag_test, hexa_base_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05x\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05x\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_base_zero", actual, expected);
}

Test(flag_test, hexa_base_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6x\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6x\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_base_marge", actual, expected);
}

Test(flag_test, hexa_base_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+x\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+x\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_base_plus", actual, expected);
}

Test(flag_test, hexa_base_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5x\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5x\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_base_space", actual, expected);
}

Test(flag_test, hexa_base_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% x\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% x\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_base_one_space", actual, expected);
}





Test(flag_test, hexa_upper_base, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%X\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%X\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_upper_base", actual, expected);
}

Test(flag_test, hexa_upper_base_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#X\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#X\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_upper_base_hash", actual, expected);
}

Test(flag_test, hexa_upper_base_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%05X\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%05X\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_upper_base_zero", actual, expected);
}

Test(flag_test, hexa_upper_base_marge, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-6X\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-6X\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_upper_base_marge", actual, expected);
}

Test(flag_test, hexa_upper_base_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+X\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+X\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_upper_base_plus", actual, expected);
}

Test(flag_test, hexa_upper_base_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%5X\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%5X\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_upper_base_space", actual, expected);
}

Test(flag_test, hexa_upper_base_one_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% X\n", (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% X\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("hexa_upper_base_one_space", actual, expected);
}

Test(flag_test, plus_and_minus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+-4da\n", 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+-4da\n", (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("plus_and_minus", actual, expected);
}

Test(flag_test, combined, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+d %-5da %10d %#d % d\n", 42, 42, 42, 42, 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+d %-5da %10d %#d % d\n", 42, 42, 42, 42, 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("combined", actual, expected);
}

Test(flag_test, multiple_zero, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%010d %03d %02d %01d\n", 42, 42, 42, 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%010d %03d %02d %01d\n", 42, 42, 42, 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("multiple_zero", actual, expected);
}

Test(flag_test, multiple_hash, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%#x %x %#X %X\n", (unsigned int)42, (unsigned int)42, (unsigned int)42, (unsigned int)42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%#x %x %#X %X\n", (unsigned int)42, (unsigned int)42, (unsigned int)42, (unsigned int)42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("multiple_hash", actual, expected);
}

Test(flag_test, multiple_minus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%-d %-6d %d %-1d %d\n", 42, 42, 42, 42, 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%-d %-6d %d %-1d %d\n", 42, 42, 42, 42, 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("multiple_minus", actual, expected);
}

Test(flag_test, multiple_plus, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("%+d %d %+d %+d\n", -42, -42, -42, 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("%+d %d %+d %+d\n", -42, -42, -42, 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("multiple_plus", actual, expected);
}

Test(flag_test, multiple_space, .init = redirect_all_std)
{
    char	expected[64] = {0};
	char	actual[64] = {0};
	FILE	*f;
	int		ret_printf;
	int		ret_ft_printf;

	f = cr_get_redirected_stdout();

	ret_printf = printf("% d %10d %d %1d %    d\n", -42, -42, -42, 42, 42);
	fflush(stdout);
	fread(expected, 1, sizeof(expected) - 1, f);

	ret_ft_printf = ft_printf("% d %10d %d %1d %    d\n", -42, -42, -42, 42, 42);
	fflush(stdout);
	fread(actual, 1, sizeof(actual) - 1, f);

	cr_assert_eq(ret_ft_printf, ret_printf);
	cr_assert_str_eq(actual, expected);
    report("multiple_space", actual, expected);
}