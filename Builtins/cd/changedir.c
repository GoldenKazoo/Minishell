#include <unistd.h>
#include <stdio.h>

/* cd builtin */ 
int	ft_change_dir(char *path)
{
	if (chdir(path) == -1)	//chdir only changes the working directory
	{						// so it's not visible here but in minishell it will
		perror("chdir");	// be visible (since it's a process itself)
		return (-1);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	char	str[1024];
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("%s\n", getcwd(str, 1024));
	ft_change_dir(argv[1]);
	printf("%s\n", getcwd(str, 1024));
	return (0);
}
*/
