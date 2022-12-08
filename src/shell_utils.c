/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:41:45 by ccamargo          #+#    #+#             */
/*   Updated: 2022/12/08 11:48:44 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* Find enviroment variables in the struct s_shell. */

char	*find_envp_field(t_shell *shell, const char *field)
{
	char	*field_tested;
	t_list	*tmp_envp;

	if (!shell || !field)
		return (NULL);
	tmp_envp = shell->envp;
	while (tmp_envp)
	{
		field_tested = ft_substr((char *) tmp_envp->content, 0, ft_strchr(\
		(char *) tmp_envp->content, '=') - (char *) tmp_envp->content);
		if (!ft_strncmp(field_tested, field, ft_strlen(field_tested)))
		{
			ft_freethis(&field_tested, NULL);
			return (ft_substr((char *) tmp_envp->content, ft_strchr((char *) \
			tmp_envp->content, '=') - (char *) tmp_envp->content + 1, \
			ft_strlen((char *) tmp_envp->content)));
		}
		ft_freethis(&field_tested, NULL);
		tmp_envp = tmp_envp->next;
	}
	return (NULL);
}
