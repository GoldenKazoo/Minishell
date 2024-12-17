/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:09:40 by vsougoum          #+#    #+#             */
/*   Updated: 2024/12/17 18:49:02 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, __attribute__ ((unused)) char **argv, __attribute__ ((unused)) char **envp)
{
	char *line;

	if (argc != 1)
		return (1);
	line = readline("shell_issue-5.1$ ");
	printf("%s\n", line);
	free(line);
	return (0);
}
