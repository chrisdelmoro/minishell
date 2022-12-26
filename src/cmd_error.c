/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:04:30 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/22 19:06:14 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	throw_err(t_cmd *cmd, char *err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	cmd->error = 1;
}
