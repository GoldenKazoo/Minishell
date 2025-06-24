#include <stdio.h>
#include <stdbool.h>

/* function to check if there's -n option */

static bool	ft_check_nonewline_option(char **str)
{
	if (str[1] != NULL && str[1][0] == '-' && str[1][1] == 'n' && str[1][2] == '\0')
		return (true);
	return (false);
}


/* echo without  -n option */
int	ft_echo(char **str)
{
	int	i;
	bool	nonewline_flag;

	nonewline_flag = ft_check_nonewline_option(str);
	i = 1;
	if (nonewline_flag == true)
		str++;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			if (str[i] != NULL)
				printf("%s", str[i]);
//			if (str[i + 1] != NULL) //test with readline
//				printf(" ");
			i++;
		}
	}
	if (nonewline_flag != true)
		printf("%c", '\n');
	return (0);
}
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	ft_echo(argv);
	return (0);
}
