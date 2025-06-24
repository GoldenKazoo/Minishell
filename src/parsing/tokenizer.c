/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:52:20 by zchagar           #+#    #+#             */
/*   Updated: 2025/06/25 01:13:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <limits.h>
#include "tokenizer.h"


void	ft_tokenize(t_list **token_list, char **splited, char **paths)
{
	int		i;
	t_list	*token;
	t_list	*last;

	i = 0;
	while (splited[i])
	{
		if (splited[i][0] != '\0')
		{
			token = malloc(sizeof(t_list));
			if (!token)
				return ;
			token->token_type = ft_check_identity(splited[i], paths);
			token->closed = 0;
			if (ft_contain_quotes(splited[i]) == false
				&& token->token_type == ARG)
				splited[i] = ft_convert_into_double_quote(splited[i]);
			token->token = splited[i];
			token->litteral = ft_is_litteral(splited[i]);
			token->next_token = NULL;
			token->previous_token = NULL;
			if (!(*token_list))
				*token_list = token;
			else
			{
				last = find_last(*token_list);
				last->next_token = token;
				token->previous_token = last;
			}
		}
		i++;                                  
	}
}


int	ft_count_redir(t_list *token_list)
{
	int	redir;

	redir = 0;
	while (token_list)
	{
		if (token_list->token_type == STDIN ||token_list->token_type == STDOUT
			|| token_list->token_type == HEREDOC || token_list->token_type == STDOUT)
		{
			redir++;
		}
		token_list = token_list->next_token; 
	}
	return (redir);
}

void	ft_error_tokenizer(t_list *token_list, int size)
{
	if (size == 1 && (token_list->token_type == PIPE || token_list->token_type == STDIN || 
		token_list->token_type == STDOUT || token_list->token_type == HEREDOC || token_list->token_type == APPEND))
	{
		printf("Syntax error : parse error near '\n'");
		return ;
	}
	if (ft_count_redir(token_list) == 0 && token_list->token_type != CMD)
	{
		printf("Syntax error : command not found");
	}
	while (token_list)
	{
		if (token_list->token_type == PIPE && (token_list->next_token->token_type == ARG || token_list->next_token->token_type == PIPE))
		{
			printf("Syntax error : command not found after PIPE");
		}
	}
}
void	ft_check_integrity(t_list *token_list, __attribute__ ((unused)) int list_size)
{
	while (token_list)
	{
		if (token_list->token_type == CMD)
		{
			token_list = token_list->next_token;
			while (token_list && (token_list->token_type == CMD || token_list->token_type == ARG))
			{
				token_list->token_type = ARG;
				token_list = token_list->next_token;
			}
		}
		if (token_list)
			token_list = token_list->next_token;
		}
}

void ft_checker_quotes(t_list *token_list)
{
	char *temp;
	
	if (token_list->token_type == ARG)
{
	printf("Before replace: %s\n", token_list->token);
	temp = token_list->token;
	token_list->token = ft_replace_litteral(temp);
	printf("After replace: %s\n", token_list->token);
}

	while (token_list)
	{
		if (ft_is_litteral(token_list->token) == true && token_list->token_type == ARG)
		{
			temp = token_list->token;
			token_list->token = ft_replace_litteral(temp);
		}
		token_list = token_list->next_token;
	}
}

void ft_free_split(char **split)
{
	int i;
	i = 0;
    if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
    free(split);
}

void free_and_reset(char *ptr)
{
    if (ptr)
        free(ptr);
}

