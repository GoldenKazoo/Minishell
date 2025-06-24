/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:05 by zchagar           #+#    #+#             */
/*   Updated: 2025/06/25 01:14:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_intlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}

bool	ft_is_litteral(char *s)
{
	size_t	len;

	len = strlen(s);
	return (len >= 2 && s[0] == '"' && s[len - 1] == '"');
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
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')
		|| c == '_'
		|| c == '?')
		return (true);
	return (false);
}


char	*ft_insert_for_litteral(char *s)
{
	size_t	i;
	size_t	j;
	char	*out;

	i = 0;
	j = 0;
	out = malloc(strlen(s) + ft_count_dollar(s) + 1);
	if (!out)
		return (NULL);
	while (s[i])
	{
		if (s[i] != '"')
		{
			if (!ft_valid_format(s[i]))
				out[j++] = '|';
			out[j++] = s[i];
		}
		i++;
	}
	out[j] = '\0';
	return (out);
}

char	*ft_replace_litteral(char *string)
{
	char	**split_str;
	char	*new_string;
	int		i;

	new_string = NULL;
	i = 0;

	string = ft_insert_for_litteral(string);
	split_str = ft_split(string, '|');
	while (split_str[i])
	{
		if (split_str[i][0] == '$')
		{
			if (split_str[i][1] == '?')
			{
				free(split_str[i]);
				split_str[i] = ft_itoa(g_last_exit_status);
			}
			else if (ft_valid_format(split_str[i][1]))
			{
				char *env_value = getenv(split_str[i] + 1);
				free(split_str[i]);
				split_str[i] = env_value ? ft_strdup(env_value) : ft_strdup("");
			}
		}
		i++;
	}
	i = 0;
	while (split_str[i])
	{
		char *tmp = new_string;
		new_string = ft_strjoin(new_string, split_str[i]);
		free(tmp);
		i++;
	}
	if (!new_string)
		new_string = ft_strdup("");
	// ft_free_split(split_str);
	return (new_string);
}


void	ft_save_space_before(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] && input[i] != '"')
			{
				if (input[i] == ' ')
					input[i] = -42;
				i++;
			}
			if (input[i] == '"')
				i++;
		}
		else if (input[i] == '\'')
		{
			i++;
			while (input[i] && input[i] != '\'')
			{
				if (input[i] == ' ')
					input[i] = -42;
				i++;
			}
		}
		else
			i++;
	}
}

void	ft_save_space_after(char **splited)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (splited[i][j] == -42)
				splited[i][j] = ' ';
			j++;
		}
		i++;
	}
}