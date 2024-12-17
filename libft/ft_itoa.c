/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:42:27 by vsougoum          #+#    #+#             */
/*   Updated: 2024/07/08 11:35:29 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_size(long nb)
{
	size_t	nb_len;

	nb_len = 0;
	if (nb < 0)
	{
		nb_len++;
		nb = -nb;
	}
	if (nb == 0)
		nb_len = 1;
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			nb_len++;
		}
	}
	return (nb_len);
}

char	*ft_itoa(int n)
{
	long	nb_tmp;
	size_t	nb_len;
	char	*res;

	nb_tmp = (long) n;
	nb_len = ft_int_size(nb_tmp);
	res = malloc(sizeof(char) * (nb_len + 1));
	if (!res)
		return (NULL);
	res[0] = '0';
	if (nb_tmp < 0)
	{
		nb_tmp = -nb_tmp;
		res[0] = '-';
	}
	res[nb_len] = '\0';
	while (nb_tmp != 0)
	{
		res[--nb_len] = (nb_tmp % 10) + '0';
		nb_tmp = nb_tmp / 10;
	}
	return (res);
}
