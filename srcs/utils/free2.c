/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:28:53 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/24 22:10:08 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expanser.h"

void	free_alltwo(t_minishell *shell, char *str, char *str2)
{
	free_pointer(shell->list);
	free_pointer(shell->env);
	free(str);
	free(str2);
}

void	free_tokens(t_token *tokens, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tokens[i].value);
		i++;
	}
}

void	free_tokens2(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].value)
	{
		free(tokens[i].value);
		i++;
	}
	free(tokens);
}

void	free_all(t_minishell *shell, char *str, char *str2)
{
	free_pointer(shell->env);
	free(str);
	free(str2);
}
