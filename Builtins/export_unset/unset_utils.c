/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:16:15 by vsougoum          #+#    #+#             */
/*   Updated: 2025/06/02 10:24:32 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

t_env	*ft_find_row(t_env *lst, char *row_to_find)
{
	t_env	*tmp;
	t_env	*row_find;

	tmp = lst;
	row_find = NULL;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->row, row_to_find) == 0)
			row_find = tmp;
		tmp = tmp->next;
	}
	return (row_find);
}

t_env	*ft_find_prev_row(t_env *lst, char *row_to_find)
{
	t_env	*tmp;
	t_env	*prev_find;
	t_env	*find_node;

	tmp = lst;
	prev_find = NULL;
	find_node = ft_find_row(lst, row_to_find);
	while (tmp != NULL)
	{
		if (tmp->next == find_node)
			prev_find = tmp;
		tmp = tmp->next;
	}
	return (prev_find);
}

t_env	*ft_find_next_row(t_env *lst, char *row_to_find)
{
	t_env	*find_node;

	find_node = ft_find_row(lst, row_to_find);
	return (find_node->next);
}

int	ft_lst_remove_node(t_env **lst, char *row_to_remove)
{
	t_env *prev_remove;
	t_env *next_remove;
	t_env *to_find;

	to_find = ft_find_row(*lst, row_to_remove);
	if (to_find == NULL)
		return (1);
	prev_remove = ft_find_prev_row(*lst, row_to_remove);
	next_remove = to_find->next;
	if (to_find == *lst)
		*lst = (*lst)->next;
	else
		prev_remove->next = next_remove;
	free(to_find->row);
	free(to_find);
	return (0);
}

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

//int main(void)
//{
//	printf("%d\n", ft_strcmp("Coucou","Aonjour"));
//	printf("%d\n", strcmp("Coucou","Aonjour"));
//	return (0);
//}
