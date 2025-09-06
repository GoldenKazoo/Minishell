/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:09:40 by vsougoum          #+#    #+#             */
/*   Updated: 2025/09/06 17:57:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"
#include "env.h"

int g_last_exit_status = 0;

static int	is_redirection(int type)
{
	return (type == STDIN || type == STDOUT || type == HEREDOC || type == APPEND);
}

int	check_syntax_errors(t_list *tokens)
{
	t_list	*current;

	if (!tokens)
		return (0);

	current = tokens;

	/* ------------------------------------------------------------- */
	/* Cas d'une erreur de pipe au début                             */
	/* ------------------------------------------------------------- */
	if (current->token_type == PIPE)
	{
		fprintf(stderr, "Syntax error: unexpected token `|`\n");
		return (1);
	}

	while (current)
	{
		if (current->token_type == PIPE)
		{
			if (current->next_token->token_type != CMD && current->next_token->token_type != ARG)
			{
				fprintf(stderr, "Syntax error: unexpected token `|`\n");
				return (1);
			}
		}
		if (is_redirection(current->token_type))
{
	if (!current->next_token || 
		(current->next_token->token_type != CMD && current->next_token->token_type != ARG))
	{
		fprintf(stderr, "Syntax error near unexpected token `%s`\n",
			current->next_token ? current->next_token->token : "newline");
		return (1);
	}
}

		current = current->next_token;
	}
	return (0);
}

int	main(__attribute__ ((unused)) int argc, __attribute__ ((unused)) char **argv, char **envp)
{
	t_env	*env_copy;
	char	**char_env_copy;

	env_copy = ft_copy_env(envp);
//	ft_print_env(env_copy);
//	printf("-------------------------------------------------\n");
//	printf("----------------------DEBUG---------------\n");
//	printf("-------------------------------------------------\n");
	char_env_copy = ft_char_copy_env(env_copy);
	while (1)
	{
		char		*input = NULL;
		char		*tmp = NULL;
		char		*spaced = NULL;
		char		**splited = NULL;
		char		**paths = NULL;
		t_list		*token_list = NULL;
		t_command	*cmd_list = NULL;
		bool		should_execute = true;
		setup_signals();
		input = readline("[Minishell]$ ");
		if (input[0] == '\0')
		{
    		free_and_reset(input);
    		continue;
		}

		if (!input)
		{
			printf("exit\n");
			break; /* Ctrl-D : on quitte si pas d’input */
		}
		add_history(input);

		/* Pour close le programme */
		if (strncmp(input, "kill", 4) == 0)
		{
			free_and_reset(input);
			break;
		}

		/* ------------------- */
		/* 1) Pré-traitement   */
		/* ------------------- */
		tmp = ft_strdup(input);
		ft_save_space_before(tmp);

		/* ----------------------------------------------------------------- */
		/* 2) Vérif des quotes                                               */
		/* ----------------------------------------------------------------- */
		if (!quotes_are_closed(tmp))
		{
			printf("Error : unclosed quotes\n");
			should_execute = false;
		}

		if (should_execute)
		{
			/* ------------------------------------------------------------- */
			/* 3) Ajout d'espaces + split                                     */
			/* ------------------------------------------------------------- */
			spaced = ft_insert_space(tmp);
			splited = ft_split(spaced, ' ');
			ft_save_space_after(splited);

			/* ------------------------------------------------------------- */
			/* 4) Tokenisation & post-traitement                             */
			/* ------------------------------------------------------------- */
			paths = ft_path_split(envp);
			int size = ft_get_size_list(splited);

			ft_tokenize(&token_list, splited, paths);
			ft_check_integrity(token_list, size);
			ft_checker_quotes(token_list);

			/* Vérif syntaxe post-token */
			if (check_syntax_errors(token_list))
				should_execute = false;
		}

		if (should_execute)
		{
			/* ------------------------------------------------------------- */
			/* 5) Conversion -> t_command + Execution                        */
			/* ------------------------------------------------------------- */
			cmd_list = token_list_to_command_list(token_list);
			if (cmd_list)
				execute_pipeline(cmd_list, char_env_copy, paths); // fn d'exec avec pipes/redir
		}

		/* ----------------------------------------------------------------- */
		/* 6) Nettoyage de fin                                               */
		/* ----------------------------------------------------------------- */
		ft_free_split(splited);
		ft_free_split(paths);
		free_and_reset(spaced);
		free_and_reset(tmp);
		free_and_reset(input);
		ft_free_list(token_list);
		// ft_free_command_list(cmd_list); // à faire pas urgent
	}
	ft_free_env(env_copy);
	free(char_env_copy);
	return (0);
}
