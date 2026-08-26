#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char **create_path(char **av)
{
	int i;
	int numbs = 0;

	i = 0;
	while (av[++i])
		numbs++;
	char **args = malloc(sizeof(char*) * numbs);

	i = 0;
	int j = 1;
	while (i < numbs)
	{
		args[i] = strdup(av[j]);
		i++;
		j++;
	}
	args[i] = NULL;
	return (args);
}

int create_process(char **av)
{
	pid_t fd = fork();

	if (fd == -1)
	{
		perror("Error when creating fork\n");
		return (1);
	}
	else if (fd == 0)
	{
		char **args = create_path(av);
		execvp(args[0], args);
		perror("Error execution\n");
		return (1);
	}
	else
		wait (NULL);
	
	return (0);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		perror ("./coreTest [programme] [arguments]");
		return (1);
	}
	create_process(av);
	return (0);
}
