/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:38:02 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/24 22:05:16 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "commands.h"

char	*get_env(char *env, t_minishell *shell)
{
	char	*res;

	res = NULL;
	if (!ft_strcmp(env, "-"))
	{
		if (search_env("OLDPWD=", shell) == -1)
			return (NULL);
		res = shell->env[search_env("OLDPWD=", shell)] + 7;
	}
	return (res);
}

void	print_env(t_minishell *shell)
{
	int	i;

	i = -1;
	while (shell->env[++i])
		printf("%s\n", shell->env[i]);
}

int	search_env(char	*env, t_minishell *shell)
{
	int	i;

	i = 0;
	while (ft_strcmp(shell->list[i], env) && shell->list[i + 1])
		i++;
	if (!ft_strcmp(shell->list[i], env))
		return (i);
	else
		return (-1);
}

int	size_env(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
		i++;
	shell->env[i + 1] = NULL;
	return (i);
}

void	my_env(char **str, t_minishell *shell)
{
	int	i;

	i = 0;
	shell->env = ft_calloc(sizeof(char *), count(str) + 2);
	while (str[i])
	{
		shell->env[i] = ft_strdup(str[i]);
		i++;
	}
}
