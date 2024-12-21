/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:52:20 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 17:52:22 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "tokenizer.h"

typedef struct s_list
{
	char	*prompt;
	int		token_type;
	int		litteral;
	int		closed;
	char	*token;
	struct s_list	*previous_token;
	struct s_list	*next_token;
} t_list;

/*char	args_append()
{
	char	**new_splited;
	int		new_size;

	new_size = 0;
	while (s[i])
	{
		if (ft_is_command(s[i]) == 1 && ft_is_pipe(s[i]) == 1 && ft_is_redirect_stdin(s[i]) == 1
			&& ft_is_redirect_stdout(s[i]) == 1 && ft_is_HEREDOC(s[i]) == 1 && ft_is_APPEND(s[i]) == 1)
		{
			if (ft_is_command(s[i]) == 1 && ft_is_pipe(s[i]) == 1 && ft_is_redirect_stdin(s[i]) == 1
			&& ft_is_redirect_stdout(s[i]) == 1 && ft_is_HEREDOC(s[i]) == 1 && ft_is_APPEND(s[i]) == 1)
			{
				
			}
		}
		new_size++;
	}
}
void	ft_give_token_type(t_list list)
{
	if (ft_is_command(splited) == 0)
		token_type = CMD;
	if (ft_is_pipe(splited) == 0)
		token_type = PIPE;
	if (ft_is_pipe(splited) == 0)
		token_type = PIPE;
	if (ft_is_redirect_stdin(splited) == 0)
		token_type = REDIRECT_IN;
	if (ft_is_redirect_stdout(splited) == 0)
		token_type = REDIRECT_OUT;
	if (ft_is_HEREDOC(splited) == 0)
		token_type = REDIRECT_OUT;
	if (ft_is_APPEND(splited) == 0)
		token_type = REDIRECT_OUT;
}
int main()
{
	int	i = 0;
	char *input = readline("Entrez quelque chose: ");
	char *new_input;
	char **splited;
	new_input = ft_insert_space(input);
	splited = ft_split(new_input, ' ');
	while (splited[i])
	{
		printf("%s\n", splited[i]);
		i++;
	}
}
*
