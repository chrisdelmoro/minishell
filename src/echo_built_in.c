/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:56:31 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/09 13:41:41 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	run_echo(t_cmd *cmd)
{
	t_list	*tmp_content;
	int		new_line;

	tmp_content = cmd->cmd_table->content;
	tmp_content = tmp_content->next;
	new_line = 1;
	if (!ft_strncmp((char *) tmp_content->content, "-n", ft_strlen((char *) \
	tmp_content->content)))
	{
		new_line = 0;
		tmp_content = tmp_content->next;
	}
	while (tmp_content)
	{
		printf("%s", (char *) tmp_content->content);
		if (tmp_content->next)
			printf(" ");
		tmp_content = tmp_content->next;
	}
	if (new_line)
		printf("\n");
	cmd->builtin = 1;
}
