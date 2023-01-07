/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:52:35 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/07 14:47:10 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Prints the contents of cmd table */

void	print_cmd_table(t_cmd cmd) //remove
{
	t_list	*tmp;

	while (cmd.cmd_table)
	{
		tmp = cmd.cmd_table->content;
		while (tmp)
		{
			printf("%s", (char *) tmp->content);
			printf(" ");
			tmp = tmp->next;
		}
		printf("\n");
		cmd.cmd_table = cmd.cmd_table->next;
	}
}

void	cmd_count_argc(t_cmd *cmd)
{
	t_list	*tmp_table;
	t_list	*tmp_command;

	tmp_table = cmd->cmd_table;
	while (tmp_table)
	{
		tmp_command = tmp_table->content;
		while (tmp_command)
		{
			cmd->argc++;
			tmp_command = tmp_command->next;
		}
		tmp_table = tmp_table->next;
	}
}
