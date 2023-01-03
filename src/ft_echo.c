#include "minishell.h"

int	ft_echo(t_list *cmd_table)
{
	char	flag;
	t_list	*tmp;
	t_list	*tested_cmd;

	flag = ' ';
	tested_cmd = cmd_table->content;
	if (tested_cmd->next->content != NULL && *((char*)tested_cmd->next->content) == '-')
	{
		flag = *(((char*)tested_cmd->next->content) + 1);
		tested_cmd = tested_cmd->next;
	}
	tmp = tested_cmd->next;
	while (tmp)
	{
		printf("%s ", (char *) tmp->content);
		tmp = tmp->next;
	}
	if (flag != 'n')
		printf("\n");
	return (0);
}
