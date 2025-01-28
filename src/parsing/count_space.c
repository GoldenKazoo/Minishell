/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:46:01 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/28 16:28:39 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_count_pipe_case(char *prompt, int *count, int *i)
{
	if (prompt[*i] == '|' && prompt[*i - 1] != ' '
		&& prompt[*i + 1] != ' ')
	{
		*count = *count + 2;
	}
}

void	ft_count_right_case(char *prompt, int *count, int *i)
{
	if (prompt[*i] == '<' && prompt[*i - 1] != ' '
		&& prompt[*i + 1] != ' ')
	{
		*count = *count + 2;
		if (prompt[*i + 1] == '<')
			(*i)++;
	}
}

void	ft_count_left_case(char *prompt, int *count, int *i)
{
	if (prompt[*i] == '>' && prompt[*i - 1] != ' '
		&& prompt[*i + 1] != ' ')
	{
		*count = *count + 2;
		if (prompt[*i + 1] == '>')
			(*i)++;
	}
}

size_t	ft_count_space(char *prompt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt[i] != '\0')
	{
		if (i > 0 && prompt[i + 1] != '\0')
		{
			ft_count_pipe_case(prompt, &count, &i);
			ft_count_right_case(prompt, &count, &i);
			ft_count_left_case(prompt, &count, &i);
		}
		i++;
	}
	return (count);
}

