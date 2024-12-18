#include <stdio.h>

int	ft_print_env(char **env)
{
	int	i;

	i = 0;
	if (*env == NULL)
		return (1);
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int main (__attribute__ ((unused)) int argc, __attribute__ ((unused)) char **argv, char **envp)
{
	if (ft_print_env(envp))
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
