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

static void	report(const char *name, int got, int expected)
{
	if (got == expected)
		fprintf(stderr, GREEN "%-60s [OK]"RESET"\n", name);
	else
		fprintf(stderr, RED"%-60s [KO]\ngot [%d] but expected [%d]"RESET"\n",
			name, got, expected);
}

Test(return_value, test_sentence, .init = redirect_all_std)
{
    int ret_printf = printf("its juste a tesssstttt !!!!\n");
    int ret_ft_printf = ft_printf("its juste a tesssstttt !!!!\n");
    report("test_sentence", ret_ft_printf, ret_printf);
}

Test(return_value, test_int, .init = redirect_all_std)
{
    int ret_printf = printf("%d", 455);
    int ret_ft_printf = ft_printf("%d", 455);
    report("test_int", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_int, .init = redirect_all_std)
{
    int ret_printf = printf("%d %d %d %d", 455, 66, 88, 999);
    int ret_ft_printf = ft_printf("%d %d %d %d", 455, 66, 88, 999);
    report("test_many_int", ret_ft_printf, ret_printf);
}

Test(return_value, test_string, .init = redirect_all_std)
{
    int ret_printf = printf("%s", "Hellllllllllllo");
    int ret_ft_printf = ft_printf("%s", "Hellllllllllllo");
    report("test_string", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_string, .init = redirect_all_std)
{
    int ret_printf = printf("%s %s %s", "Hellllllllllllo", "Iam", "dev");
    int ret_ft_printf = ft_printf("%s %s %s", "Hellllllllllllo", "Iam", "dev");
    report("test_many_string", ret_ft_printf, ret_printf);
}

Test(return_value, test_unsigned, .init = redirect_all_std)
{
    int ret_printf = printf("%u", (unsigned int)(122));
    int ret_ft_printf = ft_printf("%u", (unsigned int)(122));
    report("test_unsigned", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_unsigned, .init = redirect_all_std)
{
    int ret_printf = printf("%u %u %u", (unsigned int)(122), (unsigned int)(12672), (unsigned int)(12267));
    int ret_ft_printf = ft_printf("%u %u %u", (unsigned int)(122), (unsigned int)(12672), (unsigned int)(12267));
    report("test_many_unsigned", ret_ft_printf, ret_printf);
}