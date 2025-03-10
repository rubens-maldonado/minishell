/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:58:31 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/24 22:09:48 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expanser.h"

char	*expanse_str(char *str, char *path, int *i)
{
	int		count;
	int		k;
	char	*var;

	k = *i;
	count = count_npath(str, k);
	var = ft_substr(str, k, count);
	if (!path)
		path = ft_strdup(var);
	else
		path = ft_strjoin(path, var);
	*i = *i + count;
	free(var);
	return (path);
}

char	*expanse_path(char *str, char *path, int *i, t_minishell *shell)
{
	int		count;
	char	*var;
	char	*tmp_var;

	tmp_var = NULL;
	count = count_path(str, *i + 1);
	var = ft_substr(str, *i + 1, count);
	if (!path)
	{
		if (check_path(var, shell))
			path = get_path(var, shell);
	}
	else
	{
		if (check_path(var, shell))
		{
			tmp_var = get_path(var, shell);
			path = ft_strjoin(path, tmp_var);
			free(tmp_var);
		}
	}
	free(var);
	*i = *i + count + 1;
	return (path);
}
