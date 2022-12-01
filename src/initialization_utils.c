/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:39:05 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/30 21:39:48 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	initialize_shell(t_shell *shell, const char **envp)
{
	int	line_count;
	int	i;

	line_count = 0;
	i = 0;
	while (envp[line_count])
		line_count++;
	shell->envp = (char **) ft_calloc(line_count + 1, sizeof(char *));
	while (line_count)
	{
		shell->envp[i] = ft_strdup(envp[i]);
		i++;
		line_count--;
	}
}
