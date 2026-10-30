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

Test(return_value, test_memory_adress, .init = redirect_all_std)
{
    int a;

    int ret_printf = printf("%p", &a);
    int ret_ft_printf = ft_printf("%p", &a);
    report("test_memory_adress", ret_ft_printf, ret_printf);
}

typedef struct t {
    int a;
} t;

Test(return_value, test_many_memory_adress, .init = redirect_all_std)
{
    int a;
    t tt;

    int ret_printf = printf("%p %p", &a, &tt);
    int ret_ft_printf = ft_printf("%p %p", &a, &tt);
    report("test_many_memory_adress", ret_ft_printf, ret_printf);
}

Test(return_value, test_hexa_lower, .init = redirect_all_std)
{
    int ret_printf = printf("%x", 45369);
    int ret_ft_printf = ft_printf("%x", 45369);
    report("test_hexa_lower", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_hexa_lower, .init = redirect_all_std)
{
    int ret_printf = printf("%x %x %x", 45369, 45852, 7855);
    int ret_ft_printf = ft_printf("%x %x %x", 45369, 45852, 7855);
    report("test_many_hexa_lower", ret_ft_printf, ret_printf);
}

Test(return_value, test_hexa_upper, .init = redirect_all_std)
{
    int ret_printf = printf("%X", 45369);
    int ret_ft_printf = ft_printf("%X", 45369);
    report("test_hexa_upper", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_hexa_upper, .init = redirect_all_std)
{
    int ret_printf = printf("%X %X %X", 45369, 45852, 7855);
    int ret_ft_printf = ft_printf("%X %X %X", 45369, 45852, 7855);
    report("test_many_hexa_upper", ret_ft_printf, ret_printf);
}

Test(return_value, test_octal, .init = redirect_all_std)
{
    int ret_printf = printf("%o", 45369);
    int ret_ft_printf = ft_printf("%o", 45369);
    report("test_octal", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_octal, .init = redirect_all_std)
{
    int ret_printf = printf("%o %o %o", 45369, 45852, 7855);
    int ret_ft_printf = ft_printf("%o %o %o", 45369, 45852, 7855);
    report("test_many_octal", ret_ft_printf, ret_printf);
}

Test(return_value, test_long, .init = redirect_all_std)
{
    int ret_printf = printf("%ld", 453645555559);
    int ret_ft_printf = ft_printf("%D", 453645555559);
    report("test_long", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_long, .init = redirect_all_std)
{
    int ret_printf = printf("%ld %ld %ld", 4536945585, 4536948585, 45369455855144);
    int ret_ft_printf = ft_printf("%D %D %D", 4536945585, 4536948585, 45369455855144);
    report("test_many_long", ret_ft_printf, ret_printf);
}

Test(return_value, test_percentage, .init = redirect_all_std)
{
    int ret_printf = printf("%%");
    int ret_ft_printf = ft_printf("%%");
    report("test_percentage", ret_ft_printf, ret_printf);
}

Test(return_value, test_many_percentage, .init = redirect_all_std)
{
    int ret_printf = printf("%% %% %%");
    int ret_ft_printf = ft_printf("%% %% %%");
    report("test_many_percentage", ret_ft_printf, ret_printf);
}