/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:47:20 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 09:17:39 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_matrix(char **tmp, char **split_cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split_cmd[i])
	{
		if (!ft_strncmp("<<", split_cmd[i], 3)
			|| ft_strncmp("<", split_cmd[i], 3) == 0)
			i++;
		else if (ft_strncmp(">", split_cmd[i], 3) == 0
			|| ft_strncmp(">>", split_cmd[i], 3) == 0)
			i++;
		else
		{
			tmp[j] = ft_strdup(split_cmd[i]);
			j++;
		}
		i++;
	}
}

char	**format_cmd(char **split_cmd)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (split_cmd[i])
	{
		if (!ft_strncmp("<<", split_cmd[i], 3)
			|| ft_strncmp("<", split_cmd[i], 3) == 0)
			i++;
		else if (ft_strncmp(">", split_cmd[i], 3) == 0
			|| ft_strncmp(">>", split_cmd[i], 3) == 0)
			i++;
		else
			j++;
		i++;
	}
	tmp = ft_calloc(j + 1, sizeof(char *));
	fill_matrix(tmp, split_cmd);
	return (tmp);
}
