#include <stdio.h>

/* function to check if there's -n option

int	ft_check_newline_option(char **str)
{}

*/

/* echo without  -n option */
int	ft_echo(char *str)
{
	if (str != NULL)
	{
		printf("%s", str);
	}
	printf("%c", '\n');
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		printf("Error\n");
		return (1);
	}
	ft_echo(argv[1]);
	return (0);
}
*/
