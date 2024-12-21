/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:40 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 19:16:43 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

char	*ft_get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (!(strncmp("PATH=", envp[i], 5)))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**ft_path_split(char **envp)
{
	return (ft_split(ft_get_path(envp), ':'));
}
