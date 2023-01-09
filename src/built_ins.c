/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:10:47 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/09 00:33:10 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	check_built_in(t_cmd *cmd, t_shell *shell)
{
	t_list	*tmp_content;

	tmp_content = cmd->cmd_table->content;
	if (!ft_strncmp((char *) tmp_content->content, "echo", \
	ft_strlen((char *) tmp_content->content)))
		run_echo(cmd);
	if (!ft_strncmp((char *) tmp_content->content, "cd", \
	ft_strlen((char *) tmp_content->content)))
		run_cd(cmd, shell);
	if (!ft_strncmp((char *) tmp_content->content, "pwd", \
	ft_strlen((char *) tmp_content->content)))
		run_pwd(shell);
	if (!ft_strncmp((char *) tmp_content->content, "export", \
	ft_strlen((char *) tmp_content->content)))
		run_export(cmd, shell);
	if (!ft_strncmp((char *) tmp_content->content, "unset", \
	ft_strlen((char *) tmp_content->content)))
		run_unset(cmd, shell);
	if (!ft_strncmp((char *) tmp_content->content, "env", \
	ft_strlen((char *) tmp_content->content)))
		run_env(shell);
}
