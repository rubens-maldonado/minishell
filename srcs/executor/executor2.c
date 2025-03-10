/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:51:06 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:06:42 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	pidwait(pid_t pid, int exit, char *cmd)
{
	waitpid(pid, &exit, 0);
	free_wait(cmd);
	if (WIFEXITED(exit))
		g_exit_status = WEXITSTATUS(exit);
	if (WIFSIGNALED(exit))
		g_exit_status = 128 + WTERMSIG(exit);
}

void	final_wait(pid_t pid, int exit)
{
	int	exit_status;
	int	final_w;

	exit_status = 0;
	final_w = 0;
	while (final_w != -1)
		final_w = waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit))
		g_exit_status = WEXITSTATUS(exit);
	if (WIFSIGNALED(exit))
		g_exit_status = 128 + WTERMSIG(exit);
}
