/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:40:45 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 19:42:11 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	ft_is_redirect_stdin(char *string)
{
	if (strncmp(string, "<", 2) == 0)
		return (STDIN);
	return (0);
}

int	ft_is_redirect_stdout(char *string)
{
	if (strncmp(string, ">", 2) == 0)
		return (STDOUT);
	return (0);
}

int	ft_is_HEREDOC(char *string)
{
	if (strncmp(string, "<<", 2) == 0)
		return (HEREDOC);
	return (0);
}

int	ft_is_APPEND(char *string)
{
	if (strncmp(string, ">>", 2) == 0)
		return (APPEND);
	return (0);
}