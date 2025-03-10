/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:31:07 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/24 22:09:28 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expanser.h"

int	count_npath(char *str, int i)
{
	int	k;

	k = 0;
	while (str[i] && str[i] != '$')
	{
		k++;
		i++;
	}
	return (k);
}

int	count_path(char	*str, int i)
{
	int	k;

	k = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			k++;
		else if (str[i] == '?')
		{
			k++;
			break ;
		}
		else
			break ;
		i++;
	}
	return (k);
}

char	*find_path(char *str, t_minishell *shell)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			path = expanse_path(str, path, &i, shell);
			if (!str[i] && !path)
				return (NULL);
		}
		else if (str[i])
			path = expanse_str(str, path, &i);
	}
	return (path);
}

int	check_path(char *str, t_minishell *shell)
{
	int	len_str;
	int	i;

	len_str = ft_strlen(str);
	i = 0;
	if (str[0] == '?')
		return (1);
	while (shell->env[i])
	{
		if (!ft_strcmp(str, shell->list[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*get_path(char *str, t_minishell *shell)
{
	int	len_str;
	int	i;

	len_str = ft_strlen(str);
	i = 0;
	if (str[0] == '?')
		return (ft_itoa(g_exit_status));
	while (shell->env[i])
	{
		if (!ft_strcmp(str, shell->list[i]))
			return (ft_strdup(shell->env[i] + len_str + 1));
		i++;
	}
	return (NULL);
}
