/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:17:37 by zchagar           #+#    #+#             */
/*   Updated: 2025/05/20 11:25:41 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_list	*find_last(t_list *token_list)
{
	if (!token_list)
		return (NULL);
	while (token_list->next_token != NULL)
		token_list = token_list->next_token;
	return (token_list);
}

int	ft_get_size_list(char **splited)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (splited[i])
	{
		size++;
		i++;
	}
	return (size);
}

void ft_free_list(t_list *list)
{
    while (list)
    {
		// free(list->token);
        t_list *next = list->next_token;
        free(list);
        list = next;
    }
}

void	ft_print_token_list(t_list *token_list)
{
	while (token_list)
	{
		// if (ft_is_litteral(token_list->token) == true)
		// 	token_list->token = ft_replace_litteral(token_list->token);
		printf("%s : %i\n", token_list->token, token_list->token_type);
		token_list = token_list->next_token;
	}
}
