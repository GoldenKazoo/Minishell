/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:19:20 by vsougoum          #+#    #+#             */
/*   Updated: 2025/05/30 23:19:22 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_free_env(t_env *lst)
{
	t_env	*tmp;
	t_env	*to_free;

	tmp = lst;
	while (tmp != NULL)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free->row);
		free(to_free);
	}
}
