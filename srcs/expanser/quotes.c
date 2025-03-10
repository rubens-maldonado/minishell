/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:41:11 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/29 21:00:49 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expanser.h"

int	count_quotes(char *args)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (args[++i])
	{
		if (args[i] == '"')
			k++;
	}
	return (k);
}

int	count_src(char *args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	verify_simple_quotes(char *args)
{
	if (args[0] == '\'')
		return (1);
	return (0);
}

char	*remove_quotes(char *args)
{
	int		i;
	int		j;
	int		q;
	char	*res;

	i = -1;
	j = 0;
	q = count_quotes(args);
	res = ft_calloc(sizeof(char), (count_src(args) - q + 1));
	while (args[++i])
	{
		if (args[i] == '\"')
			continue ;
		else
		{
			res[j] = args[i];
			j++;
		}
	}
	free(args);
	return (res);
}
