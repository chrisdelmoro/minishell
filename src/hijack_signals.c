#include <minishell.h>

static void	interrupt(int signal);

void	hijack_signals(void)
{
	signal(SIGINT, interrupt);
	signal(SIGQUIT, SIG_IGN);	
}

static void	interrupt(int signal)
{
	(void)signal;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
