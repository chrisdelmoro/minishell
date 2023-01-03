#include <minishell.h>

int		cmd_is_builtin(char *content)
{
	if (!ft_strncmp(content, "echo\0", 5))
		return (1);
	if (!ft_strncmp(content, "pwd\0", 4))
		return (1);
	/*if (!ft_strncmp(content, "cd\0", 3))
		return (1);
	if (!ft_strncmp(content, "export\0", 7))
		return (1);
	if (!ft_strncmp(content, "unset\0", 6))
		return (1);
	if (!ft_strncmp(content, "env\0", 4))
		return (1);*/
	return (0);
}

void	execute_builtin(t_cmd *cmd)
{
	t_list	*tested_cmd;

	tested_cmd = cmd->cmd_table->content;
	/*if (!ft_strncmp(tested_cmd->content, "env\0", 4))
		ft_env(cmd);
	else if (!ft_strncmp(tested_cmd->content, "export\0", 7))
		ft_export(cmd->exec);
	else */
	if (!ft_strncmp(tested_cmd->content, "echo\0", 5))
		ft_echo(cmd->cmd_table);
	else if (!ft_strncmp(tested_cmd->content, "pwd\0", 4))
		ft_pwd();
	/*else if (!ft_strncmp(tested_cmd->content, "cd\0", 3))
		ft_cd(cmd->exec);
	else if (!ft_strncmp(tested_cmd->content, "export\0", 7))
		ft_export(cmd->exec);
	else if (!ft_strncmp(tested_cmd->content, "unset\0", 6))
		ft_unset(cmd->exec);*/
}