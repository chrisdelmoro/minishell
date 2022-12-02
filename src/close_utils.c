/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:37:04 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/02 18:46:37 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* readline() function causes leaks on its own. */
/* Free all memory allocated for the shell struct. */

void	free_shell(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		ft_freethis(&(*shell).envp[i], NULL);
		i++;
	}
	free(shell->envp);
	shell->envp = NULL;
	ft_freethis(&(*shell).user, NULL);
	ft_freethis(&(*shell).prompt, NULL);
	rl_clear_history();
}

/* Free all memory allocated for the cmd struct. */

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd_table[i])
	{
		ft_freethis(&(cmd)->cmd_table[i], NULL);
		i++;
	}
	free(cmd->cmd_table);
	cmd->cmd_table = NULL;
	ft_freethis(&(*cmd).cmd_typed, NULL);
}
