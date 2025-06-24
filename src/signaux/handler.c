#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <unistd.h>

void	sigint_handler(int signo)
{
	(void)signo;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	sigquit_handler(int signo)
{
	(void)signo;
}

void	setup_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

//faire une var global pour gerr les signaux ?

