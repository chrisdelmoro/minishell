/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:50:53 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/01 22:35:21 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <ft_printf.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>

typedef struct s_shell
{
	char	**envp;
	char	*user;
	char	*prompt;
	int		exit;
}	t_shell;

typedef struct s_cmd
{
	char	**cmd_table;
	char	*cmd_typed;
}	t_cmd;

/* initialization_utils.c */
void	initialize_shell(t_shell *shell, const char **envp);
void	initialize_cmd(t_cmd *cmd);

/* shell_utils.c */
char	*find_envp_field(t_shell *shell, const char *field);

/* close_utils.c */
void	free_shell(t_shell *shell);
void	free_cmd(t_cmd *cmd);

#endif