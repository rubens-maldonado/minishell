/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:09:42 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/25 18:25:03 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "commands.h"
#include "executor.h"

char	**duper(t_minishell *shell)
{
	char	**env;
	int		i;

	env = ft_calloc(sizeof(char *), count_env(shell) + 3);
	i = -1;
	while (shell->env[++i])
		env[i] = ft_strdup(shell->env[i]);
	return (env);
}

void	export_str(char *str, t_minishell *shell)
{
	int		pos;
	char	*msg;
	char	**env;

	pos = 0;
	env = duper(shell);
	msg = filling_msg(ft_strdup(str));
	if (msg == NULL)
	{
		free_all(shell, msg, str);
		return ;
	}
	set_list(shell);
	pos = search_env(msg, shell);
	if (pos >= 0)
	{
		free(env[pos]);
		env[pos] = ft_strdup(str);
	}
	else
		env[size_env(shell)] = ft_strdup(str);
	free_alltwo(shell, str, msg);
	shell->env = env;
}
