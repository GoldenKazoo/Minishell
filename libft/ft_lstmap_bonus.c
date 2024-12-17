/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:47:33 by vsougoum          #+#    #+#             */
/*   Updated: 2024/06/11 09:02:56 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_elem;
	t_list	*tmp;
	void	*elem_content;

	tmp = lst;
	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (tmp != NULL)
	{
		elem_content = f(tmp->content);
		new_elem = ft_lstnew(elem_content);
		if (!new_elem)
		{
			del(elem_content);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new_elem);
		tmp = tmp->next;
	}
	return (res);
}
