/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:05 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/24 17:33:50 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool	ft_is_litteral(char *string)
{
	if (string[0] == '"')
		return (true);
	return (false);
}

int	ft_count_dollar(char *string)
{
	int	i;
	int	count;

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

bool	ft_valid_format(char c)
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

char	*ft_insert_for_litteral(char *string)
{
	int		i;
	int		j;
	char	*new_string;

	new_string = NULL;
	i = 1;
	j = 0;
	new_string = malloc(strlen(string) + ft_count_dollar(string) + 1);
	while (string[i] && string[i] != '"')
	{
		if (ft_valid_format(string[i]) == false && string[i] != '"')
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

char	*ft_replace_litteral(char *string)
{
	char	**split_str;
	char	*new_string;
	int		i;
	int		j;

	new_string = NULL;
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
	return (new_string);
}

void	ft_save_space_before(char *input)
{
	int	i;

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

void	ft_save_space_after(char **splited)
{
	int	i;
	int	j;

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
