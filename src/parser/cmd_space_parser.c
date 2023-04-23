/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_space_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:52:22 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/23 18:35:57 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Trims the original command typed by the user of any spaces in the beginning
and end of the string. */

void	trim_cmd_typed(t_cmd *cmd)
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

void	cmd_space_parser(t_cmd *cmd)
{
	int		i;
	t_list	*current_list;

	if (cmd->error)
		return ;
	i = 0;
	current_list = NULL;
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] != ' ')
		{
			if (i == 0 || cmd->cmd_typed[i - 1] == ' ')
			{
				if (cmd->cmd_typed[i] == '>' || cmd->cmd_typed[i] == '<' || \
				cmd->cmd_typed[i] == '|')
					break_current_list(cmd, &current_list, i);
				else
					ft_lstadd_back(&current_list, ft_lstnew(ft_substr(\
					cmd->cmd_typed, i, ft_strchr(&cmd->cmd_typed[i], ' ') - \
					&cmd->cmd_typed[i])));
			}
		}
		i++;
	}
	ft_lstadd_back(&(*cmd).cmd_table, ft_lstnew(current_list));
}
