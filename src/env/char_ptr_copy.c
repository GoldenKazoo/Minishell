/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_ptr_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:49:16 by vsougoum          #+#    #+#             */
/*   Updated: 2025/06/02 20:17:50 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "stdio.h"

static int	ft_get_env_size(t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		env = env->next;
		i++;
	}
	return (i);
}

//static void	ft_printf_env(char **env)
//{
//	int	i;
//	
//	i = 0;
//	while (env[i])
//	{
//		printf("%s\n", env[i]);
//		i++;
//	}
//}

char	**ft_char_copy_env(t_env *env)
{
	char	**copy_env;
	int		i;

	i = 0;
	copy_env = malloc(sizeof(char *) * (ft_get_env_size(env) + 1));
	if (copy_env == NULL)
		return (NULL);
	while (env != NULL)
	{
		copy_env[i] = env->row;
		env = env->next;
		i++;
	}
	copy_env[i] = NULL;
//	ft_printf_env(copy_env);
	return (copy_env);
}
