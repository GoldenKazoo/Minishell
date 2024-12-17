/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:33:45 by vsougoum          #+#    #+#             */
/*   Updated: 2024/06/18 12:47:58 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	unsigned char	check_c;
	size_t			i;

	s_tmp = (unsigned char *) s;
	check_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (s_tmp[i] == check_c)
			return (&s_tmp[i]);
		i++;
	}
	return (NULL);
}
