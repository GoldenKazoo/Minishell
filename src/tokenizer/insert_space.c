/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:38:58 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 18:27:36 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int	ft_pipe_case(char *prompt, char *new_prompt, int *index, int state)
{
	if (!prompt || !new_prompt || !index[0] || !index[1])
		return (0);
	if (prompt[index[1] + 1] == '|')
	{
		state = 1;
		new_prompt[index[0]] = prompt[index[1]];
		index[0]++;
		new_prompt[index[0]] = ' ';
		index[0]++;
		new_prompt[index[0]] = '|';
		index[0]++;
		new_prompt[index[0]] = ' ';
		(index[1])++;
	}
	return (state);
}

int	ft_right_redir_case(char *prompt, char *new_prompt, int *index, int state)
{
	if (!prompt || !new_prompt || !index[0] || !index[1])
		return (0);
	if (prompt[index[1] + 1] == '<')
	{
		state = 1;
		new_prompt[index[0]++] = prompt[index[1]];
		new_prompt[index[0]++] = ' ';
		new_prompt[index[0]] = '<';
		(index[1])++;
		if (prompt[index[1] + 1] && prompt[index[1] + 1] == '<')
		{
			index[0]++;
			new_prompt[index[0]++] = '<';
			new_prompt[index[0]++] = ' ';
			(index[1])++;
		}
		else
		{
			index[0]++;
			new_prompt[index[0]] = ' ';
		}
	}
	return (state);
}

int	ft_left_redir_case(char *prompt, char *new_prompt, int *index, int state)
{
	if (!prompt || !new_prompt || !index[0] || !index[1])
		return (0);
	if (prompt[index[1] + 1] == '>')
	{
		state = 1;
		new_prompt[index[0]++] = prompt[index[1]];
		new_prompt[index[0]++] = ' ';
		new_prompt[index[0]++] = '>';
		(index[1])++;
		if (prompt[index[1] + 1] && prompt[index[1] + 1] == '>')
		{
			index[0]++;
			new_prompt[index[0]++] = '>';
			new_prompt[index[0]] = ' ';
			(index[1])++;
		}
		else
		{
			index[0]++;
			new_prompt[index[0]] = ' ';
		}
	}
	return (state);
}

char	*ft_insert_space(char *prompt)
{
	int		index[2];
	int		state;
	char	*new_prompt;

	index[0] = 0;
	index[1] = 0;
	new_prompt = malloc(strlen(prompt) + ft_count_space(prompt) + 10);
	while (prompt[index[1]] != '\0')
	{
		state = 0;
		state = ft_pipe_case(prompt, new_prompt, index, state);
		state = ft_right_redir_case(prompt, new_prompt, index, state);
		state = ft_left_redir_case(prompt, new_prompt, index, state);
		if (state == 0)
		{
			new_prompt[index[0]] = prompt[index[1]];
		}
		index[0]++;
		index[1]++;
	}
	new_prompt[index[0]] = '\0';
	return (new_prompt);
}

// int main()
// {
//     char *test = "echo ls-la|cat grep l<outfile";
//     printf("%zu\n", ft_count_space(test));
//     char *new_test = ft_insert_space(test);

//     printf("%s", new_test);
// 	free(new_test);
// }