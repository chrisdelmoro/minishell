/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:46:52 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/30 21:41:39 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, const char **envp)
{
	t_shell	shell;
	char	*user;
	char	*join;
	char	*command;

	(void) argc;
	(void) argv;
	initialize_shell(&shell, envp);
	user = find_envp_field(&shell, "USER");
	join = ft_strjoin(user, " > ");
	command = readline(join);
	while (ft_strncmp(command, "exit", ft_strlen(command)))
	{
		ft_printf("%s\n", command);
		ft_freethis(&command, NULL);
		command = readline(join);
	}
	ft_freethis(&command, NULL);
	ft_freethis(&join, NULL);
	ft_freethis(&user, NULL);
	free_memory(&shell);
	return (0);
}
