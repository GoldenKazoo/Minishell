/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:43:28 by zchagar           #+#    #+#             */
/*   Updated: 2025/05/20 08:43:28 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <stdlib.h>
#include <string.h>

t_command	*create_command_node(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->heredoc_delim = NULL;
	cmd->append = false;
	cmd->next = NULL;
	return (cmd);
}

int	count_args(t_list *token)
{
	int	count;

	count = 0;
	while (token && token->token_type != PIPE)
	{
		if (token->token_type == CMD || token->token_type == ARG)
			count++;
		token = token->next_token;
	}
	return (count);
}

char	**fill_argv(t_list *token, int count)
{
	char	**argv;
	int		i;

	argv = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (token && token->token_type != PIPE)
	{
		if (token->token_type == CMD || token->token_type == ARG)
		{
			argv[i++] = token->token;
		}
		else if (token->token_type == STDIN || token->token_type == STDOUT
			|| token->token_type == APPEND || token->token_type == HEREDOC)
		{
			token = token->next_token;
		}
		token = token->next_token;
	}
	argv[i] = NULL;
	return (argv);
}


t_command	*token_list_to_command_list(t_list *token_list)
{
	t_command	*head;
	t_command	*current;
	t_command	*new_cmd;
	int			argc;

	head = NULL;
	current = NULL;
	while (token_list)
	{
		new_cmd  = create_command_node();
		if (!new_cmd)
			return NULL;
		argc = count_args(token_list);
		new_cmd->argv = fill_argv(token_list, argc);
		// Redirection parsing
		while (token_list && token_list->token_type != PIPE)
		{
			if (token_list->token_type == STDIN && token_list->next_token)
				new_cmd->infile = token_list->next_token->token;
			else if (token_list->token_type == STDOUT && token_list->next_token)
				new_cmd->outfile = token_list->next_token->token;
			else if (token_list->token_type == APPEND && token_list->next_token)
			{
				new_cmd->outfile = token_list->next_token->token;
				new_cmd->append = true;
			} else if (token_list->token_type == HEREDOC && token_list->next_token)
				new_cmd->heredoc_delim = token_list->next_token->token;
			token_list = token_list->next_token;
		}

		// On passe au nmxt token
		if (token_list && token_list->token_type == PIPE)
			token_list = token_list->next_token;
		// Ajt a la liste
		if (!head)
			head = new_cmd;
		else
			current->next = new_cmd;
		current = new_cmd;
	}
	return head;
}

