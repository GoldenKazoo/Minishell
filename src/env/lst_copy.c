/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:17:34 by vsougoum          #+#    #+#             */
/*   Updated: 2025/05/30 23:17:47 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
