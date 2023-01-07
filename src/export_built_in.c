/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_built_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:12:37 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/07 16:13:37 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	run_export(t_cmd *cmd, t_shell *shell)
{
	t_list	*tmp_content;
	char	**tmp_env;
	int		line_count;
	int		i;

	tmp_content = cmd->cmd_table->content;
	line_count = 0;
	i = 0;
	while (shell->envp[line_count])
		line_count++;
	tmp_env = (char **) ft_calloc(line_count + 2, sizeof(char *));
	while (line_count)
	{
		tmp_env[i] = ft_strdup(shell->envp[i]);
		i++;
		line_count--;
	}
	tmp_content = tmp_content->next;
	tmp_env[i] = ft_strdup((char *) tmp_content->content);
	i = 0;
	while (shell->envp[i])
	{
		ft_freethis(&(*shell).envp[i], NULL);
		i++;
	}
	free(shell->envp);
	shell->envp = tmp_env;
}
