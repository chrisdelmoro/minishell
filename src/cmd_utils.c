/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:52:35 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/06 14:41:31 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Prints the contents of cmd table */

void	print_cmd_table(t_cmd cmd)
{
	t_list	*tmp;

	while (cmd.cmd_table)
	{
		tmp = cmd.cmd_table->content;
		while (tmp)
		{
			printf("%s\n", (char *) tmp->content);
			tmp = tmp->next;
		}
		cmd.cmd_table = cmd.cmd_table->next;
	}
}

/* Trims the original command typed by the user of any spaces in the beginning
and end of the string. */

static void	trim_cmd_typed(t_cmd *cmd)
{
	char	*tmp_cmd_typed;

	tmp_cmd_typed = cmd->cmd_typed;
	cmd->cmd_typed = ft_strtrim(cmd->cmd_typed, " ");
	ft_freethis(&tmp_cmd_typed, NULL);
}

/* Breaks the current list of one command into other lists */

static void	break_current_list(t_cmd *cmd, t_list **current_list, int i)
{
	ft_lstadd_back(&(*cmd).cmd_table, ft_lstnew(*current_list));
	ft_lstadd_back(&(*cmd).cmd_table, ft_lstnew(ft_lstnew(ft_substr(\
	cmd->cmd_typed, i, ft_strchr(&cmd->cmd_typed[i], ' ') - \
	&cmd->cmd_typed[i]))));
	*current_list = NULL;
}

/* Feeds the cmd_table on the t_cmd struct with every command and arguments
typed */

void	feed_cmd_table(t_cmd *cmd)
{
	int		i;
	t_list	*current_list;

	i = 0;
	current_list = NULL;
	trim_cmd_typed(cmd);
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] != ' ')
		{
			if (i == 0 || cmd->cmd_typed[i - 1] == ' ')
			{
				if (cmd->cmd_typed[i] == '>' || \
					cmd->cmd_typed[i] == '<' || \
					cmd->cmd_typed[i] == '|')
					break_current_list(cmd, &current_list, i);
				else
					ft_lstadd_back(&current_list, ft_lstnew(\
					ft_substr(cmd->cmd_typed, i, ft_strchr(\
					&cmd->cmd_typed[i], ' ') - &cmd->cmd_typed[i])));
			}
		}
		i++;
	}
	ft_lstadd_back(&(*cmd).cmd_table, ft_lstnew(current_list));
}
