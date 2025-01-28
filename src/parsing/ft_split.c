/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:39:00 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/28 18:20:38 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <string.h>

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * strlen(src) + 1);
	if (!p)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*p;

	i = 0;
	k = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	p = malloc(sizeof(char) * (strlen(s1) + strlen(s2)) + 1);
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_tmp;
	size_t			i;

	s_tmp = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		s_tmp[i] = 0;
		i++;
	}
}
size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}
void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*p;

	if (elementsize > 0 && elementcount > (UINT_MAX / elementsize))
		return (NULL);
	p = malloc(elementcount * elementsize);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, elementcount * elementsize);
	return (p);
}

static int	ft_countwords(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (10);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free_split(char **p, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static char	*ft_dupword(const char *str, int start, int end)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * (end - start + 1));
	if (!p)
		return (NULL);
	while (start < end)
	{
		p[i] = str[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

static void	ft_initvar(size_t *i, int *j, int *k)
{
	*i = -1;
	*j = -1;
	*k = -1;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		k;
	char	**p;

	ft_initvar(&i, &j, &k);
	if (!s)
		return (NULL);
	p = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!p)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			p[++j] = ft_dupword(s, k, i);
			if (!p[j])
				return (ft_free_split(p, ft_countwords(s, c)));
			k = -1;
		}
	}
	return (p);
}
