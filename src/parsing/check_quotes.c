/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:03:32 by zak               #+#    #+#             */
/*   Updated: 2025/01/28 13:32:04 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool	ft_contain_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (true);
		i++;
	}
	return (false);
}

char *ft_convert_into_double_quote(char *str)
{
	int		i;
	int		j;
	char	*new_string;

	i = 0;
	j = 1;
	new_string = malloc(strlen(str) + 3);
	new_string[i] = '"';
	new_string[strlen(str) + 1] = '"';
	new_string[strlen(str) + 2] = '\0';
	while (str[i])
	{
		new_string[j] = str[i];
		i++;
		j++; 
	}
	return (new_string);
}

bool	ft_check_quotes(char *str, char quote)
{
	bool	open;
	int		i;

	open = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == quote)
			open = !open;
		i++;
	}
	return (!open);
}

bool	ft_validate_all_quotes(char *str)
{
	bool	valid_single;
	bool	valid_double;

	valid_single = ft_check_quotes(str, '\'');
	valid_double = ft_check_quotes(str, '"');
	return (valid_single && valid_double);
}

void	ft_print_status(bool status)
{
	if (status)
		printf("Syntax OK\n");
	else
		printf("Syntax Error: Unmatched quote\n");
}

// int main()
// {
//     char *test1 = "echo 'Hello world'";
//     char *test2 = "echo \"Hello world";
//     char *test3 = "echo 'It's a test'";
//     char *test4 = "echo \"Test 'imbriqued' quote\"";
//     char *test5 = "echo \"Test 'imbriqued\" quote\''";

//     ft_print_status(ft_validate_all_quotes(test1)); // Syntax OK
//     ft_print_status(ft_validate_all_quotes(test2)); // Syntax Error
//     ft_print_status(ft_validate_all_quotes(test3)); // Syntax Error
//     ft_print_status(ft_validate_all_quotes(test4)); // Syntax OK
//     ft_print_status(ft_validate_all_quotes(test5)); // Syntax Error
//     return (0);
// }