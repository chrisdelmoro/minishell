/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:40:00 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/23 18:40:09 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	check_number_of_quotes(t_cmd *cmd)
{
	int	single_quote_count;
	int	double_quote_count;
	int	i;

	single_quote_count = 0;
	double_quote_count = 0;
	i = 0;
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] == '\'')
			single_quote_count++;
		if (cmd->cmd_typed[i] == '\"')
			double_quote_count++;
		i++;
	}
	if (single_quote_count % 2 != 0)
		throw_err(cmd, "syntax error from unclosed quotes `'`");
	if (double_quote_count % 2 != 0)
		throw_err(cmd, "syntax error from unclosed quotes `\"`");
}
