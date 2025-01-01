/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:31:46 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 19:48:23 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	ft_is_command(char **path, char *string)
{
	char *checker;
	
	checker = ft_get_path_cmd(path, string);
	if (checker != NULL)
		return (CMD);
	return (0);
}

int	ft_is_pipe(char *string)
{
	if (strncmp(string, "|", 1) == 0)
		return (PIPE);
	return (0);
}

int	ft_check_identity(char *string, char **path)
{
	if (ft_is_pipe(string) == PIPE)
		return (PIPE);
	if (ft_is_redirect_stdin(string) == STDIN)
		return (STDIN);
	if (ft_is_redirect_stdin(string) == STDOUT)
		return (STDOUT);
	if (ft_is_HEREDOC(string) == HEREDOC)
		return (HEREDOC);
	if (ft_is_APPEND(string) == APPEND)
		return (APPEND);
	if (ft_is_command(path, string) == CMD)
		return (CMD);
	return (ARG);
}
