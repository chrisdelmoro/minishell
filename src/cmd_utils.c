/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:52:35 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/02 18:52:29 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Prints the contents of cmd table */

void	print_cmd_table(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd_table[i])
	{
		printf("cmd_table[%d] = %s\n", i, cmd->cmd_table[i]);
		printf("cmd_table_len[%d] = %ld\n", i, ft_strlen(cmd->cmd_table[i]));
		i++;
	}
}

/* Allocs cmd_table on struct t_cmd based on how many command and arguments
were typed */

static void	alloc_cmd_table(t_cmd *cmd)
{
	int	i;
	int	cmd_count;

	i = 0;
	cmd_count = 0;
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] == ' ')
			cmd_count++;
		i++;
	}
	cmd->cmd_table = (char **) ft_calloc(cmd_count + 2, sizeof(char *));
}

/* Feeds the cmd_table on the t_cmd struct with every command and arguments
typed */

void	feed_cmd_table(t_cmd *cmd)
{
	int		i;
	int		cmd_table_index;
	char	*tmp_cmd_typed;

	i = 0;
	cmd_table_index = 0;
	tmp_cmd_typed = cmd->cmd_typed;
	cmd->cmd_typed = ft_strtrim(cmd->cmd_typed, " ");
	ft_freethis(&tmp_cmd_typed, NULL);
	alloc_cmd_table(cmd);
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] != ' ')
		{
			if (i == 0 || cmd->cmd_typed[i - 1] == ' ')
			{
				cmd->cmd_table[cmd_table_index] = ft_substr(cmd->cmd_typed, i, \
				ft_strchr(&cmd->cmd_typed[i], ' ') - &cmd->cmd_typed[i]);
				cmd_table_index++;
			}
		}
		i++;
	}
}
