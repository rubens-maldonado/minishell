/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:28:43 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 09:47:04 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "commands.h"
#include "executor.h"

void	redirect_trunc(char **args, int i, int *fd)
{
	args[i] = NULL;
	fd[1] = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		perror("open");
		return ;
	}
	close(fd[0]);
	return ;
}

void	redirect_append(char **args, int i, int *fd)
{
	args[i] = NULL;
	fd[1] = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[1] == -1)
	{
		perror("open");
		return ;
	}
	close(fd[0]);
	return ;
}

void	redirect_input(char **args, int i, int *fd)
{
	args[i] = NULL;
	fd[0] = open(args[i + 1], O_RDONLY);
	if (fd[0] == -1)
	{
		perror("open");
		return ;
	}
	close(fd[1]);
	return ;
}

void	redirect_heredoc(char **args, int i, int *fd)
{
	char	*delimiter;
	int		fd_pipe[2];

	pipe(fd_pipe);
	delimiter = ft_strdup(args[i + 1]);
	if (fd_pipe[0] == -1)
	{
		perror("open");
		return ;
	}
	create_here(delimiter, fd_pipe);
	*fd = fd_pipe[0];
	return ;
}

int	redirect(char **args, int *fd)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], ">"))
			redirect_trunc(args, i, fd);
		if (!ft_strcmp(args[i], ">>"))
			redirect_append(args, i, fd);
		if (!ft_strcmp(args[i], "<"))
			redirect_input(args, i, fd);
		if (!ft_strcmp(args[i], "<<"))
			redirect_heredoc(args, i, fd);
	}
	return (0);
}
