/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:05:55 by vsougoum          #+#    #+#             */
/*   Updated: 2025/06/02 10:21:55 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char*	ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL && s1 != NULL)
		return (ft_strdup(s1));
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char *ft_find_var_row(t_env *env, char *var_name)
{
	t_env	*tmp;

	if (env == NULL)
		return (NULL);
	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strncmp(var_name, tmp->row, ft_strlen(var_name)) == 0)
			return (tmp->row);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_unset(t_env **env, char *env_var)
{
	char	*env_var_full;
	char	*env_var_row;

	if (ft_strchr(env_var, '=') != NULL)
		return ;
	env_var_full = ft_strjoin(env_var, "=");
	env_var_row = ft_find_var_row(*env, env_var_full);
//	printf("VAR FULL: %s\n", env_var_full);
//	printf("env var row: %s\n", env_var_row);
	if (env_var_row == NULL)
	{
		free(env_var_full);
		return ;
	}
	ft_lst_remove_node(env, env_var_row);
	free(env_var_full);
}
