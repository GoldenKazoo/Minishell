/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:52:20 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 19:51:27 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "tokenizer.h"

typedef struct s_list
{
	char			*prompt;
	int				token_type;
	int				litteral;
	int				closed;
	char			*token;
	struct s_list	*previous_token;
	struct s_list	*next_token;
}	t_list;

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		check;
	char	*input;
	char	*new_input;
	char	**splited;
	char	**paths;

	i = 0;
	input = readline("Entrez quelque chose: ");
	new_input = ft_insert_space(input);
	splited = ft_split(new_input, ' ');
	paths = ft_path_split(envp);
	while (splited[i])
	{
		check = ft_check_identity(splited[i], paths);
		printf("%s : %i\n", splited[i], check);
		i++;
	}
}

//Todo : Fix l'identification (par ex > donne 1)