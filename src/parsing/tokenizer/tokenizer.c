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
#include <limits.h>
#include "tokenizer.h"

typedef struct s_list
{
	char			*prompt;
	int				token_type;
	bool			litteral;
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
    if(string[0] == '"')
        return (true);
    return (false);
}

int ft_count_dollar(char *string)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (string[i])
    {
        if (string[i] == '$')
            count++;
        i++;
    }
    return (count);
}

bool ft_valid_format(char c)
{
    if (c <= 'Z' && c >= 'A')
        return (true);
    if (c <= 'z' && c >= 'a')
        return (true);
    if (c <= '9' && c >= '0')
        return (true);
    if (c == '_')
        return (true);
    return (false);
}
char *ft_insert_for_litteral(char *string)
{
    int     i;
    int     j;
    char    *new_string = NULL;
    i = 1;
    j = 0;
    new_string = malloc(strlen(string) + ft_count_dollar(string) + 1);
    while (string[i] && string[i] != '"')
    {
        
        if (ft_valid_format(string[i]) == false && string[i]!= '"')
        {
            new_string[j] = '|';
            j++;
        }
        if (string[i] != '"')
            new_string[j] = string[i];
        i++;
        j++;
    }
    return (new_string);
}

char *ft_replace_litteral(char *string)
{
    char **split_str;
    char *new_string = NULL;
    int i;
    int j;

    i = 0;
    j = 0;
    string = ft_insert_for_litteral(string);
    split_str = ft_split(string, '|');
    while (split_str[i])
    {
        if (split_str[i][0] == '$' && ft_valid_format(split_str[i][1]))
        {
            split_str[i] = getenv(++split_str[i]);
        }
        i++;
        j = 0;
    }
    i = 0;
    while (split_str[i])
    {
        new_string = ft_strjoin(new_string, split_str[i]);
        i++;
    }
    return(new_string);
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
        token->closed = 0;
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

void ft_print_token_list(t_list *token_list)
{
   while (token_list)
    {
        if (ft_is_litteral(token_list->token) == true)
            token_list-> token = ft_replace_litteral(token_list->token);
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

void ft_save_space_before(char *input)
{
    int i;

    i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '"')
        {
            i++;
            while (input[i] != '"')
            {
                if (input[i] == ' ')
                    input[i] = -42;
                i++;
            }
        }
        if (input[i] == '\'')
        {
            i++;
            while (input[i] != '\'')
            {
                if (input[i] == ' ')
                    input[i] = -42;
                i++;
            }
        }
        i++;
    }
}

void ft_save_space_after(char **splited)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (splited[i])
    {
        while (splited[i][j] != '\0')
        {
            if (splited[i][j] == -42)
                splited[i][j] = ' ';
            j++;
        }
        j = 0;
        i++;
    }
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
        // input = "echo \"Hello        $USER\" 'Oui'";
        if (strncmp(input, "kill", 4) == 0)
            return (0);
        new_input = strdup(input);
        ft_save_space_before(new_input);
        new_input = ft_insert_space(new_input);
        splited = ft_split(new_input, ' ');
        ft_save_space_after(splited);
        paths = ft_path_split(envp);
        size = ft_get_size_list(splited);
        ft_tokenize(&token_list, splited, paths);
        ft_check_integrity(token_list, size);
        ft_print_token_list(token_list);
        ft_free_list(token_list);
    }
    return (0);
}