/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:29:53 by vsougoum          #+#    #+#             */
/*   Updated: 2024/06/18 12:46:57 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_tmp;
	unsigned char	*dest_tmp;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	src_tmp = (unsigned char *) src;
	dest_tmp = (unsigned char *) dest;
	i = 0;
	if (src_tmp < dest_tmp)
	{
		while (++i <= n)
			dest_tmp[n - i] = src_tmp[n - i];
	}
	else
	{
		while (n-- > 0)
			*(dest_tmp++) = *(src_tmp++);
	}
	return (dest);
}
