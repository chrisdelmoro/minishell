/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:39:05 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/08 11:40:42 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Initialize shell variables. */

void	initialize_shell(t_shell *shell, const char **envp)
{
	int		i;

	i = 0;
	shell->envp = NULL;
	while (envp[i])
	{
		ft_lstadd_back(&shell->envp, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
	shell->user = find_envp_field(shell, "USER");
	shell->prompt = ft_strjoin(shell->user, " > ");
	shell->exit = 0;
}

/* Initialize cmd variables. Called each time a command is typed. */

void	initialize_cmd(t_cmd *cmd)
{
	cmd->cmd_table = NULL;
	cmd->cmd_typed = NULL;
}
