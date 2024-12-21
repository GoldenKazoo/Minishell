/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:52:20 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/21 18:45:31 by zchagar          ###   ########.fr       */
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

int	main(void)
{
	int		i;
	char	*input;
	char	*new_input;
	char	**splited;

	i = 0;
	input = readline("Entrez quelque chose: ");
	new_input = ft_insert_space(input);
	splited = ft_split(new_input, ' ');
	while (splited[i])
	{
		printf("%s\n", splited[i]);
		i++;
	}
}
