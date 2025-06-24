#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_get_current_working_dir(void)
{
	char	*cur_dir;

	cur_dir = malloc(sizeof(char) * PATH_MAX);
	if (cur_dir == NULL)
		return (NULL);
	return (getcwd(cur_dir, PATH_MAX));
}

int	ft_print_working_dir(void)
{
	char *current_dir;

	current_dir = ft_get_current_working_dir();
	if (current_dir == NULL)
		return (1);
	printf("%s\n", current_dir);
	return (0);
}

int	main(void)
{
	if (ft_print_working_dir() == 1)
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
