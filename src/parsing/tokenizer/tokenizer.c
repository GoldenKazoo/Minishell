/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zak <zak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:52:20 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/15 22:07:43 by zak              ###   ########.fr       */
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

bool ft_is_litteral(char *string)
{
    if(string[0] == '\'')
        return (true);
    return (false);
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
        token->token = splited[i]; //ici gerer quote concat si present in string
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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ft_append_quote(t_list **token_list)
{
    t_list *current = *token_list;
    t_list *next;
    char *merged_token;
    int in_quotes;
    char quote_char;

    while (current)
    {
        char *token = current->token;

        if (strchr(token, '\'') || strchr(token, '"'))
        {
            if (token[0] == '\'' || token[0] == '"')
                quote_char = token[0];
            else
                quote_char = 0;

            in_quotes = quote_char ? 1 : 0;
            merged_token = strdup(token);

            next = current->next_token;
            while (in_quotes && next)
            {
                merged_token = realloc(merged_token, strlen(merged_token) + strlen(next->token) + 2);
                strcat(merged_token, " ");
                strcat(merged_token, next->token);
                if (strchr(next->token, quote_char))
                    in_quotes = 0;

                next = next->next_token;
            }
            if (in_quotes)
            {
                printf("Syntax error: unclosed quote.\n");
                free(merged_token);
                return;
            }
            current->token = merged_token;
            current->next_token = next;
            t_list *tmp = current->next_token;
            while (tmp && tmp != next)
            {
                t_list *to_free = tmp;
                tmp = tmp->next_token;
                free(to_free);
            }
        }
        current = current->next_token;
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
        ft_append_quote(&token_list);
        ft_print_token_list(token_list);
        ft_free_list(token_list);
    }
    return (0);
}