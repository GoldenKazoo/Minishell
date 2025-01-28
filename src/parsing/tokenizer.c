/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:52:20 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/28 14:10:19 by zchagar          ###   ########.fr       */
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
	t_list	*last_token;

	i = 0;
	while (splited[i])
	{
		token = malloc(sizeof(t_list));
		if (!token)
			return ;
		token->prompt = NULL;
		token->token_type = ft_check_identity(splited[i], paths);
		token->closed = 0;
		if (ft_contain_quotes(splited[i]) == false && token->token_type == ARG)
			splited[i] = ft_convert_into_double_quote(splited[i]);
		token->token = splited[i];
		token->litteral = ft_is_litteral(splited[i]);
		token->next_token = NULL;
		token->previous_token = NULL;
		if (!(*token_list))
		{
			*token_list = token;
		}
		else
		{
			last_token = find_last(*token_list);
			last_token->next_token = token;
			token->previous_token = last_token;
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
void	ft_check_integrity(t_list *token_list, int list_size)
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
	while (token_list)
	{
		if (ft_is_litteral(token_list->token) == true && token_list->token_type == ARG)
			token_list->token = ft_replace_litteral(token_list->token);
		token_list = token_list->next_token;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char    *input;
	int     size;
	char    *new_input;
	char    **splited;
	char    **paths;

	while (1)
	{
		t_list  *token_list = NULL;
		input = readline("[Minishell]$ ");
		// input = "echo zsh$USER";
		add_history(input);
		if (strncmp(input, "kill", 4) == 0)
			return (0);
		new_input = strdup(input);
		ft_save_space_before(new_input);
		new_input = ft_insert_space(new_input);
		if (ft_validate_all_quotes(new_input) == false)
		{}
		else
		{
		splited = ft_split(new_input, ' ');
		ft_save_space_after(splited);
		paths = ft_path_split(envp);
		size = ft_get_size_list(splited);
		ft_tokenize(&token_list, splited, paths);
		ft_check_integrity(token_list, size);
		ft_checker_quotes(token_list);
		ft_print_token_list(token_list);
		ft_free_list(token_list);
		}
	}
	return (0);
}