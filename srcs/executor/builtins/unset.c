/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:02:23 by rmaldona          #+#    #+#             */
/*   Updated: 2023/04/24 22:07:27 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expanser.h"

void	unset(char *str, t_minishell *shell)
{
	int		i;
	int		j;
	char	**unset;

	i = -1;
	j = 0;
	str = ft_strjoin(str, "=");
	unset = ft_calloc(sizeof(char *), count(shell->env) + 1);
	if (!unset)
		return ;
	while (shell->env[++i])
	{
		if (ft_strncmp(shell->env[i], str, ft_strlen(str)))
			unset[j++] = ft_strdup(shell->env[i]);
	}
	if (j == i)
	{
		free_pointer(unset);
		free(str);
		return ;
	}
	free_pointer(shell->env);
	free(str);
	shell->env = unset;
}
