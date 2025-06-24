/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:03:32 by zak               #+#    #+#             */
/*   Updated: 2025/06/25 01:06:25 by marvin           ###   ########.fr       */
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

char	*ft_convert_into_double_quote(char *str)
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

int	quotes_are_closed(const char *s)
{
	int		i;
	char	q;

	i = 0;
	q = 0;
	while (s[i])
	{
		if (s[i] == '\\' && q != '\'' && s[i + 1])
		{
			i += 2;
		}
		else
		{
			if (q == 0 && (s[i] == '\'' || s[i] == '"'))
				q = s[i];
			else if (q != 0 && s[i] == q)
				q = 0;
			i++;
		}
	}
	return (q == 0);
}
