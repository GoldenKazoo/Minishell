/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:22:26 by vsougoum          #+#    #+#             */
/*   Updated: 2025/05/30 23:26:15 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
		ft_printf("%s\n", tmp->row);
		tmp = tmp->next;
	}
	return (0);
}
