/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:37:04 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/08 11:41:37 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* readline() function causes leaks on its own. */
/* Free all memory allocated for the shell struct. */

void	free_shell(t_shell *shell)
{
	ft_lstclear(&shell->envp, free);
	ft_freethis(&(*shell).user, NULL);
	ft_freethis(&(*shell).prompt, NULL);
	rl_clear_history();
}

/* Free all memory allocated for the cmd struct. */

void	free_cmd(t_cmd *cmd)
{
	t_list	*tmp;

	tmp = cmd->cmd_table;
	while (tmp)
	{
		ft_lstclear((t_list **) &tmp->content, free);
		tmp = tmp->next;
	}
	ft_lstclear(&(*cmd).cmd_table, free);
	ft_freethis(&(*cmd).cmd_typed, NULL);
}
