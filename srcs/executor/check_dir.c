/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:42:21 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:52:27 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/dir.h>

int	check_directory(char *res_split)
{
	DIR	*dir;

	if (res_split[0] == '/'
		|| (res_split[0] == '\'' && res_split[1] == '/'))
	{
		dir = opendir(res_split);
		if (dir)
		{
			printf("minishell: %s: is a directory\n", res_split);
			g_exit_status = 126;
			closedir(dir);
			return (0);
		}
		else
		{
			if (access(res_split, X_OK | F_OK) == 0)
				return (1);
			g_exit_status = 127;
			printf("minishell: %s: not is a directory\n", res_split);
			return (0);
		}
	}
	return (1);
}
