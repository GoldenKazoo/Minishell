/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:42:14 by vsougoum          #+#    #+#             */
/*   Updated: 2024/07/08 09:09:34 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] != c && str[i] != '\0')
			i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*ft_word_fill(char const *s, unsigned int start, unsigned int end)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * ((end - start) + 1));
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	*ft_free_str(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static void	ft_init_var(size_t *i, int *j, int *start_word)
{
	*i = 0;
	*j = -1;
	*start_word = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		start_word;

	if (!s)
		return (NULL);
	ft_init_var(&i, &j, &start_word);
	res = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			res[++j] = ft_word_fill(s, start_word, i);
			if (!(res[j]))
				return (ft_free_str(res, j));
			start_word = -1;
		}
		i++;
	}
	return (res);
}
