/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:46 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/25 13:59:39 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

size_t	count_var(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

void	print_error(char *str)
{
	printf("Minishell: %s: command not found\n", str);
	exit(0);
}

size_t	count_env(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
		i++;
	return (i);
}
