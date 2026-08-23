#include "ft_parsing.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_optargs(t_optargs *args, int argc, char **argv, char *optstring)
{
	args->argc = argc;
	args->argv = argv;
	args->optarg = NULL;
	args->opterr = 1;
	args->optind = 1;
	args->optopt = 0;
	args->optreset = 0;
	args->optstring = optstring;
}

void	reset_optargs(t_optargs *args)
{
	args->optind = 0;
	args->optreset = 0;
	args->optarg = NULL;
}

void	usage()
{
	write(2, "usage: <-h> <-f filename> <-s> <-c> <-i> <-v>", 45);
	exit(0);
}

int	is_arg(t_optargs *args, char *arg)
{
	int	i;

	i = 0;
	while (args->optstring[i] != '\0')
	{
		if (arg[0] != '-')
			return (0);
		if (args->optstring[i] == arg[1])
			return (1);
	}
	return (0);
}

void	error_unknown_arg(char *prog_name, char arg)
{
	write(2, prog_name, ft_strlen(prog_name));
	write(2, ": unknown option: ", 18);
	write(2, &arg, 1);
	write(2, "\n", 1);
	usage();
}

int	ft_getopt(t_optargs *args)			// CONTINUER ICI
{
	char	arg;

	arg = -1;
	if (args->optreset == 1)
		reset_optargs(args);
	if (args->argv[args->optind] == NULL)
		return (arg);
	if (is_arg(args, args->argv[args->optind]))
	{
		arg = args->argv[args->optind][1];
	}
	else
		error_unknown_arg(args->argv[0], args->argv[args->optind][0]);
	return (arg);
}

int	main(int argc, char **argv)
{
	t_optargs	*args;
	int			flag;

	args = malloc(sizeof(t_optargs));
	if (args == NULL)
		return (-1);
	init_optargs(args, argc, argv, "hsciv");
	flag = ft_getopt(args);
	while (flag != -1)
	{
		if (flag == 'h')
			usage();
		// else if (flag == 's')
		// 	get_split_file();
		// else if (flag == 'c')
		// 	get_whole_file();
		// else if (flag == 'i')
		// 	get_int_ptr();
		// else if (flag == 'v')
		// 	get_int_ptr_ptr();
		flag = ft_getopt(args);
	}
	
}