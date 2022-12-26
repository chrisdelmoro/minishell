/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:28:23 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/23 18:35:14 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Function checks if pipe follows spaces or not */

static void	cmd_pipe_parser_before(t_cmd *cmd, int *i)
{
	char	*str_part1;
	char	*str_part2;
	char	*tmp;

	str_part1 = ft_substr(cmd->cmd_typed, 0, *i);
	str_part2 = ft_substr(cmd->cmd_typed, *i, ft_strlen(cmd->cmd_typed));
	tmp = str_part1;
	str_part1 = ft_strjoin(str_part1, " ");
	ft_freethis(&tmp, NULL);
	ft_freethis(&cmd->cmd_typed, NULL);
	cmd->cmd_typed = ft_strjoin(str_part1, str_part2);
	ft_freethis(&str_part1, NULL);
	ft_freethis(&str_part2, NULL);
	*i += 1;
}

/* Function checks if pipe is followed by spaces or not */

static void	cmd_pipe_parser_after(t_cmd *cmd, int *i)
{
	char	*str_part1;
	char	*str_part2;
	char	*tmp;

	str_part1 = ft_substr(cmd->cmd_typed, 0, *i + 1);
	str_part2 = ft_substr(cmd->cmd_typed, *i + 1, ft_strlen(cmd->cmd_typed));
	tmp = str_part1;
	str_part1 = ft_strjoin(str_part1, " ");
	ft_freethis(&tmp, NULL);
	ft_freethis(&cmd->cmd_typed, NULL);
	cmd->cmd_typed = ft_strjoin(str_part1, str_part2);
	ft_freethis(&str_part1, NULL);
	ft_freethis(&str_part2, NULL);
	*i += 1;
}

/* Function analizes cmd_typed to fix possible type errors with pipes */

void	cmd_pipe_parser(t_cmd *cmd)
{
	int		i;

	if (cmd->error)
		return ;
	i = 0;
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] == '|')
		{
			if (cmd->cmd_typed[i - 1] != ' ')
				cmd_pipe_parser_before(cmd, &i);
			if (cmd->cmd_typed[i + 1] != ' ')
				cmd_pipe_parser_after(cmd, &i);
		}
		i++;
	}
}
