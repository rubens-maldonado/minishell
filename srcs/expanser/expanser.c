/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:31:07 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/29 20:57:38 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expanser.h"

void	print_list(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->list[i])
	{
		printf("%s\n", shell->list[i]);
		i++;
	}
}

void	set_list(t_minishell *shell)
{
	int		i;
	char	**list;
	char	*res;

	i = 1;
	res = ft_strdup("");
	list = ft_split(shell->env[0], '=');
	res = ft_strjoin(res, list[0]);
	free_pointer(list);
	while (shell->env[i])
	{
		list = ft_split(shell->env[i], '=');
		res = ft_strjoin(res, "\n");
		res = ft_strjoin(res, list[0]);
		free_pointer(list);
		i++;
	}
	shell->list = ft_split(res, '\n');
	free(res);
}

int	expanser(t_token *tokens, t_minishell *shell, int pos)
{
	char	*tmp;

	tmp = NULL;
	if (tokens[pos].type == 7)
	{
		set_list(shell);
		tmp = select_option(tokens[pos].value);
		tokens[pos].value = find_path(tmp, shell);
		free(tmp);
		free_pointer(shell->list);
	}
	else if (tokens[pos].value)
	{
		tmp = select_option(tokens[pos].value);
		tokens[pos].value = ft_strdup(tmp);
		free(tmp);
	}
	if (!tokens[pos].value)
		return (0);
	return (1);
}
