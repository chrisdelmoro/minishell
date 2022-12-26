/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_var_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:55:58 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/23 18:35:45 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	replace_cmd_typed(t_cmd *cmd, char *found_var, int i, int j)
{
	char	*str_part1;
	char	*str_part2;
	char	*tmp_cmd_typed;

	str_part1 = ft_substr(cmd->cmd_typed, 0, i);
	str_part2 = ft_substr(cmd->cmd_typed, i + j, ft_strlen(cmd->cmd_typed));
	tmp_cmd_typed = ft_strjoin(str_part1, found_var);
	ft_freethis(&cmd->cmd_typed, NULL);
	cmd->cmd_typed = ft_strjoin(tmp_cmd_typed, str_part2);
	ft_freethis(&str_part1, NULL);
	ft_freethis(&tmp_cmd_typed, NULL);
	ft_freethis(&str_part2, NULL);
}

static void	search_env_vars(t_shell *shell, t_cmd *cmd, int i)
{
	char	*env_var;
	char	*found_var;
	int		j;

	j = 1;
	found_var = NULL;
	while (cmd->cmd_typed[i + j] && !found_var)
	{
		env_var = ft_substr(cmd->cmd_typed, i + 1, j);
		found_var = find_envp_field(shell, env_var);
		if (!found_var)
			ft_freethis(&found_var, NULL);
		ft_freethis(&env_var, NULL);
		j++;
	}
	replace_cmd_typed(cmd, found_var, i, j);
	ft_freethis(&found_var, NULL);
}

void	cmd_expand_var(t_shell *shell, t_cmd *cmd)
{
	int		quoted;
	int		i;

	if (cmd->error)
		return ;
	quoted = 0;
	i = 0;
	while (cmd->cmd_typed[i])
	{
		if (cmd->cmd_typed[i] == '\'' && quoted == 0)
			quoted = 1;
		else if (cmd->cmd_typed[i] == '\'' && quoted == 1)
			quoted = 0;
		if (cmd->cmd_typed[i] == '$' && quoted == 0)
			search_env_vars(shell, cmd, i);
		i++;
	}
}
