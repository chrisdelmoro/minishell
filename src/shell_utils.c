/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:41:45 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/30 21:41:59 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*find_envp_field(t_shell *shell, const char *field)
{
	int		i;
	char	*field_tested;

	i = 0;
	while (shell->envp[i])
	{
		field_tested = ft_substr(shell->envp[i], 0, ft_strchr(shell->envp[i], \
		'=') - shell->envp[i]);
		if (!ft_strncmp(field_tested, field, ft_strlen(field_tested)))
		{
			ft_freethis(&field_tested, NULL);
			return (ft_substr(shell->envp[i], ft_strchr(shell->envp[i], '=') \
			- shell->envp[i] + 1, ft_strlen(shell->envp[i])));
		}
		ft_freethis(&field_tested, NULL);
		i++;
	}
	return (NULL);
}
