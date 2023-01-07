/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:50:53 by ccamargo          #+#    #+#             */
/*   Updated: 2023/01/07 16:13:18 by ccamargo         ###   ########.fr       */
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
	int		argc;
	int		error;
}	t_cmd;

/* initialization_utils.c */
void	initialize_shell(t_shell *shell, const char **envp);
void	initialize_cmd(t_shell *shell, t_cmd *cmd);

/* shell_utils.c */
char	*find_envp_field(t_shell *shell, const char *field);
int		find_envp_field_index(t_shell *shell, const char *field);
void	replace_env_field(t_shell *shell, const char *field, \
const char *new_field);

/* built_ins.c */
void	check_built_in(t_cmd *cmd, t_shell *shell);

/* cd_built_in.c */
void	run_cd(t_cmd *cmd, t_shell *shell);

/* env_built_in.c */
void	run_env(t_shell *shell);

/* pwd_built_in.c */
void	run_pwd(t_shell *shell);

/* echo_built_in.c */
void	run_echo(t_cmd *cmd);

/* export_built_in.c */
void	run_export(t_cmd *cmd, t_shell *shell);

/* unset_built_in.c */
void	run_unset(t_cmd *cmd, t_shell *shell);

/* cmd_utils.c */
void	print_cmd_table(t_cmd cmd);
void	cmd_count_argc(t_cmd *cmd);

/* cmd_parser.c */
void	feed_cmd_table(t_shell *shell, t_cmd *cmd);

/* cmd_pipe_parser.c */
void	cmd_pipe_parser(t_cmd *cmd);

/* cmd_redirect_parser.c */
void	cmd_redirect_parser(t_cmd *cmd);

/* cmd_validation_utils.c */
void	check_number_of_quotes(t_cmd *cmd);

/* cmd_var_expansion.c */
void	cmd_expand_var(t_shell *shell, t_cmd *cmd);

/* cmd_quotes_parser.c */
void	cmd_remove_quotes(t_cmd *cmd);

/* cmd_space_parser.c */
void	trim_cmd_typed(t_cmd *cmd);
void	cmd_space_parser(t_cmd *cmd);

/* cmd_error.c */
void	throw_err(t_cmd *cmd, char *err);

/* cmd_exec_utilc.c */
void	execute_cmd(t_shell *shell, t_cmd *cmd);

/* close_utils.c */
void	free_shell(t_shell *shell);
void	free_cmd(t_cmd *cmd);
void	free_argv(char **argv);

#endif