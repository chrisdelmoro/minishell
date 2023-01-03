/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-f <jlucas-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:46:52 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/18 10:56:22 by jlucas-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_cmd(t_shell *shell)
{
	t_cmd	cmd;

	hijack_signals();
	initialize_cmd(shell, &cmd);
	cmd.cmd_typed = readline(shell->prompt);
	add_history(cmd.cmd_typed);
	feed_cmd_table(&cmd);
	execute_cmd(shell, &cmd);
	free_cmd(&cmd);
}

int	main(int argc, char **argv, const char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	initialize_shell(&shell, envp);
	while (!shell.exit)
	{
		handle_cmd(&shell);
	}
	free_shell(&shell);
	return (0);
}
