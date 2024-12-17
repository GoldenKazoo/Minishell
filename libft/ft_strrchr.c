/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:57:52 by vsougoum          #+#    #+#             */
/*   Updated: 2024/05/28 15:51:33 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cast_c;
	char	*checkc;

	cast_c = (char) c;
	i = 0;
	checkc = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == cast_c)
			checkc = (char *) &s[i];
		i++;
	}
	if (s[i] == cast_c)
		checkc = (char *) &s[i];
	return (checkc);
}
