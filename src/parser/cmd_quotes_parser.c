/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quotes_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:43:15 by ccamargo          #+#    #+#             */
/*   Updated: 2023/04/23 16:01:11 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	remove_double_quotes(t_cmd *cmd, int *i)
{
	char	*quote_removed;
	char	*str_part1;
	char	*str_part2;
	char	*tmp_cmd_typed;

	quote_removed = ft_substr(cmd->cmd_typed, *i + 1, ft_strchr(\
	&cmd->cmd_typed[*i + 1], '"') - &cmd->cmd_typed[*i + 1]);
	str_part1 = ft_substr(cmd->cmd_typed, 0, *i);
	*i += (ft_strchr(&cmd->cmd_typed[*i + 1], '"') - &cmd->cmd_typed[*i]) + 1;
	str_part2 = ft_substr(cmd->cmd_typed, *i, ft_strlen(&cmd->cmd_typed[*i]));
	tmp_cmd_typed = ft_strjoin(str_part1, quote_removed);
	ft_freethis(&cmd->cmd_typed, NULL);
	cmd->cmd_typed = ft_strjoin(tmp_cmd_typed, str_part2);
	ft_freethis(&quote_removed, NULL);
	ft_freethis(&str_part1, NULL);
	ft_freethis(&tmp_cmd_typed, NULL);
	ft_freethis(&str_part2, NULL);
	*i -= 2;
}

static void	remove_single_quotes(t_cmd *cmd, int *i)
{
	char	*quote_removed;
	char	*str_part1;
	char	*str_part2;
	char	*tmp_cmd_typed;

	quote_removed = ft_substr(cmd->cmd_typed, *i + 1, ft_strchr(\
	&cmd->cmd_typed[*i + 1], '\'') - &cmd->cmd_typed[*i + 1]);
	str_part1 = ft_substr(cmd->cmd_typed, 0, *i);
	*i += (ft_strchr(&cmd->cmd_typed[*i + 1], '\'') - &cmd->cmd_typed[*i]) + 1;
	str_part2 = ft_substr(cmd->cmd_typed, *i, ft_strlen(&cmd->cmd_typed[*i]));
	tmp_cmd_typed = ft_strjoin(str_part1, quote_removed);
	ft_freethis(&cmd->cmd_typed, NULL);
	cmd->cmd_typed = ft_strjoin(tmp_cmd_typed, str_part2);
	ft_freethis(&quote_removed, NULL);
	ft_freethis(&str_part1, NULL);
	ft_freethis(&tmp_cmd_typed, NULL);
	ft_freethis(&str_part2, NULL);
	*i -= 2;
}

void	cmd_remove_quotes(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->error)
		return ;
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] == '\'')
		{
			remove_single_quotes(cmd, &i);
		}
		else if (cmd->cmd_typed[i] == '"')
		{
			remove_double_quotes(cmd, &i);
		}
		else
			i++;
	}
}
