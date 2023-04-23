/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:02:13 by ccamargo          #+#    #+#             */
/*   Updated: 2023/04/23 16:00:07 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Feeds the cmd_table on the t_cmd struct with every command and arguments
typed */

void	feed_cmd_table(t_shell *shell, t_cmd *cmd)
{
	trim_cmd_typed(cmd);
	check_number_of_quotes(cmd);
	cmd_pipe_parser(cmd);
	cmd_redirect_parser(cmd);
	cmd_expand_var(shell, cmd);
	cmd_remove_quotes(cmd);
	cmd_space_parser(cmd);
	cmd_count_argc(cmd);
}
