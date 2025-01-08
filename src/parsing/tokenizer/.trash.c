/*
char	args_append()
{
	char	**new_splited;
	int		new_size;

	new_size = 0;
	while (s[i])
	{
		if (ft_is_command(s[i]) == 1 && ft_is_pipe(s[i]) == 1 && ft_is_redirect_stdin(s[i]) == 1
			&& ft_is_redirect_stdout(s[i]) == 1 && ft_is_HEREDOC(s[i]) == 1 && ft_is_APPEND(s[i]) == 1)
		{
			if (ft_is_command(s[i]) == 1 && ft_is_pipe(s[i]) == 1 && ft_is_redirect_stdin(s[i]) == 1
			&& ft_is_redirect_stdout(s[i]) == 1 && ft_is_HEREDOC(s[i]) == 1 && ft_is_APPEND(s[i]) == 1)
			{
				
			}
		}
		new_size++;
	}
}
void	ft_give_token_type(t_list list)
{
	if (ft_is_command(splited) == 0)
		token_type = CMD;
	if (ft_is_pipe(splited) == 0)
		token_type = PIPE;
	if (ft_is_pipe(splited) == 0)
		token_type = PIPE;
	if (ft_is_redirect_stdin(splited) == 0)
		token_type = REDIRECT_IN;
	if (ft_is_redirect_stdout(splited) == 0)
		token_type = REDIRECT_OUT;
	if (ft_is_HEREDOC(splited) == 0)
		token_type = REDIRECT_OUT;
	if (ft_is_APPEND(splited) == 0)
		token_type = REDIRECT_OUT;
}*/