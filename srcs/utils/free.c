/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:52:13 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/22 11:27:31 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_ptwo(char ***pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free_pointer(pointer[i]);
		i++;
	}
	free(pointer);
}

void	free_str(char *str, char *msg)
{
	free(str);
	free(msg);
}

void	free_execve(char *src)
{
	free(src);
	wait(0);
	exit(0);
}

void	free_wait(char *src)
{
	free(src);
	wait(0);
}

void	free_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}
