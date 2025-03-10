/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:00:49 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:12:37 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "commands.h"
#include "executor.h"

void	child_one(t_minishell *shell, char **split, int *input, int *fd)
{
	pid_t	pid;
	char	**tmp;

	pipe(fd);
	redirect(split, fd);
	tmp = format_cmd(split);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		dup2(*input, 0);
		close(*input);
		exec_commands(tmp, shell);
	}
	if (pid > 0)
	{
		close(fd[1]);
		close(*input);
		*input = fd[0];
		free_pointer(tmp);
	}
}

void	last_child(t_minishell *shell, char **split, int input, int *fd)
{
	pid_t	pid;
	char	**tmp;

	redirect(split, fd);
	tmp = format_cmd(split);
	pid = fork();
	if (pid == 0)
	{
		dup2(input, 0);
		close(input);
		exec_commands(tmp, shell);
		close(fd[0]);
		close(fd[1]);
	}
	if (pid > 0)
	{
		close(input);
		free_pointer(tmp);
		final_wait(pid, 0);
	}
}

void	ft_pipex(t_minishell *shell, char ***split, int **fd)
{
	int	i;
	int	k;
	int	input;

	i = 0;
	k = 0;
	input = dup(0);
	while (i < shell->n_comm - 1)
	{
		child_one(shell, split[i], &input, fd[i]);
		i++;
	}
	last_child(shell, split[i], input, fd[i]);
	while (k < shell->n_comm)
	{
		close(fd[k][0]);
		close(fd[k][1]);
		k++;
	}
}
