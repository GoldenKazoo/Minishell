/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:38:58 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/28 17:22:11 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

char	*ft_insert_space(char *prompt)
{
	size_t	len  = strlen(prompt) + ft_count_space(prompt) + 1;
	char	*out = malloc(len);
	size_t	i = 0, j = 0;

	if (!out)
		return (NULL);
	while (prompt[i])
	{
		if (prompt[i] == '<' || prompt[i] == '>' || prompt[i] == '|')
		{
			if (j && out[j - 1] != ' ')
				out[j++] = ' ';
			out[j++] = prompt[i];
			if ((prompt[i] == '>' || prompt[i] == '<') && prompt[i + 1] == prompt[i])
				out[j++] = prompt[++i];      /* copie le 2ᵉ ‘>’ ou ‘<’ */
			if (prompt[i + 1] && prompt[i + 1] != ' ')
				out[j++] = ' ';
		}
		else
			out[j++] = prompt[i];
		i++;
	}
	out[j] = '\0';
	return (out);
}



// int main()
// {
//     char *test = "echo ls-la|cat grep l<outfile";
//     printf("%zu\n", ft_count_space(test));
//     char *new_test = ft_insert_space(test);

//     printf("%s", new_test);
// 	free(new_test);
// }