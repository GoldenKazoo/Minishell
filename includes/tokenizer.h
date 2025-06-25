/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:27:59 by zchagar           #+#    #+#             */
/*   Updated: 2025/06/25 00:53:13 by marvin           ###   ########.fr       */
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
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <limits.h>

# define CMD		1	//"foo"
# define ARG		2	//"bar"
# define PIPE		3	//"|"
# define STDIN		4	//"<"
# define HEREDOC	5	//"<<"
# define STDOUT		6	//">"
# define APPEND		7	//">>"

typedef struct s_list
{
	int				token_type;
	bool			litteral;
	int				closed;
	char			*token;
	struct s_list	*previous_token;
	struct s_list	*next_token;
}	t_list;

typedef struct s_command
{
    char    **argv;
    char    *infile;
    char    *outfile;
    char    *heredoc_delim;
    bool    append;
    struct s_command *next;
} t_command;

char	**ft_split(char const *s, char c);
size_t	ft_count_space(char *prompt);
char	*ft_insert_space(char *prompt);
char	**ft_path_split(char **envp);
char	*ft_get_path_cmd(char **paths, char *cmd);
int		ft_is_command(char **path, char *string);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_is_redirect_stdin(char *string);
int		ft_is_redirect_stdout(char *string);
int		ft_is_heredoc(char *string);
int		ft_is_append(char *string);
int		ft_check_identity(char *string, char **path);
bool	ft_is_litteral(char *string);
char	*ft_replace_litteral(char *string);
t_list	*find_last(t_list *token_list);
void ft_save_space_before(char *input);
void ft_save_space_after(char **splited);
int	ft_get_size_list(char **splited);
void ft_print_token_list(t_list *token_list);
void ft_free_list(t_list *token_list);
bool	ft_contain_quotes(char *str);
char *ft_convert_into_double_quote(char *str);
bool	ft_validate_all_quotes(char *str);
char	*ft_strdup(const char *src);
void ft_free_split(char **array);
int	quotes_are_closed(const char *s);

t_command	*token_list_to_command_list(t_list *token_list);
void		print_command_list(t_command *cmds);
void	setup_signals(void);
void free_and_reset(char *ptr);
void	ft_tokenize(t_list **token_list, char **splited, char **paths);
void	ft_check_integrity(t_list *token_list, __attribute__ ((unused)) int list_size);
void ft_checker_quotes(t_list *token_list);
void execute_pipeline(t_command *cmd_list, char **envp, char **paths);

#endif
