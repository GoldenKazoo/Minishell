/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:50:54 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 19:31:37 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

char	*ft_get_path_cmd(char **paths, char *cmd)
{
	int		i;
	char	*path_cmd;
	char	*slash_cmd;

	i = -1;
	path_cmd = NULL;
	if (!paths)
		return (NULL);
	slash_cmd = ft_strjoin("/", cmd);
	if (slash_cmd == NULL)
		return (NULL);
	while (paths[++i])
	{
		path_cmd = ft_strjoin(paths[i], slash_cmd);
		if (path_cmd == NULL)
			return (NULL);
		if (access(path_cmd, X_OK) == 0)
		{
			free(slash_cmd);
			return (path_cmd);
		}
		free(path_cmd);
	}
	free(slash_cmd);
	return (NULL);
}
