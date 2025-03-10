/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:58:34 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:07:43 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	redirect_trunc_solo(char **args, int i, int *fd)
{
	fd[1] = -1;
	while (args[i] && !ft_strcmp(args[i], ">>"))
	{
		if (args[i + 1])
		{
			if (fd[1] != -1)
				close(fd[1]);
			fd[1] = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			i += 2;
		}
	}
	if (fd[1] == -1)
	{
		perror("open");
		return ;
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	return ;
}

void	redirect_append_solo(char **args, int i, int *fd)
{
	fd[1] = -1;
	while (args[i] && !ft_strcmp(args[i], ">>"))
	{
		if (args[i + 1])
		{
			if (fd[1] != -1)
				close(fd[1]);
			fd[1] = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			i += 2;
		}
	}
	if (fd[1] == -1)
	{
		perror("open");
		return ;
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	return ;
}

void	redirect_input_solo(char **args, int i, int *fd)
{
	fd[0] = -1;
	while (args[i] && !ft_strcmp(args[i], "<"))
	{
		if (args[i + 1])
		{
			if (fd[0] != -1)
				close(fd[0]);
			fd[0] = open(args[i + 1], O_RDONLY);
			i += 2;
		}
	}
	if (fd[0] == -1)
	{
		perror("open");
		return ;
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return ;
}

void	redirect_heredoc_solo(char **args, int i)
{
	int		fd_pipe[2];
	int		k;

	k = 0;
	fd_pipe[0] = -1;
	fd_pipe[1] = -1;
	while (args[i])
	{
		if (args[i] && !ft_strncmp(args[i], "<<", 2))
		{
			if (fd_pipe[0] != -1)
				close(fd_pipe[0]);
			if (fd_pipe[1] != -1)
				close(fd_pipe[1]);
			pipe(fd_pipe);
			create_heredoc(ft_strdup(args[i + 1]), fd_pipe);
		}
		i++;
	}
	if (fd_pipe[0] == -1)
	{
		perror("open");
		return ;
	}
	return ;
}

int	redirect_solo(char **args, int *fd)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (args[i] && !ft_strcmp(args[i], ">"))
			redirect_trunc_solo(args, i, fd);
		if (args[i] && !ft_strcmp(args[i], ">>"))
			redirect_append_solo(args, i, fd);
		if (args[i] && !ft_strcmp(args[i], "<"))
			redirect_input_solo(args, i, fd);
		if (args[i] && !ft_strncmp(args[i], "<<", 3))
			redirect_heredoc_solo(args, i);
	}
	return (0);
}
