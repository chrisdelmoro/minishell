#include "./minishell.h"

int	ft_pwd()
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	pwd = NULL;
	return (0);
}
