/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-f <jlucas-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:50:53 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/26 02:04:22 by jlucas-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
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
	char	*prompt;
	int		exit;
}	t_shell;

typedef struct s_cmd
{
	t_list	*cmd_table;
	char	*cmd_typed;
	char	**paths;
}	t_cmd;

/* initialization_utils.c */
void	initialize_shell(t_shell *shell, const char **envp);
void	initialize_cmd(t_shell *shell, t_cmd *cmd);

/* shell_utils.c */
char	*find_envp_field(t_shell *shell, const char *field);

/* cmd_utils.c */
void	feed_cmd_table(t_cmd *cmd);
void	print_cmd_table(t_cmd cmd); //remove

/* cmd_exec_utilc.c */
void	execute_cmd(t_shell *shell, t_cmd *cmd);

/* close_utils.c */
void	free_shell(t_shell *shell);
void	free_cmd(t_cmd *cmd);
void	free_argv(char **argv);

void	hijack_signals(void);
int		cmd_is_builtin(char *content);
void	execute_builtin(t_cmd *cmd);
int		ft_pwd(void);
int		ft_echo(t_list *cmd_table);


#endif