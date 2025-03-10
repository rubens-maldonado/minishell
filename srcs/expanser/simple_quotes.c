/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:44:56 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/30 09:38:05 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expanser.h"

int	count_simple(char *args)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (args[++i])
	{
		if (args[i] == '\'')
			k++;
	}
	return (k);
}

char	*remove_simple(char *args)
{
	int		i;
	int		j;
	int		q;
	char	*res;

	i = -1;
	j = 0;
	q = count_simple(args);
	res = ft_calloc(sizeof(char), (count_src(args) - q + 1));
	while (args[++i])
	{
		if (args[i] == '\'')
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

char	*select_option(char *args)
{
	if (verify_simple_quotes(args))
		return (remove_simple(args));
	else
		return (remove_quotes(args));
}
