/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:39:10 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:31:56 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "commands.h"
#include "executor.h"
#include "parse.h"
#include <fcntl.h>

void	free_fds(int **fds, t_minishell *shell)
{
	int	i;

	i = 0;
	while (i < shell->n_comm)
	{
		free(fds[i]);
		i++;
	}
	free(fds);
}

int	**create_fds(t_minishell *shell)
{
	int	**fd;
	int	i;

	i = 0;
	fd = malloc(sizeof(int *) * shell->n_comm);
	while (i < shell->n_comm)
	{
		fd[i] = malloc(sizeof(int) * 2);
		fd[i][0] = 3;
		fd[i][1] = 3;
		i++;
	}
	return (fd);
}

void	split_commands(char **args, t_minishell *shell)
{
	char	***aux;
	int		i;
	int		**fds;
	char	**temp;

	i = 1;
	aux = ft_calloc(sizeof(char **), shell->n_comm + 1);
	aux[0] = ft_split(args[0], '\a');
	while (i < shell->n_comm)
	{
		aux[i] = ft_split(&args[i][1], '\a');
		i++;
	}
	fds = create_fds(shell);
	if (shell->n_comm > 1)
		ft_pipex(shell, aux, fds);
	else
	{
		redirect_solo(aux[0], fds[0]);
		temp = format_cmd(aux[0]);
		exec_commands(temp, shell);
		free_pointer(temp);
	}
	free_fds(fds, shell);
	free_ptwo(aux);
}

void	exec_commands(char **res_split, t_minishell *shell)
{
	if (!ft_strcmp(res_split[0], "echo"))
		echo(res_split, count(res_split));
	else if (!ft_strcmp(res_split[0], "env"))
		print_env(shell);
	else if (!ft_strcmp(res_split[0], "pwd"))
		pwd();
	else if (!ft_strcmp(res_split[0], "cd"))
		cd(res_split, shell);
	else if (!ft_strcmp(res_split[0], "unset"))
		unset(ft_strdup(res_split[1]), shell);
	else if (!ft_strcmp(res_split[0], "export"))
		export_str(ft_strdup(res_split[1]), shell);
	else
		my_execv(shell, res_split);
	if (shell->n_comm > 1)
		exit(g_exit_status);
	dup2(shell->fd_in, 0);
	dup2(shell->fd_out, 1);
}
