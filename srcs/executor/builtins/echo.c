/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:49:36 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/25 19:02:01 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	echo_n(int *flag, int *i, char **args)
{
	int	j;

	j = 0;
	*i = 1;
	while (ft_strnstr(args[*i], "-n", ft_strlen(args[*i])))
	{
		j = 1;
		while (args[*i][j])
		{
			if (!ft_strchr("n", args[*i][j]))
				break ;
			j++;
		}
		if (!ft_strchr("n", args[*i][j]))
			break ;
		*i = *i + 1;
		*flag = 1;
		if (args[*i] == 0)
			return (1);
	}
	return (0);
}

void	print(char *res, int flag)
{
	if (flag == 0)
		printf("%s\n", res);
	else
		printf("%s", res);
	free(res);
	g_exit_status = 0;
}

void	echo(char **args, int size)
{
	char	*message;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (size < 2 || !args[1])
	{
		printf("\n");
		return ;
	}
	echo_n(&flag, &i, args);
	message = ft_strdup(args[i]);
	while (++i < size)
	{
		message = ft_strjoin(message, " ");
		message = ft_strjoin(message, args[i]);
	}
	print(message, flag);
}
