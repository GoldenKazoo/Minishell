/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:16:23 by vsougoum          #+#    #+#             */
/*   Updated: 2025/05/30 23:20:28 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
