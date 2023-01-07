/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:46:52 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/07 14:48:01 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_cmd(t_shell *shell)
{
	t_cmd	cmd;

	initialize_cmd(shell, &cmd);
	cmd.cmd_typed = readline(shell->prompt);
	add_history(cmd.cmd_typed);
	feed_cmd_table(shell, &cmd);
	//print_cmd_table(cmd);
	//printf("cmd_typed: %s\n", cmd.cmd_typed);
	if (!cmd.error)
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
	printf("exit\n");
	free_shell(&shell);
	return (0);
}
