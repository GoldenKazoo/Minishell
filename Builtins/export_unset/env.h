/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:09:30 by vsougoum          #+#    #+#             */
/*   Updated: 2025/06/02 10:22:04 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_env
{
	char			*row;
	struct s_env	*next;
} t_env;

int		ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
int		ft_char_idx(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strchr(char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

t_env	*ft_lstnew(char	*str);
t_env	*ft_lstlast(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);

t_env	*ft_copy_env(char **env);
void	ft_free_env(t_env *lst);
int		ft_print_env(t_env *lst_env);
int		ft_edit_var_env(t_env **env, char *new_row);

int		ft_export(t_env **env, char *new_row);
void	ft_unset(t_env **env, char *env_var);

t_env	*ft_find_row(t_env *lst, char *row_to_find);
t_env	*ft_find_prev_row(t_env *lst, char *row_to_find);
t_env	*ft_find_next_row(t_env *lst, char *row_to_find);
int		ft_lst_remove_node(t_env **lst, char *row_to_remove);

#endif
