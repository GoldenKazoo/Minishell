#include "minishell.h"
#include "tokenizer.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

void	handle_redirections(t_command *cmd)
{
	int fd;

	if (cmd->infile)
	{
		fd = open(cmd->infile, O_RDONLY);
		if (fd < 0)
		{
			perror(cmd->infile);
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (cmd->outfile)
	{
		if (cmd->append)
			fd = open(cmd->outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(cmd->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror(cmd->outfile);
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (cmd->heredoc_delim)
	{
		int hd_pipe[2];
		char *line = NULL;

		if (pipe(hd_pipe) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}

		while (1)
		{
			line = readline("> ");
			if (!line)
				break;
			if (strcmp(line, cmd->heredoc_delim) == 0)
			{
				free(line);
				break;
			}
			write(hd_pipe[1], line, strlen(line));
			write(hd_pipe[1], "\n", 1);
			free(line);
		}
		close(hd_pipe[1]);
		dup2(hd_pipe[0], STDIN_FILENO);
		close(hd_pipe[0]);
	}
}

void execute_pipeline(t_command *cmd_list, char **envp, char **paths)
{
	int fd[2];
	int prev_fd = -1;
	pid_t pid;
	t_command *cmd = cmd_list;

	while (cmd)
	{
		if (cmd->next)
			pipe(fd);

		pid = fork();
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, 0);
				close(prev_fd);
			}
			if (cmd->next)
			{
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
			}

			handle_redirections(cmd);

			char *exec_path;
			int use_free = 0;

			if (strchr(cmd->argv[0], '/'))
			{
				exec_path = cmd->argv[0];
				if (access(exec_path, X_OK) != 0)
				{
					perror(exec_path);
					exit(127);
				}
			}
			else
			{
				exec_path = ft_get_path_cmd(paths, cmd->argv[0]);
				if (!exec_path)
				{
					fprintf(stderr, "%s: command not found\n", cmd->argv[0]);
					exit(127);
				}
				use_free = 1;
			}

			execve(exec_path, cmd->argv, envp);
			perror("execve");
			if (use_free)
				free(exec_path);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (prev_fd != -1)
				close(prev_fd);
			if (cmd->next)
			{
				close(fd[1]);
				prev_fd = fd[0];
			}
		}
		cmd = cmd->next;
	}

int status;

while (wait(&status) > 0)
	;

if (WIFEXITED(status))
	g_last_exit_status = WEXITSTATUS(status);
else if (WIFSIGNALED(status))
	g_last_exit_status = 128 + WTERMSIG(status);
}
