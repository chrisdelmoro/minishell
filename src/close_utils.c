/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:37:04 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/30 21:37:24 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_memory(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->envp[i])
	{
		ft_freethis(&(*shell).envp[i], NULL);
		i++;
	}
	free(shell->envp);
	shell->envp = NULL;
}
