/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_built_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:12:37 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/09 13:42:11 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	no_args(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		printf("declare -x ");
		printf("%s\n", shell->envp[i]);
		i++;
	}
}

static int	is_arg_valid(t_cmd *cmd, char *arg)
{
	int	equals;
	int	i;

	equals = 0;
	i = 0;
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '=')
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putchar_fd(arg[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			cmd->error = 1;
			return (0);
		}
		if (arg[i] == '=')
			equals++;
		i++;
	}
	if (equals > 0)
		return (1);
	else
		return (0);
}

static void	realloc_env(t_shell *shell, char *env_line)
{
	char	**tmp_env;
	int		line_count;
	int		i;

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
	tmp_env[i] = ft_strdup(env_line);
	i = 0;
	while (shell->envp[i])
	{
		ft_freethis(&(*shell).envp[i], NULL);
		i++;
	}
	free(shell->envp);
	shell->envp = tmp_env;
}

void	run_export(t_cmd *cmd, t_shell *shell)
{
	t_list	*tmp_content;

	tmp_content = cmd->cmd_table->content;
	tmp_content = tmp_content->next;
	if (cmd->argc == 1)
	{
		no_args(shell);
		return ;
	}
	while (tmp_content)
	{
		if (is_arg_valid(cmd, (char *) tmp_content->content))
		{
			realloc_env(shell, (char *) tmp_content->content);
		}
		tmp_content = tmp_content->next;
	}
	cmd->builtin = 1;
}
