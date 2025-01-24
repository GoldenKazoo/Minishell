/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:27:59 by zchagar           #+#    #+#             */
/*   Updated: 2025/01/24 16:49:46 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# define CMD		1	//"foo"
# define ARG		2	//"bar"
# define PIPE		3	//"|"
# define STDIN		4	//"<"
# define HEREDOC	5	//"<<"
# define STDOUT		6	//">"
# define APPEND		7	//">>"

typedef struct s_list
{
	char			*prompt;
	int				token_type;
	bool			litteral;
	int				closed;
	char			*token;
	struct s_list	*previous_token;
	struct s_list	*next_token;
}	t_list;

char	**ft_split(char const *s, char c);
size_t	ft_count_space(char *prompt);
char	*ft_insert_space(char *prompt);
char	**ft_path_split(char **envp);
char	*ft_get_path_cmd(char **paths, char *cmd);
int		ft_is_command(char **path, char *string);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_is_redirect_stdin(char *string);
int		ft_is_redirect_stdout(char *string);
int		ft_is_HEREDOC(char *string);
int		ft_is_APPEND(char *string);
int		ft_check_identity(char *string, char **path);
bool	ft_is_litteral(char *string);
char	*ft_replace_litteral(char *string);
t_list	*find_last(t_list *token_list);
void ft_save_space_before(char *input);
void ft_save_space_after(char **splited);
int	ft_get_size_list(char **splited);
void ft_print_token_list(t_list *token_list);
void ft_free_list(t_list *token_list);
#endif