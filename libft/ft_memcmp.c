/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:07:45 by vsougoum          #+#    #+#             */
/*   Updated: 2024/05/28 15:34:43 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;
	size_t			i;

	s1_tmp = (unsigned char *) s1;
	s2_tmp = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) s1_tmp[i] != (unsigned char) s2_tmp[i])
			return ((unsigned char) s1_tmp[i] - (unsigned char) s2_tmp[i]);
		i++;
	}
	return (0);
}
