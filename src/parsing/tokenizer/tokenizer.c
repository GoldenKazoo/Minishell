/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zak <zak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:52:20 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/08 22:25:06 by zak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "tokenizer.h"

typedef struct s_list
{
	char			*prompt;
	int				token_type;
	int				litteral;
	int				closed;
	char			*token;
	struct s_list	*previous_token;
	struct s_list	*next_token;
}	t_list;

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
	int size;
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

void ft_tokenize(t_list **token_list, char **splited, char **paths)
{
    int     i;
    t_list  *token;
    t_list  *last_token;

    i = 0;
    while (splited[i])
    {
        token = malloc(sizeof(t_list));
        if (!token)
            return ;
        token->prompt = NULL;
        token->token_type = ft_check_identity(splited[i], paths);
        token->litteral = 0;
        token->closed = 0;
        token->token = splited[i]; //ici gerer quote concat
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

void ft_print_token_list(t_list *token_list)
{
   while (token_list)
    {
        printf("%s : %i\n", token_list->token, token_list->token_type);
        token_list = token_list->next_token;
    }
}

int     ft_count_redir(t_list *token_list)
{
    int redir;

    redir = 0;
    while(token_list)
    {
        if (token_list->token_type == STDIN ||token_list->token_type == STDOUT || token_list->token_type == HEREDOC || token_list->token_type == STDOUT)
        {
            redir++;
        }
        token_list = token_list->next_token; 
    }
    return (redir);
}

void    ft_error_tokenizer(t_list *token_list, int size)
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
void    ft_check_integrity(t_list *token_list, int list_size)
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

void ft_free_list(t_list *token_list)
{
    free(token_list);
}
int main(int argc, char **argv, char **envp)
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
        if (strncmp(input, "kill", 4) == 0)
            return (0);
        new_input = ft_insert_space(input);
        splited = ft_split(new_input, ' ');
        paths = ft_path_split(envp);
        size = ft_get_size_list(splited);
        ft_tokenize(&token_list, splited, paths);
        ft_check_integrity(token_list, size);
        ft_print_token_list(token_list);
        ft_free_list(token_list);
    }
    return (0);
}


//Todo : Fix l'identification (par ex > donne 1)