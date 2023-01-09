/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:59:29 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/09 13:42:22 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	feed_tmp_env(t_shell *shell, char **tmp_env, t_list *tmp_content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (shell->envp[i])
	{
		if (i == find_envp_field_index(shell, (char *) tmp_content->content))
			i++;
		if (!shell->envp[i])
			break ;
		tmp_env[j] = ft_strdup(shell->envp[i]);
		i++;
		j++;
	}
}

static void	clear_envp(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		ft_freethis(&(*shell).envp[i], NULL);
		i++;
	}
	free(shell->envp);
}

void	run_unset(t_cmd *cmd, t_shell *shell)
{
	t_list	*tmp_content;
	char	**tmp_env;
	int		line_count;

	tmp_content = cmd->cmd_table->content;
	tmp_content = tmp_content->next;
	while (tmp_content)
	{
		line_count = 0;
		while (shell->envp[line_count])
			line_count++;
		tmp_env = (char **) ft_calloc(line_count, sizeof(char *));
		feed_tmp_env(shell, tmp_env, tmp_content);
		clear_envp(shell);
		shell->envp = tmp_env;
		tmp_content = tmp_content->next;
	}
	cmd->builtin = 1;
}
