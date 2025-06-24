#include "env.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < (n - 1))
		i++;
	if (n > 0)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

t_env *ft_lstnew(char	*str)
{
	t_env	*new;

	new = malloc(sizeof(t_env) * 1);
	if (new == NULL)
		return (NULL);
	new->row = str;
	new->next = NULL;
	return (new);
}
t_env	*ft_lstlast(t_env *lst)
{
	t_env	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*last;
	
	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}

char	*ft_strdup(char *str)
{
	char	*dup_str;
	int		i;

	i = 0;
	dup_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dup_str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
