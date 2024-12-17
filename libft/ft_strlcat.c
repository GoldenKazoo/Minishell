/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:13:10 by vsougoum          #+#    #+#             */
/*   Updated: 2024/06/17 11:03:21 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t catsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	if (catsize == 0)
		return (ft_strlen(src));
	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (catsize <= dest_len)
	{
		return (catsize + src_len);
	}
	while (src[i] != '\0' && (dest_len + i) < (catsize - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
