/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:39:05 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/07 14:37:09 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Initialize shell variables. */

void	initialize_shell(t_shell *shell, const char **envp)
{
	int		line_count;
	char	*user;
	int		i;

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
	replace_env_field(shell, "SHELL", "SHELL=minishell");
	user = find_envp_field(shell, "USER");
	shell->prompt = ft_strjoin(user, " > ");
	ft_freethis(&user, NULL);
	shell->exit = 0;
}

/* Initialize cmd variables. Called each time a command is typed. */

void	initialize_cmd(t_shell *shell, t_cmd *cmd)
{
	char	*env_path;

	cmd->cmd_table = NULL;
	cmd->cmd_typed = NULL;
	cmd->error = 0;
	env_path = find_envp_field(shell, "PATH");
	cmd->paths = ft_split(env_path, ':');
	ft_freethis(&env_path, NULL);
	cmd->argc = 0;
}
