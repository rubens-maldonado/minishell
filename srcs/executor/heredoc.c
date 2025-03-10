/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:52:44 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:08:37 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	create_here(char *delimiter, int *fd)
{
	char	*heredoc;

	heredoc = readline(">");
	while (42)
	{
		if (!ft_strncmp(heredoc, delimiter, (ft_strlen(delimiter) + 1)))
		{
			free(heredoc);
			break ;
		}
		ft_putendl_fd(heredoc, fd[1]);
		free(heredoc);
		heredoc = readline(">");
	}
	free(delimiter);
	close(fd[1]);
}

void	create_heredoc(char *delimiter, int *fd)
{
	char	*heredoc;

	heredoc = readline("> ");
	while (heredoc && ft_strcmp(heredoc, delimiter))
	{
		if (!heredoc || !ft_strcmp(heredoc, delimiter))
		{
			free(heredoc);
			break ;
		}
		ft_putendl_fd(heredoc, fd[1]);
		free(heredoc);
		heredoc = readline("> ");
	}
	free(delimiter);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	fd[0] = STDIN_FILENO;
	return ;
}
