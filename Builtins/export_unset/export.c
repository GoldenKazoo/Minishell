#include "env.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isalnum(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

int	ft_check_var_name(char *s)
{
	int	i;

	i = 1;
	while (s[i] != '=')
	{
		if (ft_isalnum(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

t_env	*ft_copy_env(char **env)
{
	t_env	*new_env;
	int		i;

	i = 0;
	new_env = NULL;
	while (env[i] != NULL)
	{
		ft_lstadd_back(&new_env, ft_lstnew(ft_strdup(env[i])));
		i++;
	}
	return (new_env);
}

int	ft_print_env(t_env *lst_env)
{
	t_env	*tmp;

	tmp = lst_env;
	if (!tmp)
	{
		ft_putstr_fd("environment empty ):\n", 2);
		return (1);
	}
	while (tmp != NULL)
	{
		printf("%s\n", tmp->row);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_char_idx(char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_edit_var_env(t_env **env, char *new_row)
{
	t_env	*tmp;

	if (env == NULL)
		return (1);
	tmp = *env;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->row, new_row, ft_char_idx(tmp->row, '=')) == 0)
		{
			free(tmp->row);
			tmp->row = ft_strdup(new_row);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_export(t_env **env, char *new_row)
{
	if (new_row == NULL)
		return (1);
	if (!ft_isalpha(*new_row))
	{
		ft_putstr_fd("export: invalid identifier\n", 2);
		return (1);
	}
	if (ft_strchr(new_row, '=') == NULL)
		return (0);
	if (ft_check_var_name(new_row) == 1)
	{
		ft_putstr_fd("export: invalid identifier\n", 2);
		return (1);
	}
	if (ft_edit_var_env(env, new_row) == 1)
		ft_lstadd_back(env, ft_lstnew(ft_strdup(new_row)));
	return (0);
}
