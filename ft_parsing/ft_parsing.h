#include <unistd.h>

typedef struct s_optargs
{
	int		argc;
	char	**argv;
	char	*optstring;
	char	*optarg;
	int		optind;
	int		opterr;
	int		optopt;
	int		optreset;
}	t_optargs;