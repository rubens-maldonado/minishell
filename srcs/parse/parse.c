/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:18:30 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 10:32:24 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "minishell.h"
#include "expanser.h"
#include "commands.h"

void	start_parse(t_token *tokens, int i, t_minishell *shell)
{
	int	c;

	c = 0;
	shell->n_comm = 1;
	if (i == 0)
		return ;
	while (c < i)
	{
		if (tokens[c].type == PIPE)
			shell->n_comm++;
		c++;
	}
	join_tokens(tokens, i, shell);
}

char	*split_pipes(t_token *tokens, int size, t_minishell *shell)
{
	char	*res;

	if (!expanser(tokens, shell, shell->c))
		return (NULL);
	res = ft_strdup(tokens[shell->c].value);
	shell->c++;
	while (tokens[shell->c].type != PIPE && shell->c < size)
	{
		if (tokens[shell->c].value && !expanser(tokens, shell, shell->c))
			shell->c++;
		else
		{
			res = ft_strjoin(res, "\a");
			res = ft_strjoin(res, tokens[shell->c].value);
			shell->c++;
		}
	}
	return (res);
}

void	join_tokens(t_token *tokens, int size, t_minishell *shell)
{
	int		cmds;
	char	**res;

	cmds = 0;
	res = ft_calloc(sizeof(char *), (shell->n_comm + 1));
	shell->c = 0;
	while (cmds < shell->n_comm)
	{
		res[cmds] = split_pipes(tokens, size, shell);
		if (res[cmds] == NULL)
		{
			free_tokens2(tokens);
			free_pointer(res);
			return ;
		}
		cmds++;
	}
	res[cmds] = NULL;
	split_commands(res, shell);
	free_tokens2(tokens);
	free_pointer(res);
}
