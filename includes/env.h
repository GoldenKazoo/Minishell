/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:10:20 by vsougoum          #+#    #+#             */
/*   Updated: 2025/06/02 19:45:17 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "../libft/libft.h"

typedef struct s_env
{
	char			*row;
	struct s_env	*next;
} t_env;

t_env	*ft_lstnew(char	*str);
t_env	*ft_lstlast(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);

t_env	*ft_copy_env(char **env);
void	ft_free_env(t_env *lst);
int		ft_print_env(t_env *lst_env);

char	**ft_char_copy_env(t_env *env);

#endif
