/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:14:42 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/22 11:27:16 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*filling_msg(char *str)
{
	char	*msg;
	int		i;

	msg = malloc(sizeof(char) * count_var(str) + 1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0)
		{
			if (str[i] == '_')
				msg[i] = str[i];
			else
				return (NULL);
		}
		msg[i] = str[i];
		i++;
	}
	if (str[i] != '=')
	{
		free_str(str, msg);
		return (NULL);
	}
	msg[i] = '\0';
	free(str);
	return (msg);
}
