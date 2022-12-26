/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:52:35 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/19 19:44:04 by ccamargo         ###   ########.fr       */
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
