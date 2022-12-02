/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:46:52 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/02 18:48:32 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_cmd(t_shell *shell)
{
	t_cmd	cmd;

	initialize_cmd(&cmd);
	cmd.cmd_typed = readline(shell->prompt);
	add_history(cmd.cmd_typed);
	feed_cmd_table(&cmd);
	if (!ft_strncmp(cmd.cmd_table[0], "exit", ft_strlen(cmd.cmd_typed)))
		shell->exit = 1;
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
