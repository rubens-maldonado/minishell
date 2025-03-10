/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:53:25 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 11:00:17 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	search_path(t_minishell *shell)
{
	char	*res;

	set_list(shell);
	res = ft_strdup(shell->env[search_env("PATH", shell)] + 4);
	free_pointer(shell->list);
	shell->env_path = ft_split(res, ':');
	free(res);
}

char	*mount_command(t_minishell *shell, char **res_split)
{
	char	*cmd_tmp;
	char	*cmd;
	int		i;

	i = 0;
	while (shell->env_path[i])
	{
		cmd_tmp = ft_strjoin(ft_strdup(shell->env_path[i]), "/");
		cmd = ft_strjoin_nofree(cmd_tmp, res_split[0]);
		free(cmd_tmp);
		if (access(cmd, X_OK | F_OK) == 0)
		{
			free_pointer(shell->env_path);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	free_pointer(shell->env_path);
	return (ft_strdup(res_split[0]));
}

void	execv_group(t_minishell *shell, pid_t pid, char **res_split, char *cmd)
{
	if (pid == 0)
	{
		execve(cmd, res_split, shell->env);
		write(2, "minishell: ", 11);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": command not found\n", 20);
		free_execve(cmd);
	}
	else
		free_execve(cmd);
}

void	my_execv(t_minishell *shell, char **res_split)
{
	char	*cmd;
	pid_t	pid;
	int		exit;

	search_path(shell);
	exit = 0;
	pid = -1;
	cmd = mount_command(shell, res_split);
	pid = fork();
	if (pid == 0)
	{
		set_signal_child();
		if (res_split[0] != NULL)
			execv_group(shell, pid, res_split, cmd);
		else
		{
			free_pointer(res_split);
			free(cmd);
		}
	}
	else if (pid > 0)
		pidwait(pid, exit, cmd);
}
