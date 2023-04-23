/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:50:14 by ccamargo          #+#    #+#             */
/*   Updated: 2023/04/23 20:15:37 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Form argv as a simple list as it is requeired for executing a binary. */

static char	**form_argv(t_list *cmd_lst)
{
	t_list	*tmp;
	char	**argv;
	int		lst_size;
	int		i;

	lst_size = 0;
	i = 0;
	tmp = cmd_lst;
	while (tmp)
	{
		lst_size++;
		tmp = tmp->next;
	}
	argv = (char **) ft_calloc(lst_size + 1, sizeof (char *));
	while (cmd_lst)
	{
		argv[i] = ft_strdup((char *) cmd_lst->content);
		cmd_lst = cmd_lst->next;
		i++;
	}
	return (argv);
}

static char	*form_tested_path(t_cmd *cmd, int i)
{
	t_list	*tested_cmd;
	char	*tested_path;
	char	*tested_path_tmp;

	tested_cmd = cmd->cmd_table->content;
	tested_path = ft_strjoin(cmd->paths[i], "/");
	tested_path_tmp = tested_path;
	tested_path = ft_strjoin(tested_path, (char *) tested_cmd->content);
	ft_freethis(&tested_path_tmp, NULL);
	return (tested_path);
}

/* Run a binary based on a relative path. */

static void	run_path(t_shell *shell, char **argv)
{
	int		child_pid;
	int		i;

	i = 0;
	if (!access(argv[0], F_OK))
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(argv[0], argv, shell->envp);
		}
		waitpid(child_pid, NULL, 0);
	}
	i++;
}

/* Run a binary based on envp. */

static void	run_sys_bin(t_shell *shell, t_cmd *cmd, char **argv)
{
	char	*tested_path;
	int		child_pid;
	int		i;

	i = 0;
	while (cmd->paths[i])
	{
		tested_path = form_tested_path(cmd, i);
		if (!access(tested_path, F_OK))
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				execve(tested_path, argv, shell->envp);
			}
			waitpid(child_pid, NULL, 0);
			break ;
		}
		ft_freethis(&tested_path, NULL);
		i++;
	}
	ft_freethis(&tested_path, NULL);
}

void	execute_cmd(t_shell *shell, t_cmd *cmd)
{
	t_list	*tested_cmd;
	char	**argv;

	tested_cmd = cmd->cmd_table->content;
	if (!ft_strncmp((char *) tested_cmd->content, "exit", 4))
	{
		shell->exit = 1;
		return ;
	}
	argv = form_argv(cmd->cmd_table->content);
	check_built_in(cmd, shell);
	if (!cmd->builtin)
	{
		if (!ft_strncmp(argv[0], ".", 1) || !ft_strncmp(argv[0], "/", 1))
			run_path(shell, argv);
		else
			run_sys_bin(shell, cmd, argv);
	}
	free_argv(argv);
}
