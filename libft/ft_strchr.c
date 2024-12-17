/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:24:09 by vsougoum          #+#    #+#             */
/*   Updated: 2024/06/02 15:59:52 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cast_c;

	cast_c = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cast_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cast_c)
		return ((char *) &s[i]);
	return (NULL);
}
