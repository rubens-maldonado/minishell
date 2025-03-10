/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:19:13 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/24 22:04:31 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "commands.h"
#include "executor.h"

void	cd_h(char **path, t_minishell *shell)
{
	set_list(shell);
	if (get_env(path[1], shell) == NULL)
		printf("cd: OLDPWD not set\n");
	else
	{
		chdir(get_env(path[1], shell));
		free(shell->env[search_env("OLDPWD=", shell)]);
		shell->env[search_env("OLDPWD=",
				shell)] = ft_strjoin_nofree("OLDPWD=", shell->oldpwd);
		free(shell->env[search_env("PWD=", shell)]);
		shell->env[search_env("PWD=",
				shell)] = ft_strjoin_nofree("PWD=", get_pwd());
	}
	free_pointer(shell->list);
}

void	cd(char **path, t_minishell *shell)
{
	shell->oldpwd = get_pwd();
	if (!path[1])
		return ;
	if (!ft_strcmp(path[1], "-"))
		cd_h(path, shell);
	else if (chdir(path[1]) == -1)
		printf("cd: %s: No such file or directory\n", path[1]);
	else
	{
		set_list(shell);
		if (search_env("OLDPWD=", shell) == -1)
			shell->env[size_env(shell)] = ft_strjoin_nofree("OLDPWD=",
					shell->oldpwd);
		else
		{
			free(shell->env[search_env("OLDPWD=", shell)]);
			shell->env[search_env("OLDPWD=",
					shell)] = ft_strjoin_nofree("OLDPWD=", shell->oldpwd);
		}
		free(shell->env[search_env("PWD=", shell)]);
		shell->env[search_env("PWD=",
				shell)] = ft_strjoin_nofree("PWD=", get_pwd());
		free_pointer(shell->list);
	}
}
